#include "stdafx.h"
#include "resource.h"

#define		dim(x)		sizeof(x)/sizeof(x[0])

DWORD doneTable[] = {
	IDC_KEYTONE,
	IDC_MESSAGETONE,
	IDC_VIBRATION,
	IDC_ORIENTATION,
	IDC_USER_LOCATION,
	IDC_SHOW_MAP,
	IDC_ANT_WEIGHT_SCALE,
	IDC_ANT_FITNESS_EQUIPMENT,
	IDC_TIME_FORMAT,
	IDC_DAYLIGHT_SAVING_1,
	IDC_UNIT,
	IDC_VIRTUAL_PARTNER,
	IDC_PACE_SPEED,
	IDC_ANT_HEART_RATE_MONITOR,
	IDC_ANT_HEART_RATE_DISPLAY,
	IDC_ANT_FOOT_PAD,
	IDC_ANT_FOOT_PAD_SOURCE,
	IDC_ANT_BIKE,
	IDC_ANT_BIKE_SENSOR,
	IDC_ANT_POWER_METER_SENSOR,
	IDC_GSENSOR_COMPASS_SENSOR,
	IDC_BLE_FINDER,
	IDC_BLE_HEART_RATE,
	IDC_DAYLIGHT_SAVING_2,
	IDC_GPS_TIMER_AUTO_UPDATE,
	IDC_BAROMETER_SENSOR,
	IDC_THEME,
	IDC_METRONOME_STATE,
	IDC_WARM_UP,
	IDC_COOL_DOWN,
	IDC_GENDER,
	IDC_LIFETIME_ATHLETE,
};

BOOL checkDoneTable(DWORD id) {
	DWORD i = 0;
	for(i = 0; i < dim(doneTable); i++) {
		if(id == doneTable[i]) {
			break;
		}
	}
	if(i < dim(doneTable)) {
		return TRUE;
	} else {
		return FALSE;
	}
}
