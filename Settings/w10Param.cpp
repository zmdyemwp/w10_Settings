#include "stdafx.h"
#include "w10Param.h"
#include "StringTable.h"


/**************************************************************
*		Settings
*/
W10PARAM	mode;
W10PARAM	lang;
W10PARAM	bktimeout;
W10PARAM	bklevel;
W10PARAM	recorddata;
W10PARAM	timezone1;
W10PARAM	position;
W10PARAM	autolap;
W10PARAM	autopause;
W10PARAM	autoscroll;
W10PARAM	antfootstep;

W10PARAM	antbikeweight;
W10PARAM	antbikeodometer;
W10PARAM	antbikewheel;

W10PARAM	gsensorstep;
W10PARAM	timezone2;

W10PARAM	btspptone;
W10PARAM	btsppvibration;
W10PARAM	metronomeInterval;
W10PARAM	metronomeRing;

W10PARAM	alarm4;

/**************************************************************
*		Training
*/
W10PARAM	timeAlert;
W10PARAM	distAlert;
W10PARAM	calorieAlert;
W10PARAM	heartRateAlert;
W10PARAM	interval;
W10PARAM	rest;
W10PARAM	reps;
W10PARAM	age;
W10PARAM	weight_height;


void InitParamW10(void) {

/**************************************************************
*		Settings
*/
	//		Mode
	memset(&mode, 0, sizeof(mode));
	mode.title = IDS_WWE_MODE;
	mode.count = 5;
	mode.options[0] = IDS_WWE_RUN;
	mode.options[1] = IDS_WWE_BIKE;
	mode.options[2] = IDS_WWE_OWSWIM;
	mode.options[3] = IDS_WWE_POOLSWIM;
	mode.options[4] = IDS_WWE_OTHER;

	//		Language
	memset(&lang, 0, sizeof(lang));
	lang.title = IDS_WWE_LANGUAGE;
	lang.count = 3;
	lang.options[0] = IDS_WWE_WWE;
	lang.options[1] = IDS_WWE_CHT;
	lang.options[2] = IDS_WWE_CHS;

	//		backlight timeout
	memset(&bktimeout, 0, sizeof(bktimeout));
	bktimeout.title = IDS_WWE_BACKLIGHT_TIMEOUT;
	bktimeout.count = 0;
	//bktimeout.options[0] = IDS_WWE_STAYS_ON;
	bktimeout.options[0] = IDS_WWE_SECONDS;

	//		backlight level
	memset(&bklevel, 0, sizeof(bklevel));
	bklevel.title = IDS_WWE_BACKLIGHT_LEVEL;
	bklevel.count = 3;
	bklevel.options[0] = IDS_WWE_OFF;
	bklevel.options[1] = IDS_WWE_MIDDLE;
	bklevel.options[2] = IDS_WWE_HIGH;

	//		Record Data Points
	memset(&recorddata, 0, sizeof(recorddata));
	recorddata.title = IDS_WWE_RECORD_DATA_POINT;
	recorddata.count = 3;
	recorddata.options[0] = IDS_WWE_SMART_RECORDING;
	recorddata.options[1] = IDS_WWE_EVENT_RECORDING;
	recorddata.options[2] = IDS_WWE_NO_RECORD;

	//		Time Zone 1
	memset(&timezone1, 0, sizeof(timezone1));
	timezone1.title = IDS_WWE_TIME_ZONE_1;
	timezone1.count = 0;

	//		Position
	memset(&position, 0, sizeof(position));
	position.title = IDS_WWE_POSITION;
	position.count = 3;
	position.options[0] = IDS_POSITION_1;
	position.options[1] = IDS_POSITION_2;
	position.options[2] = IDS_POSITION_3;

	//		Auto Lap
	memset(&autolap, 0, sizeof(autolap));
	autolap.title = IDS_WWE_AUTO_LAP_TRIGGER;
	autolap.count = 3;
	autolap.options[0] = IDS_WWE_OFF;
	autolap.options[1] = IDS_WWE_BY_TIME;
	autolap.options[2] = IDS_WWE_BY_DISTANCE;
	autolap.options[3] = 0;
	autolap.options[4] = IDS_WWE_SECONDS;
	autolap.options[5] = IDS_WWE_METERS;

	//		Auto Pause
	memset(&autopause, 0, sizeof(autopause));
	autopause.title = IDS_WWE_AUTO_TIMER_PAUSE;
	autopause.count = 3;
	autopause.options[0] = IDS_WWE_OFF;
	autopause.options[1] = IDS_WWE_WHEN_STOPPED;
	autopause.options[2] = IDS_WWE_CUSTOM_PACE;
	autopause.options[3] = 0;
	autopause.options[4] = 0;
	autopause.options[5] = IDS_WWE_SECONDS;

	//		Auto Scroll
	memset(&autoscroll, 0, sizeof(autoscroll));
	autoscroll.title = IDS_WWE_AUTO_SCROLL;
	autoscroll.count = 4;
	autoscroll.options[0] = IDS_WWE_OFF;
	autoscroll.options[1] = IDS_WWE_SLOW;
	autoscroll.options[2] = IDS_WWE_MEDIUM;
	autoscroll.options[3] = IDS_WWE_FAST;

	//		ANT+ Step Distance
	memset(&antfootstep, 0, sizeof(antfootstep));
	antfootstep.title = IDS_WWE_ANT_FOOT_PAD_STEP_DISTANCE;
	antfootstep.count = 0;
	antfootstep.options[0] = IDS_WWE_RUN;
	antfootstep.options[1] = IDS_WWE_SWIM;
	antfootstep.options[2] = IDS_WWE_OTHER;
	antfootstep.options[3] = IDS_WWE_CM;

	//		ANT+ Bike Weight
	memset(&antbikeweight, 0, sizeof(antbikeweight));
	antbikeweight.title = IDS_WWE_ANT_BIKE_WEIGHT;
	antbikeweight.count = 0;
	antbikeweight.options[0] = IDS_WWE_KG;

	//		ANT+ Bike Odometer
	memset(&antbikeodometer, 0, sizeof(antbikeodometer));
	antbikeodometer.title = IDS_WWE_ANT_BIKE_ODOMETER;
	antbikeodometer.count = 0;
	antbikeodometer.options[0] = IDS_WWE_METERS;

	//		ANT+ Bike Wheel
	memset(&antbikewheel, 0, sizeof(antbikewheel));
	antbikewheel.title = IDS_WWE_ANT_BIKE_WHEEL_SIZE;
	antbikewheel.count = 0;
	antbikewheel.options[0] = IDS_WWE_CM;

	//		GSensor Step Distance
	memset(&gsensorstep, 0, sizeof(gsensorstep));
	gsensorstep.title = IDS_WWE_GSENSOR_STEP_DISTANCE;
	gsensorstep.count = 0;
	gsensorstep.options[0] = IDS_WWE_RUN;
	gsensorstep.options[1] = IDS_WWE_SWIM;
	gsensorstep.options[2] = IDS_WWE_OTHER;
	gsensorstep.options[3] = IDS_WWE_CM;

	//		Time Zone 1
	memset(&timezone2, 0, sizeof(timezone2));
	timezone2.title = IDS_WWE_TIME_ZONE_2;
	timezone2.count = 0;

	//		BT SPP Tone
	memset(&btspptone, 0, sizeof(btspptone));
	btspptone.title = IDS_WWE_BT_SPP_TONE;
	btspptone.count = 0;
	btspptone.options[0] = IDS_WWE_MS;

	//		BT SPP Vibration
	memset(&btsppvibration, 0, sizeof(btsppvibration));
	btsppvibration.title = IDS_WWE_BT_SPP_VIBRATION;
	btsppvibration.count = 0;
	btsppvibration.options[0] = IDS_WWE_MS;

	//		Metronome Interval
	memset(&metronomeInterval, 0, sizeof(metronomeInterval));
	metronomeInterval.title = IDS_WWE_METRONOME_TIME;
	metronomeInterval.count = 0;
	metronomeInterval.options[0] = IDS_WWE_MS;

	//		Metronome Ring
	memset(&metronomeRing, 0, sizeof(metronomeRing));
	metronomeRing.title = IDS_WWE_METRONOME_RING;
	metronomeRing.count = 0;
	metronomeRing.options[0] = IDS_WWE_MS;

	//		Alarm * 4
	memset(&alarm4, 0, sizeof(alarm4));
	alarm4.title = IDS_WWE_ALARM;


/**************************************************************
*		Training
*/
	//		Time Alert
	memset(&timeAlert, 0, sizeof(W10PARAM));
	timeAlert.title = IDS_WWE_TIME_ALART;
	timeAlert.count = 2;
	timeAlert.options[0] = IDS_WWE_OFF;
	timeAlert.options[1] = IDS_WWE_ON;
	timeAlert.options[2] = 0;
	timeAlert.options[3] = IDS_WWE_SECONDS;
	
	//		Dist. Alert
	memset(&distAlert, 0, sizeof(W10PARAM));
	distAlert.title = IDS_WWE_DISTANCE_ALART;
	distAlert.count = 2;
	distAlert.options[0] = IDS_WWE_OFF;
	distAlert.options[1] = IDS_WWE_ON;
	distAlert.options[2] = 0;
	distAlert.options[3] = IDS_WWE_METERS;
	
	//		Calorie Alert
	memset(&calorieAlert, 0, sizeof(W10PARAM));
	calorieAlert.title = IDS_WWE_CALORIE_ALART;
	calorieAlert.count = 2;
	calorieAlert.options[0] = IDS_WWE_OFF;
	calorieAlert.options[1] = IDS_WWE_ON;
	calorieAlert.options[2] = 0;
	calorieAlert.options[3] = IDS_WWE_CAL;
	
	//		Heart Rate Alert
	memset(&heartRateAlert, 0, sizeof(W10PARAM));
	heartRateAlert.title = IDS_WWE_HR_ALART;
	heartRateAlert.count = 2;
	heartRateAlert.options[0] = IDS_WWE_OFF;
	heartRateAlert.options[1] = IDS_WWE_ON;
	heartRateAlert.options[2] = 0;
	heartRateAlert.options[3] = IDS_WWE_BPM;
	
	//		Interval
	memset(&interval, 0, sizeof(W10PARAM));
	interval.title = IDS_WWE_INTERVAL_TYPE;
	interval.count = 2;
	interval.options[0] = IDS_WWE_TIME;
	interval.options[1] = IDS_WWE_DISTANCE;
	interval.options[2] = IDS_WWE_SECONDS;
	interval.options[3] = IDS_WWE_METERS;
	
	//		Rest
	memset(&rest, 0, sizeof(W10PARAM));
	rest.title = IDS_WWE_REST_TYPE;
	rest.count = 2;
	rest.options[0] = IDS_WWE_TIME;
	rest.options[1] = IDS_WWE_DISTANCE;
	rest.options[2] = IDS_WWE_SECONDS;
	rest.options[3] = IDS_WWE_METERS;
	
	//		Repeat
	memset(&reps, 0, sizeof(W10PARAM));
	reps.title = IDS_WWE_REPEATS;
	
	//		Age
	memset(&age, 0, sizeof(W10PARAM));
	age.title = IDS_WWE_AGE;
	
	//		Weight & Height
	memset(&weight_height, 0, sizeof(W10PARAM));
	weight_height.title = IDS_WWE_WEIGHT_HEIGHT;
	weight_height.count = 0;
	weight_height.options[0] = IDS_WWE_KG;
	weight_height.options[1] = IDS_WWE_CM;
	weight_height.options[2] = IDS_WWE_POUND;
	weight_height.options[3] = IDS_WWE_INCH;


}

