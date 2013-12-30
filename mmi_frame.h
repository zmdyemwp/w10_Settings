#ifndef __MMI_FRAME_H
#define __MMI_FRAME_H

//#define  FILE_FORMAT_OLD						1


// Frame Define
#define FRAME_MASK										0x0fff

// Menu 1st
#define FRAME_MENU_MASK									0x01ff

#define FRAME_MENU_TABLE								0x0000		//int fMenuTable(unsigned int Index);
#define FRAME_MENU_TABLE_MAX							0x01ff

#define FRAME_MENU_PULLDOWN								0x0200		//int fPDMenuTable(unsigned int Index);
#define FRAME_MENU_PULLDOWN_MAX							0x03ff

#define FRAME_MENU_MIX									0x0400		//int fMixTable(unsigned int Index);
#define FRAME_MENU_MIX_MAX								0x05ff

#define FRAME_SET_SHOW									0x0600		//int fSetShowTable(unsigned int Index);
#define FRAME_SET_SHOW_MAX								0x07ff

#define FRAME_SHOW										0x0800		//int fShowTable(unsigned int Index);
#define FRAME_SHOW_MAX									0x09ff
#define FRAME_SHOW_ENTRY								0x2110		//Call fShowTable, accroding Mode
#define FRAME_SHOW_NEXT									0x2113		//Return this Value to Next frame
#define FRAME_CLOCK										0x2300

#define FRAME_MENU_CALIB_ANT_FOOTPOD					0x1461
#define FRAME_MENU_CALIB_ANT_BIKE						0x1462
#define FRAME_MENU_CALIB_GSENSOR						0x1463

#define FRAME_MENU_SETTING_ABOUT						0x1440
#define FRAME_MENU_HISTORY_ACTIVITIES					0x1110
#define FRAME_MENU_HISTORY_ACTIVITIES_MORE				0x1142
#define FRAME_MENU_HISTORY_ACTIVITIES_SHOW				0x1143
#define FRAME_MENU_HISTORY_ACTIVITIES_MAP				0x1144
#define FRAME_MENU_HISTORY_TOTAL						0x1120
#define FRAME_MENU_HISTORY_MEMORY						0x1150

#define	FRAME_MENU_GPS_SATELLITES_CN					0x1201
#define	FRAME_MENU_GPS_SATELLITES_SKY					0x1202
#define	FRAME_MENU_SPP_LOG_TRANSGERRING					0x1203
#define	FRAME_MENU_GPS_LOCATION_MANAGER					0x1221
#define	FRAME_MENU_GPS_LOCATION_MORE					0x1222
#define	FRAME_MENU_GPS_LOCATION_MODIFY					0x1224
#define	FRAME_MENU_GPS_LOCATION_NAVIGATE				0x122f

#define	FRAME_MENU_WORKOUT								0x1301
#define	FRAME_MENU_WORKOUT_MORE							0x1302
#define	FRAME_MENU_WORKOUT_PAGE							0x1303
#define	FRAME_MENU_WORKOUT_PAGE_MODIFY					0x1304
#define	FRAME_MENU_WORKOUT_RUN							0x130f

#define	FRAME_MENU_VR_MANAGER							0x1321
#define	FRAME_MENU_VR_MORE								0x1322
#define	FRAME_MENU_VR_MODIFY							0x1324
#define	FRAME_MENU_VR_RUN								0x132f

#define	FRAME_MENU_COURSE								0x1341
#define	FRAME_MENU_COURSE_MORE							0x1342
#define	FRAME_MENU_COURSE_ADD							0x1343
#define	FRAME_MENU_COURSE_MAP							0x1344
#define	FRAME_MENU_COURSE_RUN							0x134f

#define FRAME_BLE_FDR_MENU								0x1400
#define FRAME_BLE_FDR_LIST								0x1401
#define FRAME_BLE_FDR_LIST_MORE							0x1402
#define FRAME_BLE_FDR_SCAN								0x140f

#define FRAME_BLE_HR_MENU								0x1410
#define FRAME_BLE_HR_LIST								0x1411
#define FRAME_BLE_HR_LIST_MORE							0x1412
#define FRAME_BLE_HR_SCAN								0x141f

#define FRAME_CHANGE_SPORT								0x4100
#define FRAME_LIGHT										0x4200
#define FRAME_COMPASS									0x4300
#define FRAME_COMPASS_CALIBRATION						0x4310
#define FRAME_TEMPERATURE								0x4400
#define FRAME_PRESSURE									0x4410
#define FRAME_ANTHR										0x4500
#define FRAME_ANTFOOTPAD								0x4501
#define FRAME_ANTBIKESPD								0x4502
#define FRAME_ANTBIKEPOWER								0x4503


#define NOTIFY_STOPWATCH								(1<<0)
#define NOTIFY_LAP										(1<<1)
#define NOTIFY_RESET									(1<<2)
#define NOTIFY_ALERT									(1<<3)
#define NOTIFY_ALARM									(1<<5)
#define NOTIFY_WORKOUT									(1<<16)
#define NOTIFY_VR_WIN									(1<<17)
#define NOTIFY_VR_LOST									(1<<18)
#define NOTIFY_MESSAGE									(1<<10)
#define NOTIFY_BTSPP_CONNECT							(1<<11)
#define NOTIFY_BLEFINDER								(1<<12)
#define NOTIFY_DEVICEMSG								(1<<30)
#define NOTIFY_DEVICEMSG_PRESS							(1<<29)


#define FUNCTION_LIST									0x5000
#define FUNCTION_GPS_ENABLE								FUNCTION_LIST+0x0100
#define FUNCTION_GPS_NAVIGATION_STOP					FUNCTION_LIST+0x0103
#define FUNCTION_GPS_BUTTON_SAVE						FUNCTION_LIST+0x0106
#define FUNCTION_GPS_BUTTON_DELETE						FUNCTION_LIST+0x0107
#define FUNCTION_GPS_BUTTON_GOTO						FUNCTION_LIST+0x0108
#define FUNCTION_GPS_BUTTON_ADD							FUNCTION_LIST+0x0101
#define FUNCTION_GPS_BUTTON_DELETEALL					FUNCTION_LIST+0x0102

#define FUNCTION_LAP_BUTTON_DELETE						FUNCTION_LIST+0x0117
#define FUNCTION_LAP_BUTTON_DELETEALL					FUNCTION_LIST+0x0112

#define FUNCTION_GET_RTCTIME							FUNCTION_LIST+0x0120
#define FUNCTION_SET_RTCTIME							FUNCTION_LIST+0x0121
#define FUNCTION_ANT_HR_ENABLE							FUNCTION_LIST+0x0210
#define FUNCTION_ANT_FOOTPAD_ENABLE						FUNCTION_LIST+0x0220
#define FUNCTION_ANT_BIKE_SPD_CAD_ENABLE				FUNCTION_LIST+0x0230
#define FUNCTION_ANT_BIKE_POWER							FUNCTION_LIST+0x0240
#define FUNCTION_GSENSOR_ENABLE							FUNCTION_LIST+0x0300
#define FUNCTION_GSENSOR_SETCOUNT						FUNCTION_LIST+0x0301

#define FUNCTION_BLE_HR_ENABLE							FUNCTION_LIST+0x0410
#define FUNCTION_BLE_FINDER_ENABLE						FUNCTION_LIST+0x0400
#define FUNCTION_BLE_DELETE								FUNCTION_LIST+0x0407
#define FUNCTION_BLE_CONNECT							FUNCTION_LIST+0x0408
#define FUNCTION_BLE_DELETEALL							FUNCTION_LIST+0x0402

#define FUNCTION_BT_SPP_INIT							FUNCTION_LIST+0x0431

#define FUNCTION_WEIGHT_CONVERSION						FUNCTION_LIST+0x0900
#define FUNCTION_CALIB_DEFAULT							FUNCTION_LIST+0x0911
#define FUNCTION_TEMP_CLEAR								FUNCTION_LIST+0x0912
#define FUNCTION_TEMP_METRONOME_GET						FUNCTION_LIST+0x0918
#define FUNCTION_TEMP_METRONOME_SET						FUNCTION_LIST+0x0919
#define FUNCTION_ALARM1_READ							FUNCTION_LIST+0x0921
#define FUNCTION_ALARM2_READ							FUNCTION_LIST+0x0922
#define FUNCTION_ALARM3_READ							FUNCTION_LIST+0x0923
#define FUNCTION_ALARM4_READ							FUNCTION_LIST+0x0924
#define FUNCTION_ALARM1_SAVE							FUNCTION_LIST+0x0928
#define FUNCTION_ALARM2_SAVE							FUNCTION_LIST+0x0929
#define FUNCTION_ALARM3_SAVE							FUNCTION_LIST+0x092A
#define FUNCTION_ALARM4_SAVE							FUNCTION_LIST+0x092B

#define FUNCTION_FLASH_FORMAT							FUNCTION_LIST+0x0A00
#define FUNCTION_BACKLIGHT								FUNCTION_LIST+0x0A50

#define FUNCTION_WORKOUT_BUTTON_STATUS					FUNCTION_LIST+0x050B
#define FUNCTION_WORKOUT_BUTTON_SAVE					FUNCTION_LIST+0x0506
#define FUNCTION_WORKOUT_BUTTON_DELETE					FUNCTION_LIST+0x0507
#define FUNCTION_WORKOUT_BUTTON_DO						FUNCTION_LIST+0x0508
#define FUNCTION_WORKOUT_BUTTON_INTERVALDO				FUNCTION_LIST+0x0509
#define FUNCTION_WORKOUT_BUTTON_ADD						FUNCTION_LIST+0x0501
#define FUNCTION_WORKOUT_BUTTON_DELETEALL				FUNCTION_LIST+0x0502

#define FUNCTION_VR_BUTTON_SAVE							FUNCTION_LIST+0x0526
#define FUNCTION_VR_BUTTON_DELETE						FUNCTION_LIST+0x0527
#define FUNCTION_VR_BUTTON_DO							FUNCTION_LIST+0x0528
#define FUNCTION_VR_BUTTON_ADD							FUNCTION_LIST+0x0521
#define FUNCTION_VR_BUTTON_DELETEALL					FUNCTION_LIST+0x0522

#define FUNCTION_COURSE_BUTTON_DELETE					FUNCTION_LIST+0x0517
#define FUNCTION_COURSE_BUTTON_DO						FUNCTION_LIST+0x0518
#define FUNCTION_COURSE_BUTTON_DELETEALL				FUNCTION_LIST+0x0512

#define RAMBUF_SIZE		20480

#define WORKOUT_SIZE	12

#define BLESAVE_SIZE	16

// Sport Mode Define
#define MODE_RUN										0x01
#define MODE_BIKE										0x02
#define MODE_OWSWIM										0x03
#define MODE_POOLSWIM									0x04
#define MODE_OTHER										0x05

#define LAP_MODE_RUN									0x00
#define LAP_MODE_BIKE									0x01
#define LAP_MODE_SWIM									0x02
#define LAP_MODE_OTHER									0x03


#define DEPENDON_NOT									0x08000

#define RECORD_RESET									0
#define RECORD_START									1
#define RECORD_STOP										2


#define AUTOPAUSE_SPEED									0.3  //Km/h

#define M_PI 3.14159265358979323846


typedef	void (*pfn_void_pvoid)(void *);
typedef	void (*pfn_void)( void );
typedef	void (*pfn_void_us_us_pi)( unsigned short, unsigned short, int * );

typedef struct
{
	unsigned int Frame;				// Frame id
	unsigned int Mode;				// Mode: 1:RUN, 2:BIKE, 3:OWSWIM, 4:POOLSWIM, 5:OTHER
	unsigned int Language;			// Language: 0:WWE, 2:CHT, 3:CHS
	unsigned int KeyTone;			// KeyTone: 0:Off, 1:On
	unsigned int MessageTone;		// MessageTone: 0:Off, 1:On
	unsigned int Vibration;			// MessageVibration: 0:Off, 1:On
	unsigned int BacklightTimeout;	// BacklightTimeout: 0:Stays On, other: X seconds
	unsigned int BacklightLevel;	// BackLight brightness: Number 0-Max  0:Off, 1:Middle, 2:High
	unsigned int Orientation;		// Orientation: 0:North Up, 1:Track Up
	unsigned int UserLocation;		// UserLocation: 0:Hide, 1:Show
	unsigned int ShowMap;			// ShowMap: 0:No, 1:Yes
	unsigned int ANTWeight;			// ANT Weight Scale: 0:No, 1:Yes
	unsigned int ANTEquipment;		// ANT Fitness Equipment: 0:No, 1:Yes
	unsigned int RecordData;		// Record Data Points: 0:Smart Recording, 1:Event Recording, 2:No Record
	unsigned int TransferData;		// Data Transfer: 0:No, 1:Yes
	unsigned int PairingData;		// Data PairingData: 0:Off, 1:On
	unsigned int InitialSetup;		// Initial Setup: 0:No, 1:Yes
	unsigned int TimeFormat;		// Time Format: 0:12 Hour, 1:24 Hour
	unsigned int TimeZone;			// Time Zone: 0xABCD  AB:Hour or Hour-32(if > 20), CD:Minutes
	unsigned int TimeSaving;		// DayLight Saving Time: 0:No, 1:Yes
	unsigned int DistanceUnit;		// Distance: 0:Metric, 1:Settatu
	unsigned int ElevationUnit;		// Elevation: 0:Metric, 1:Settatu
	unsigned int WeightUnit;		// Weight/Height: 0:Metric, 1:Settatu
	unsigned int SpeedUnit;			// Pace/Speed: 0:Metric, 1:Settatu
	unsigned int PositionUnit;		// Position: 0:hddd.ddddd, 1:hddd mm.mmm 2:hddd mm ss.s
	unsigned int GPSEnable;			// GPS Enable: 0:No, 1:Yes
	unsigned int AutoLap;			// Auto Lap Trigger: 0:Off, 1:By Time 2:By Distance
	unsigned int LapAtDistance;		// Distance's Lap At: Distance (Meter)
	unsigned int LapAtTime;			// Time's Lap At: Time (second base)
	unsigned int AutoPause;			// Auto Timer Pause: 0:Off, 1:When Stopped 2:Custom Pace
	unsigned int PauseTime;			// Pause When: Time (second base)
	unsigned int AutoScroll;		// Auto Scroll: 0:Off, 1:Slow 2:Meduim 3:Fast
	unsigned int VPEnable;			// Virtual Partner Enable: 0:Off, 1:On
	unsigned int PaceSpeed;			// Pace Speed: 0:Pace, 1:Speed
	unsigned int ANTHeartRate;		// Ant+ Heart Rate Monitor: 0:No, 1:Yes
	unsigned int ANTHRDisplay;		// Ant+ HR Display: 0:Bpm, 1:%
	unsigned int ANTZoneCalc;		// Ant+ Zone calculate: 0:Max, 1:Reserve 2:Custom
	unsigned int ANTZoneMax;		// Ant+ Zone Max: Number: 0:-254
	unsigned int ANTZoneRest;		// Ant+ Zone Resting: Number: 0:-254
	unsigned int ANTFootPod;		// Ant+ Foot Pad: 0:No, 1:Yes
	unsigned int ANTFootPadSource;	// Ant+ Foot Pad Source: 0:GPS, 1:Foot Pad
	unsigned int ANTFootPodRunDistance;// Ant+ Foot Pad Run mode Step Distance: Number 1-300 (cm)
	unsigned int ANTFootPodSwimDistance;// Ant+ Foot Pad Swim mode Step Distance: Number 1-300 (cm)
	unsigned int ANTFootPodOtherDistance;// Ant+ Foot Pad Other mode Step Distance: Number 1-300 (cm)
	unsigned int ANTBikeWeight;		// Ant+ Bike Weight: Number: 0-451 (kg)
	unsigned int ANTBikeOdometer;	// Ant+ Bike Odometer: Number: 0-9999000(meter)
	unsigned int ANTBikeAuto;		// Ant+ Bike Auto/Manual: 0:Auto 1:Manual
	unsigned int ANTBikeWheel;		// Ant+ Bike Wheel Size if Bike is Auto: 1-2000 (cm)
	unsigned int ANTBikeSensor;		// Ant+ Bike Sensor: 0:No, 1:Yes
	unsigned int ANTBikePower;		// Ant+ Power Meter Sensor: 0:No, 1:Yes
	unsigned int GCountValue;		// GCount Value: 9.8-30 (cm/sec2)
	unsigned int GSensorOn;			// GSensor/Compass Sensor: 0:No, 1:Yes
	unsigned int GSensorRunDistance;// GSensor Run Mode Step Distance: Number 1-300 (cm)
	unsigned int GSensorSwimDistance;// GSensor Swim Mode Step Distance: Number 1-300 (cm)
	unsigned int GSensorOtherDistance;// GSensor Other Mode Step Distance: Number 1-300 (cm)
	unsigned int BLEFinder;			// BLE Finder Function: 0:No, 1:Yes
	unsigned int BLEHR;				// BLE Heart Rate Function: 0:No, 1:Yes
	unsigned int TimeZone2;			// Time Zone 2: 0xABCD  AB:Hour or Hour-32(if > 20), CD:Minutes
	unsigned int TimeSaving2;		// DayLight Saving Time 2: 0:No, 1:Yes
	unsigned int GPSAutoUpdate;		// GPS Timer Auto Update: 0:No, 1:Yes
	unsigned int BluetoothSPP;		// Bluetooth SPP Action State: 0:Off, 1:On
	unsigned int BTSPPTone;			// Bluetooth Notify Tone Time: Number <mS>
	unsigned int BTSPPVibration;	// Bluetooth Notify Vibration Time: Number <mS>
	unsigned int BarometerOn;		// Barometer Sensor: 0:No, 1:Yes
	unsigned int Themes;			// Themes: 0:Digital, 1:Indicator
	unsigned int Metronome;			// Metronome State: 0:No, 1:Yes
	unsigned int MetronomeTime;		// Metronome Interval Time: Number (mS)
	unsigned int MetronomeRing;		// Metronome Ring Time: Number (mS)
	unsigned int AlarmOn[4];		// Alarm 1 State: 0:No, 1:Yes
	unsigned int AlarmWeek[4];		// Alarm 1 Week: bit0:SUM, 1:MON, 2:TUE, 3:WED, 4:THU, 5:FRI, 6:SAT
	unsigned int AlarmHour[4];		// Alarm 1 Hour: Number 0 ~ 23
	unsigned int AlarmMin[4];		// Alarm 1 Minute: Number 0 ~ 59
} GLOBAL_SETTING;


typedef struct
{
	unsigned int TimeAlert;			// Time Alert: 0:Off, 1:On
	unsigned int TimeAlertTime;		// Time Alert Time: Time (seconds base)
	unsigned int RunAlert;			// Time Alert: 0:Off, 1:On
	unsigned int RunAlertTime;		// Run Alert: Time (seconds base)
	unsigned int WalkAlertTime;		// Walk Alert: Time (seconds base)
	unsigned int DistanceAlert;		// Distance Alert: 0:Off, 1:On
	unsigned int DistanceAlertValue;// Distance Alert Value: Value (Meter)
	unsigned int ColorieAlert;		// Colorie Alert: 0:Off, 1:On
	unsigned int ColorieAlertValue;	// Colorie Alert Value: Value
	unsigned int HRAlert;			// HR Alert: 0:Off, 1:On
	unsigned int HRAlertValue;		// HR Alert Value: Number (Bpm)
	unsigned int IntervalType;		// Training->Interval->Type: 0:Time, 1:Distance
	unsigned int IntervalTime;		// Training->Interval->Time: Time (seconds base)
	unsigned int IntervalDistance;	// Training->Interval->Distance: Distance (Meter)
	unsigned int RestType;			// Training->Interval->Reset Type: 0:Time, 1:Distance
	unsigned int RestTime;			// Training->Interval->Reset Time: Time (seconds base)
	unsigned int RestDistance;		// Training->Interval->ResetDistance: Distance (Meter)
	unsigned int Reps;				// Training->Interval->Reps: Number
	unsigned int WarmUp;			// Warm Up: 1:Enable 0:Disable
	unsigned int CoolDown;			// Cool Down: 1:Enable 0:Disable
	unsigned int Gender;			// Gender: 0:Male 0:Female
	unsigned int Age;				// Age: Number
	unsigned int Weight;			// Weight: Number (kg)
	unsigned int Height;			// Height: Number (cm)
	unsigned int Weight2;			// Weight: Number (lb)		// 1 kg = 2.20462262 pound(lb)
	unsigned int Height2;			// Height: Number (inch)	// 1 cm = 0.3937 inch
	unsigned int LFAthlete;			// Lifetime Athlete: 0:No, 1:Yes
} GLOBAL_TRAINING;

typedef	struct
{
    double               ShiftX;
    double               ShiftY;
    double               ShiftZ;
    double               MultiX;
    double               MultiY;
    double               MultiZ;
    double               MultiNX;
    double               MultiNY;
    double               MultiNZ;
} COMPASS_CALIB, *P_COMPASS_CALIB;

typedef struct {
	double Lat;
	double Long;
	double High;
} GLOBAL_GPS_LOCATION;

typedef struct {
	unsigned int Distance;
	unsigned int Time;
} GLOBAL_VR_LOCATION;

typedef struct{
	unsigned char Name[32];		//BLE Name
	unsigned char Address[6];	//BLE Addr
	unsigned char Type;			//BLE Type: 1:Finder, 2:Heart Rate
	unsigned int State;			//BLE State: 0:No Used, 1:Disconnect_Addr, 2:Connecting, 3:Connected, 4:Disconnecting, 5:Deleting, 6:ReConnecting
	unsigned int Point;			//Point to GLOBAL_BLE_RUN's Index, be used only in State=2,3,4,6
} BLE_SAVE;

typedef struct{
	unsigned char Name[32];		//BLE Name
	unsigned char Address[6];	//BLE Addr
	unsigned char Type;			//BLE Type: 1:Finder, 2:Heart Rate
	unsigned char id;			//BLE API's Id
	unsigned int State;			//BLE State: 0:No Used, 2:Connecting, 3:Connected, 4:Disconnecting, 5:Deleting, 6:ReConnecting
	unsigned int Point;			//Point to BLE_SAVE's Index
	unsigned int Tick;			//BLE Timeout Tick
	unsigned int ReTry;			//BLE Re Try Count;
} GLOBAL_BLE_RUN;

typedef struct
{
	COMPASS_CALIB CompassCalib;		// Save Compass Calibration Parameter
	unsigned int TotalTick[4];		// Present Total Tick Time for All Mode: Number (Tick) []= 0:MODE_RUN, 1:MODE_BIKE, 2:MODE_SWIM 3:OTHER
	unsigned int BTAddress1;		// Bluetooth Address: A[3],A[2],A[1],A[0]
	unsigned int BTAddress2;		// Bluetooth Address: 0, 0, A[5], A[4]
	BLE_SAVE BLESave[BLESAVE_SIZE];	// BLE Info
} GLOBAL_INFO;

typedef struct
{
	unsigned int SaveStep;			// Save Step: 0:Nodo 1:Write 2:Modify
	unsigned int SaveTick;			// Save Tick if the tick occor, save data: Number (Tick)
	unsigned int Status;			// Record Status: 0:Reset, 1:Start, 2:Stop
	unsigned int StartTick;			// Start Time: Number (Tick)
	unsigned int RunTick;			// already Run Tick: Number (Tick)
	unsigned int LapLastTick;		// Last Lap Tick Time: Number (Tick)
	unsigned int LapAverageTick;	// Average Lap Tick Time: Number (Tick)
	unsigned int LapPreviousTick;	// Previous Lap Tick Time: Number (Tick)
	unsigned int LapCount;			// press Count for user press Lap key: Number (frequency)

	unsigned int NTFStopwatchTick;		// Tick time when Start/Stop Notify occor: Number (Tick)  0: No Notify
	unsigned int NTFLapTick;			// Tick time when Lap Notify occor: Number (Tick)  0: No Notify
	unsigned int NTFResetTick;			// Tick time when Reset Notify occor: Number (Tick)  0: No Notify
	unsigned int NTFAlertTick;		// Tick time when Time Alert Notify occor: Number (Tick)  0: No Notify
	unsigned int NTFAlertIDS;			// Save Alert's Notify IDS
	unsigned int NTFAlarmTick;			// Tick time when Alarm Notify occor: Number (Tick)  0: No Notify
	unsigned int NTFAlarmRingTick;		// Tick time when Alarm Ring occor: Number (Tick)  0: No Notify
	unsigned int NTFAlarmIDS;			// Save Alarm's Notify IDS
	unsigned int NTFWorkoutTick;		// Tick time when Workout Notify occor: Number (Tick)  0: No Notify
	unsigned int NTFVRTick;				// Tick time when Virtual Racer Notify occor: Number (Tick)  0: No Notify
	unsigned int NTFMessageTick;		// Tick time when Message Notify occor: Number (Tick)  0: No Notify
	unsigned int NotifyType;			// Notify Type: bit0:No Notify, bit1:Notify Start/Stop, bit2:Notify Lap, bit20:Compass Calibration
	unsigned int NTFDeviceOffTick;		// Tick time when Device Off Notify occor: Number (Tick)  0: No Notify
	unsigned int NTFDeviceOffIDS;		// Save Device off's Notify IDS
	unsigned int NTFDevicePMsgTick;		// Tick time when Device Press Message Notify occor: Number (Tick)  0: No Notify
	unsigned int NTFDevicePMsgIDS;		// Save Device Device Press Message Notify IDS
	unsigned int NTFBTSPPTick;			// Tick time when Bluetooth SPP Notify occor: Number (Tick)  0: No Notify
	unsigned int NTFBLEFinderTick;		// Tick time when Bluetooth BLE Finder Notify occor: Number (Tick)  0: No Notify
	unsigned int NTFBLEFinderRingTick;	// Tick time when Bluetooth BLE Finder Ring occor: Number (Tick)  0: No Notify

	unsigned int AlarmState;		// Record whether Alarm is occor: bit0:Alarm1, bit1:Alarm2, bit2:Alarm3, bit3:Alarm4

	unsigned int TimeAlertTick;		// Tick time when Time Alert occor: Number (Tick)  0: No Alert
	unsigned int RunAlertTick;		// Tick time when Run Alert occor: Number (Tick)  0: No Alert
	unsigned int WalkAlertTick;		// Tick time when Walk Alert occor: Number (Tick)  0: No Alert
	double DistanceAlertValue;		// Tick time when Distance Alert occor: Value (Meter)
	double ColorieAlertValue;		// Tick time when Calorie Alert occor: Value (Colorie)

	unsigned int MetronomeTick;		// Tick time when Metronome occor: Number (Tick)  0: No Alert

	unsigned int ANTHRLap;			// Ant+ Heart Rate whe Lap occor: Number (Bpm)

	unsigned int LapFootPodCadence;	// Lap FootPod Cadence: Number (Count/Mintue)
	unsigned int LastFootPodCount;	// Last FootPod Count: Number (Time)

	unsigned int LapPreviousBikeTick;	// Lap Previous Bike Time: Number (Tick)
	unsigned int LastBikeCount;		// Last Bike Count: Number (Time)
	unsigned int LastBikeTick;		// Last Bike Time: Number (mSec)
	unsigned int PreviousBikeTick;	// Bike Previous Time: Number (mSec)
	unsigned int BikeTimeout;		// Bike Timeout: Number (mSec)

	unsigned int LapPreviousGSensorTick;	// Present Lap Previous GSensor Time: Number (mSec)
	unsigned int LastGSensorCount;	// Last GSensor Count: Number (Time)
	unsigned int LastGSensorTick;	// Last GSensor Time: Number (mSec)
	unsigned int PreviousGSensorTick;// GSensor Previous Time: Number (mSec)
	unsigned int GSensorTimeout;	// GSensor Timeout: Number (mSec)
	unsigned int UserMove;			// GSensor User Move: 0:Stop, 1:Move
	unsigned int UserMoveTick;		// GSensor User Move Tick: Number (mSec)

	double LapSpeed;				// Lap Run Speed: Number (Km/Hour)
	double LapPreviousRunDistance;		// Lap Previous Run Distance: Number (meter)
	double LapRunDistance;				// Lap Run Distance: Number (meter)
	double RunDistance;				// already Run Distance: Number (meter)
	unsigned int Step;				// Step Count: Number (Count)
	unsigned int LapStep;			// Lap Step Count: Number (Count)
	unsigned int LapPreviousStep;	// Lap Previous Step Count: Number (Count)

	unsigned int RecordTick;		// Record Rocrod Tick when this Tick is occor: Number (Tick)
	unsigned int RecordDistance;	// Record Rocrod Distance when this distance is more than X meter: Number (meter)

	double LapPreviousCalories;		// Lap Previous Run Calories: Number (Col)
	double LapCalories;				// Lap Run Calories: Number (Col)
	double RunCalories;				// Already Run Calories: Number (Col)
	unsigned int CaloriesTick;		// Record Colories Tick when this Tick is occor: Number (Tick)

	unsigned int GradePoint;		// The Grade Point
	double GradeLat[10];			// The Grade Record Lat
	double GradeLon[10];			// The Grade Record Lon
	double GradeHigh[10];			// The Grade Record High
	double Lat;						// The Latest Location
	double Lon;						// The Latest Location
	double High;					// The Latest Location
	unsigned int GPSDistTick;		// Record GPS Distance Tick when this Tick is occor: Number (Tick)
	char Name[14];					// The name of log file: 0:No Log
	char NameLap[14];				// The Lap name of log file: 0:No Log

	unsigned int WorkoutSN;			// Save Workout Serial Number.
	unsigned int WorkoutState;		// Save Workout State: 0:No Workout, 1:Workouting.
	unsigned int WorkoutPoint;		// Point to Workout index
	unsigned int WorkoutAction;		// Execute Action 
	unsigned int WorkoutActionSize;	// Total Execute Action

	unsigned int CourseSN;			// Save Workout Serial Number.
	unsigned int CourseState;		// Save Workout State: 0:No Course, 1:Coursing, 2:Go to Start.
	unsigned int CourseAction;		// Execute Action Point
	unsigned int CourseActionSize;	// Total Execute Action
	unsigned int CourseActionMEM;	// Action Point of being Saved in Memory

	unsigned int GPSLocationState;	// GPS Location Action State: 0:Off, 1:On
	unsigned int VirtualRaceState;	// Virtual Race Action State: 0:Off, 1:On
} GLOBAL_RECORD;

typedef struct
{
	unsigned int RePaint;			// RePaint Screen: 0:No, 1:RePaint
	unsigned int SuspendTick;		// Suspend When Tick time out: Number (Tick)
	unsigned int GPSTimeUpdate;		// Whether GPS Time is update: 0:No Update, 1:Update
	unsigned int GPSFixState;		// GPS Fix State: 0:Off, 1:Available'A', 2:'V'
	unsigned int MonitorL3Tick;		// Monitor Tick for polling 3000ms using
	unsigned int MonitorL2Tick;		// Monitor Tick for polling 1000ms using
	unsigned int MonitorL1Tick;		// Monitor Tick for polling 500ms using
	unsigned int LightState;		// BcakLight State: 0:Off, 1:On
	unsigned int LightOffTick;		// BackLight Off Tick Time, if Tick time occor, backlight Off
	unsigned int ANTHRState;		// ANT+ HR State: 0:Off, 1:On
	unsigned int ANTFootPodState;	// ANT+ Foot Pod State: 0:Off, 1:On
	unsigned int ANTBikeState;		// ANT+ Bike Sensor State: 0:Off, 1:On
	unsigned int RamBufState;		// RAM Buffer State: 0:Free, 1:In-Used
} GLOBAL_STATUS;

typedef struct
{
	char Com[500];
	int Index;				// Command's Index
	
	char Name[10];			// Read File's Name
	int Pos;				// Read File's Pos
	int Size;				// Read File's Size
	unsigned int State;		// Bluetooth State: 0:Off, 1:Standby, 2:File Reading,
	unsigned int Timeout;	// Bluetooth No Data Timeout: Number (Tick)

	unsigned char MSGHead[12];		// Message Head
	unsigned char MSG[3][30];		// Message Content
} GLOBAL_BTSPP;


typedef struct {
	int Year;						// Year (Date)
	int Month;						// Hour (Date)
	int Day;						// Day (Date)
	int Hour;						// Hour (Time)
	int Min;						// Min (Time)
	int Sec;						// Sec (Time)
	unsigned int P1;		// Lat Pos, N=0, S=1	//Workout Type	//Sunday	//BLE first page
	unsigned int D1;		// Lat Degree			//Workout Value	//Monday
	unsigned int M1;		// Lat Minute							//Tuesday
	unsigned int S1;		// Lat Second			//Workout State //Wednesday	//BLE State
	unsigned int cS1;		// Lat 1/100 Second
	unsigned int P2;		// Long Degree, E=0, W=1				//Thursday	//BLE Last page
	unsigned int D2;		// Long Degree			//Virtual RaceDistance //Friday
	unsigned int M2;		// Long Minute			//BLE Type		//Saturday
	unsigned int S2;		// Long Second			//Virtaul Race Time(Sec)
	unsigned int cS2;		// Long 1/100 Second	//BLE Length
	unsigned int High;		// High		//cm		//Workout Page			//BLE Number
	unsigned int Number;	// GPS SN				//Workout SN	//Virtual Race SN	//BLE List Number

} GLOBAL_TEMP, *P_GLOBAL_TEMP;


typedef struct {
	unsigned int State;			// Workout State: 0:Off, 1:Execute, 2:Rest, 8:Warm Up, 9:Cool Down
	unsigned int Type;			// Workout Type: 0:LapPress, 1:Time, 2:Distance, 3:HR_GT, 4:HR_ST, 5:Caloric
	unsigned int Info;			// Workout Info
}GLOBAL_WORKOUT, *P_GLOBAL_WORKOUT;


typedef struct {
	unsigned int Tick;
	double Lat;				// Latitude 
	double Long;			// Longitude
	double High;
	double Distance;
}GLOBAL_COURSE_DATA, *P_GLOBAL_COURSE_DATA;



void fPaint_MenuContent2( void );
unsigned short fMenuTable(unsigned short Index);
unsigned short fPDMenuTable(unsigned short Index);
unsigned short fMixTable(unsigned short Index);
unsigned short fLapMore( void );
unsigned short fLapList( void );
unsigned short fLapShow2( void );
unsigned short fLapMap2( void );
unsigned short fLapTotal( unsigned short Mode );
unsigned short fChangeSport(void *pfun, void *pIn);
unsigned short fLight(void *pfun, void *pIn);
unsigned short fSetShowTable( unsigned short usFun );
unsigned short fShowTable( unsigned short usFun );
unsigned short fAbout(void);
unsigned short FunctionList( unsigned short usFun );
unsigned short fMemoryDetail( void );
unsigned short fCompass( void );
unsigned short fCompassCalib( void );
unsigned short fANTConnect( unsigned short usFun );
unsigned short fTemperature( void );
unsigned short fPressure( void );
unsigned short fGpsStatusCN( void );
unsigned short fGpsStatusSat( void );
unsigned short fSppLogStatus( void );
unsigned short fBLEMenu( int Type );
unsigned short fBLEList( int Type );
unsigned short fBLEListMore( int Type );
unsigned short fBLEScan( int Type );
unsigned short fClock( void );
unsigned short fGPSLocation( void );
unsigned short fGPSLocationModify( void );
unsigned short fGPSLocationMore( void );
unsigned short fWorkoutList( void );
unsigned short fWorkoutMore( void );
unsigned short fWorkoutPage( void );
unsigned short fWorkoutPageModify( void );
unsigned short fWorkoutRun( void );
unsigned short fGPSNavigate( void );
unsigned short fGpsMapStatus( char *pName );
unsigned short fGpsDirectStatus( void );
unsigned short fVirtualRace( void );
unsigned short fVirtualRaceMore( void );
unsigned short fVirtualRaceModify( void );
unsigned short fVirtualRaceRun( void );
unsigned short fCourseAdd( void );
unsigned short fCourseMap( void );
unsigned short fCourseMore( void );
unsigned short fCourseList( void );
unsigned short fCourseRun( void );
unsigned short fPowerManager(void *pfun, void *pIn);
unsigned short fVRaceStatus( void );
unsigned short fCalibartion( unsigned short usTableIndex );

void PaintOpenScreen( void );
void ChargingFrame( void );

void MoveInitial( void );

void Monitor( int *pRePaint );
void ButtonEvent(unsigned short *pEvent);

void fPaint_Notify(void);
void fPaint_WorkoutRunNotify( void );
void fPaint_VirtualRaceNotify( void );
void fPaint_BluetoothNotify( void );
void fPaint_BluetoothSPPNotify( void );
void doPaintDirection(double r);
void doPaintCompass(double r);
void fPaint_Lap( unsigned int SN );

#endif
