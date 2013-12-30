
#include "Watch.h"

#include "Board.h"
#include "API.h"
#include "mmi_frame.h"
#include "mmi_show.h"
#include "Button.h"
#include "Power.h"
#include "GDI.h"
#include "Files.h"
#include "Monitor.h"
#include "Function.h"

GLOBAL_INFO g_Info;
GLOBAL_SETTING g_Setting;
GLOBAL_TRAINING g_Training;
GLOBAL_RECORD g_Record;
GLOBAL_STATUS g_Status;
GLOBAL_TEMP  g_Temp;
GLOBAL_GPS_LOCATION  g_GPSLocation;
GLOBAL_VR_LOCATION g_VirtualRace;
GLOBAL_WORKOUT g_pWorkout[WORKOUT_SIZE];
extern SHOW_CONTENT g_pShowContent[30];
extern GLOBAL_STORAGE_INFO g_Storage;

unsigned int g_pRamBuf[RAMBUF_SIZE/4];		// 20480B, 20KB

int CheckCleanBoot()
{

	if( File_Read( "g_Storage", (unsigned char *)&g_Storage, 0, sizeof(g_Storage) ) != FILE_SUCCESS || g_Storage.ID != FILE_ID ) 
		return 1;

	if( File_Read("g_Setting", (unsigned char *)&g_Setting, 0, sizeof(g_Setting)) != FILE_SUCCESS || !g_Setting.Mode || g_Setting.InitialSetup ) 
		return 1;

	if( File_Read("g_Info", (unsigned char *)&g_Info, 0, sizeof(g_Info)) != FILE_SUCCESS ) 
		return 1;

	if( File_Read("g_Training", (unsigned char *)&g_Training, 0, sizeof(g_Training)) != FILE_SUCCESS ) 
		return 1;

	if( File_Read("g_Show", (unsigned char *)&g_pShowContent, 0, sizeof(g_pShowContent)) != FILE_SUCCESS ) 
		return 1;

	return 0;
}

void LoadFileDefault( void )
{
	int i;
	unsigned char Addr[6];

	API_BT_SPP_Init();
	API_mkfs();

	g_Storage.ID = FILE_ID;
	g_Storage.SerialNumber = 0;
	g_Storage.GPSNumber = 0;
	File_Write( "g_Storage", (unsigned char *)&g_Storage, sizeof(g_Storage) );

	g_Training.TimeAlertTime = 300;		//300 second
	g_Training.RunAlertTime = 300;		//300 second
	g_Training.WalkAlertTime = 60;		//60 second
	g_Training.DistanceAlertValue = 3000;
	g_Training.ColorieAlertValue = 3000;
	g_Training.HRAlertValue = 150;	
	g_Training.Reps = 3;
	g_Training.Age = 30;
	g_Training.Weight = 70;
	g_Training.Weight2 = 154;
	g_Training.Height = 175;
	g_Training.Height2 = 69;
	g_Training.IntervalTime = 60;
	g_Training.IntervalDistance = 200;
	g_Training.RestTime = 60;
	g_Training.RestDistance = 200;
	File_Write("g_Training", (unsigned char *)&g_Training, sizeof(g_Training));

	for( i = 0; i < 5; i++ )
	{
		g_pShowContent[0+i*4].Code[0] = CODE_TIME;
		g_pShowContent[0+i*4].Code[1] = CODE_NOW;
		g_pShowContent[0+i*4].Code[2] = CODE_TIME+CODE_LAP;
		g_pShowContent[0+i*4].Code[3] = CODE_TIME+CODE_LAST_LAP;
		g_pShowContent[0+i*4].Length = 3;
		
		g_pShowContent[1+i*4].Code[0] = CODE_TIME;
		g_pShowContent[1+i*4].Code[1] = CODE_SPEED;
		g_pShowContent[1+i*4].Code[2] = CODE_DISTANCE;
		g_pShowContent[1+i*4].Code[3] = CODE_DISTANCE+CODE_LAP;
		g_pShowContent[1+i*4].Length = 3;
			
		g_pShowContent[2+i*4].Code[0] = CODE_TIME;
		g_pShowContent[2+i*4].Code[1] = CODE_CADENCE;
		g_pShowContent[2+i*4].Code[2] = CODE_STEPS;
		g_pShowContent[2+i*4].Code[3] = CODE_STEPS+CODE_LAST_LAP;
		g_pShowContent[2+i*4].Length = 3;
			
		g_pShowContent[3+i*4].Code[0] = CODE_TIME;
		g_pShowContent[3+i*4].Code[1] = CODE_HEART_RATE;
		g_pShowContent[3+i*4].Code[2] = CODE_LAPS;
		g_pShowContent[3+i*4].Code[3] = CODE_ELEVATION;
		g_pShowContent[3+i*4].Length = 3;
	}
	File_Write("g_Show", (unsigned char *)&g_pShowContent, sizeof(g_pShowContent));

	g_Setting.Mode = MODE_RUN;
	g_Setting.Language = 0;				//WWE
	g_Setting.KeyTone = 1;				//ON
	g_Setting.MessageTone = 1;			//ON
	g_Setting.Vibration = 1;		//ON
	g_Setting.BacklightTimeout = 15;		//15 Sec;
	g_Setting.BacklightLevel = 1;
	g_Setting.Orientation = 0;			//North Up
	g_Setting.UserLocation = 1;			//Show
	g_Setting.ShowMap = 1;				//Yes
	g_Setting.ANTZoneMax = 200;
	g_Setting.ANTZoneRest = 70;
	g_Setting.ANTBikeWheel = 109;
	g_Setting.ANTFootPodRunDistance = 40;
	g_Setting.ANTFootPodSwimDistance = 20;
	g_Setting.ANTFootPodOtherDistance = 30;
	g_Setting.GSensorRunDistance = 40;
	g_Setting.GSensorSwimDistance = 20;
	g_Setting.GSensorOtherDistance = 30;
	g_Setting.GCountValue = 1000;
	g_Setting.GPSAutoUpdate = 1;
	g_Setting.TimeZone = (8<<16)+00;	//UTC+8:00
	g_Setting.TimeZone2 = 0;			//UTC+0:00
	g_Setting.InitialSetup = 0;
	g_Setting.PauseTime	= 1800;
	g_Setting.LapAtTime = 1800;
	g_Setting.LapAtDistance = 3000;
	g_Setting.BTSPPTone = 2000;
	g_Setting.BTSPPVibration = 3000;
	g_Setting.MetronomeRing = 500;
	g_Setting.MetronomeTime = 1000;
	File_Write("g_Setting", (unsigned char *)&g_Setting, sizeof(g_Setting));

	for( i = 0; i < 100; i++ )
	{
		if( API_BT_SPP_IS_READY() )
			break;
		API_Delay(50);
	}
	API_BT_GET_BT_ADDRESS( Addr );
	printf("%d,%d,%d,%d,%d,%d\r\n", Addr[5], Addr[4], Addr[3], Addr[2], Addr[1], Addr[0] );

	g_Info.BTAddress1 = (Addr[3]<<24) | (Addr[2]<<16) | (Addr[1]<<8) | (Addr[0]<<0);
	g_Info.BTAddress2 = (Addr[5]<<8) | (Addr[4]<<0);
	for( i = 0; i < 4; i++ )
		g_Info.TotalTick[i] = 0;
	File_Write("g_Info", (unsigned char *)&g_Info, sizeof(g_Info));

	API_BT_SPP_DeInit();

}

void Initial( void )
{
	Button_Clear();
	if( CheckCleanBoot() ) 
	{
		LoadFileDefault();
	}
	else
		API_Delay(600);
		

	if( g_Setting.GPSEnable )
	{
		API_GPS_Start();
		g_Status.GPSFixState = 2;
	}
	else
		g_Status.GPSFixState = 0;

	if( g_Setting.ANTHeartRate )
	{
		HRM_Init();
		g_Status.ANTHRState = 1;
	}
	else
		API_Delay(50);
	
	if( g_Setting.ANTFootPod && g_Setting.Mode != MODE_BIKE )
	{
		SDM_Init();
		g_Status.ANTFootPodState = 1;
	}
	else
		API_Delay(50);

	if( g_Setting.ANTBikeSensor && g_Setting.Mode == MODE_BIKE )
	{
		BYCYCLE_Init();
		g_Status.ANTBikeState = 1;
	}
	else
		API_Delay(50);

	if( g_Setting.GSensorOn )
	{
		API_eCompassInit();
		API_Set_Update_rate(100);
		API_Clear_Counter_G();
	}
	else
		API_Delay(50);

	if( g_Setting.BLEFinder || g_Setting.BLEHR )
	{
		if( g_Setting.BLEFinder )
		{
			API_BT_BLE_Init( API_BT_BLE_MASTER_FINDER );
   			printf("API_BT_BLE_Init   API_BT_BLE_MASTER_FINDER\r\n");
		}
		if( g_Setting.BLEHR )
		{
			API_BT_BLE_Init( API_BT_BLE_MASTER_HEARTRATE );
	   		printf("API_BT_BLE_Init  API_BT_BLE_MASTER_HEARTRATE\r\n");
		}

		API_Delay(300);

		if( g_Setting.BLEFinder )
			BLEInitial( 1 );

		if( g_Setting.BLEHR )
			BLEInitial( 2 );	
	}
	else
		API_Delay(1000);


	if( g_Setting.GPSAutoUpdate )
		g_Status.GPSTimeUpdate = 1;

	if( g_Setting.BluetoothSPP )
		BT_SPP_Init( );
	else
		API_Delay(100);

}


void MMIFrame( char status )
{
	int Frame;
	int NextFrame;
	int ShowInfo[5] = {FRAME_SHOW+0, FRAME_SHOW+4, FRAME_SHOW+8, FRAME_SHOW+12, FRAME_SHOW+16};

	// Initial MMI
	API_LCD_Init();
	API_LCD_Backlight( 1 );
	g_Status.LightState = 1;
	PaintOpenScreen();
	API_ChargeInit();
	API_VibrationInit();
	API_BuzzerInit();
	API_Delay(50);
	Initial();
	BacklightEvent();

#if GTIW10_DO_CHARGING
	if( status )
	{
		ChargingFrame();
		API_PowerOff();
		API_Delay(60000);
	}
#endif

	NextFrame = FRAME_CLOCK;
	while(1)
	{
		Frame = NextFrame;
		if( Frame <= FRAME_MENU_TABLE_MAX )
		{
			NextFrame = fMenuTable( Frame );
			if( NextFrame == FRAME_SHOW_NEXT )
				NextFrame = FRAME_SHOW_ENTRY;
		}
		else if( Frame <= FRAME_MENU_PULLDOWN_MAX )
		{
			NextFrame = fPDMenuTable( Frame - FRAME_MENU_PULLDOWN );
		}
		else if( Frame <= FRAME_MENU_MIX_MAX )
		{
			NextFrame = fMixTable( Frame - FRAME_MENU_MIX );
		}
		else if( Frame <= FRAME_SET_SHOW_MAX )
		{
			NextFrame = fSetShowTable( Frame - FRAME_SET_SHOW );
		}
		else if( Frame <= FRAME_SHOW_MAX )
		{
			NextFrame = fShowTable( Frame - FRAME_SHOW );
			ShowInfo[(Frame - FRAME_SHOW)/4] = Frame;
			if( NextFrame == FRAME_SHOW_NEXT )
				NextFrame = FRAME_MENU_GPS_LOCATION_NAVIGATE;
		}
		else if( Frame >= FRAME_MENU_HISTORY_TOTAL && Frame <= FRAME_MENU_HISTORY_TOTAL+4 )
		{
			NextFrame = fLapTotal( Frame - FRAME_MENU_HISTORY_TOTAL );
		}
		else
		{			
			switch( Frame )
			{
			case FRAME_MENU_SETTING_ABOUT:
				NextFrame = fAbout();
				break;
			case FRAME_CLOCK:
				NextFrame = fClock();
				if( NextFrame == FRAME_SHOW_NEXT )
					NextFrame = 0;
				break;
			case FRAME_SHOW_ENTRY:
				NextFrame = ShowInfo[g_Setting.Mode-1];
				break;
			case FRAME_MENU_HISTORY_ACTIVITIES:
				NextFrame = fLapList( );
				break;
			case FRAME_MENU_HISTORY_ACTIVITIES_MORE:
				NextFrame = fLapMore( );
				break;
			case FRAME_MENU_HISTORY_ACTIVITIES_SHOW:
				NextFrame = fLapShow2( );
				break;
			case FRAME_MENU_HISTORY_ACTIVITIES_MAP:
				NextFrame = fLapMap2( );
				break;
			case FRAME_MENU_HISTORY_MEMORY:
				NextFrame = fMemoryDetail();
				break;
			case FRAME_ANTHR:
				NextFrame = fANTConnect( 0 );
				break;
			case FRAME_ANTFOOTPAD:
				NextFrame = fANTConnect( 1 );
				break;
			case FRAME_ANTBIKESPD:
				NextFrame = fANTConnect( 2 );
				break;
			case FRAME_ANTBIKEPOWER:
				NextFrame = fANTConnect( 3 );
				break;
			case FRAME_BLE_FDR_MENU:
				NextFrame = fBLEMenu( 1 );
				break; 
			case FRAME_BLE_FDR_LIST:
				NextFrame = fBLEList( 1 );
				break; 
			case FRAME_BLE_FDR_LIST_MORE:
				NextFrame = fBLEListMore( 1 );
				break;
			case FRAME_BLE_FDR_SCAN:
				NextFrame = fBLEScan( 1 );
				break;
			case FRAME_BLE_HR_MENU:
				NextFrame = fBLEMenu( 2 );
				break; 
			case FRAME_BLE_HR_LIST:
				NextFrame = fBLEList( 2 );
				break; 
			case FRAME_BLE_HR_LIST_MORE:
				NextFrame = fBLEListMore( 2 );
				break;
			case FRAME_BLE_HR_SCAN:
				NextFrame = fBLEScan( 2 );
				break;
			case FRAME_MENU_CALIB_ANT_FOOTPOD:
				NextFrame = fCalibartion( 27 );
				break;
			case FRAME_MENU_CALIB_ANT_BIKE:
				NextFrame = fCalibartion( 28 );
				break;
			case FRAME_MENU_CALIB_GSENSOR:
				NextFrame = fCalibartion( 29 );
				break;
			case FRAME_COMPASS:
				NextFrame = fCompass();
				break;
			case FRAME_COMPASS_CALIBRATION:
				NextFrame = fCompassCalib();
				break;
			case FRAME_TEMPERATURE:
				NextFrame = fTemperature();
				break;
			case FRAME_PRESSURE:
				NextFrame = fPressure();
				break;
			case FRAME_MENU_GPS_SATELLITES_CN:
				NextFrame = fGpsStatusCN();
				break;
			case FRAME_MENU_GPS_SATELLITES_SKY:
				NextFrame = fGpsStatusSat();
				break;
			case FRAME_MENU_SPP_LOG_TRANSGERRING:
				NextFrame = fSppLogStatus();
				break;
			case FRAME_MENU_GPS_LOCATION_MANAGER:
				NextFrame = fGPSLocation( );
				break;
			case FRAME_MENU_GPS_LOCATION_MORE:
				NextFrame = fGPSLocationMore( );
				break;
			case FRAME_MENU_GPS_LOCATION_MODIFY:
				NextFrame = fGPSLocationModify( );
				break;
			case FRAME_MENU_GPS_LOCATION_NAVIGATE:
				NextFrame = fGPSNavigate( );
				if( NextFrame == FRAME_SHOW_NEXT )
					NextFrame = FRAME_MENU_WORKOUT_RUN;
				break;
			case FRAME_MENU_WORKOUT_RUN:
				NextFrame = fWorkoutRun( );
				if( NextFrame == FRAME_SHOW_NEXT )
					NextFrame = FRAME_MENU_COURSE_RUN;
				break;
			case FRAME_MENU_WORKOUT:
				NextFrame = fWorkoutList( );
				break;
			case FRAME_MENU_WORKOUT_MORE:
				NextFrame = fWorkoutMore( );
				break;
			case FRAME_MENU_WORKOUT_PAGE:
				NextFrame = fWorkoutPage( );
				break;
			case FRAME_MENU_WORKOUT_PAGE_MODIFY:
				NextFrame = fWorkoutPageModify( );
				break;
			case FRAME_MENU_COURSE_RUN:
				NextFrame = fCourseRun( );
				if( NextFrame == FRAME_SHOW_NEXT )
					NextFrame = FRAME_MENU_VR_RUN;
				break;
			case FRAME_MENU_COURSE:
				NextFrame = fCourseList( );
				break;
			case FRAME_MENU_COURSE_MORE:
				NextFrame = fCourseMore( );
				break;
			case FRAME_MENU_COURSE_ADD:
				NextFrame = fCourseAdd( );
				break;
			case FRAME_MENU_COURSE_MAP:
				NextFrame = fCourseMap( );
				break;
			case FRAME_MENU_VR_RUN:
				NextFrame = fVirtualRaceRun( );
				if( NextFrame == FRAME_SHOW_NEXT )
					NextFrame = FRAME_CLOCK;
				break;
			case FRAME_MENU_VR_MANAGER:
				NextFrame = fVirtualRace( );
				break;
			case FRAME_MENU_VR_MORE:
				NextFrame = fVirtualRaceMore( );
				break;
			case FRAME_MENU_VR_MODIFY:
				NextFrame = fVirtualRaceModify( );
				break;
			default:
				NextFrame = FRAME_CLOCK;
				break;		
			}
		}
	}
}


