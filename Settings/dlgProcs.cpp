#include "stdafx.h"
#include "dlgProcs.h"
#include "w10Param.h"
#include "resource.h"

static W10PARAM * obj;

INT_PTR CALLBACK sampleProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	switch(message) {
		case WM_INITDIALOG:
			//		Title
			SetWindowText(hDlg, w10_LoadString(obj->title));
			SetDlgItemText(hDlg, IDC_APPLY, w10_LoadString(IDS_WWE_APPLY));
			//		Options
			return TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam)) {
				case IDC_APPLY:
					//		TODO:	revise value here.
					EndDialog(hDlg, LOWORD(wParam));
					break;
				case IDOK:
				case IDCANCEL:
					EndDialog(hDlg, LOWORD(wParam));
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
	return FALSE;
}

/*********************************************************************
*		COMBOBOX
*/
INT_PTR CALLBACK ComboListProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	if(WM_INITDIALOG == message) {
		obj = (W10PARAM *)lParam;
		//		Options
		for(DWORD i = 0; i < obj->count; i++) {
			SendDlgItemMessage(hDlg, IDC_OPTIONS, CB_INSERTSTRING,
				-1, (LPARAM)w10_LoadString(obj->options[i]));
		}
		SendDlgItemMessage(hDlg, IDC_OPTIONS, CB_SETCURSEL, obj->index, 0);
	} else if(WM_COMMAND == message && IDC_APPLY == LOWORD(wParam)) {
		//		TODO:	revise value here.
		obj->index = SendDlgItemMessage(hDlg, IDC_OPTIONS, CB_GETCURSEL, 0, 0);
	}
	return sampleProc(hDlg,message,wParam,lParam);
}

/*********************************************************************
*		EDITTEXT
*/
INT_PTR CALLBACK EditProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	if(WM_INITDIALOG == message) {
		obj = (W10PARAM *)lParam;
		//		Options
		SetDlgItemInt(hDlg, IDC_EDIT, obj->index, FALSE);
		SetDlgItemText(hDlg, IDC_UNIT_TEXT, w10_LoadString(obj->options[0]));
	} else if(WM_COMMAND == message && IDC_APPLY == LOWORD(wParam)) {
		//		TODO:	revise value here.
		BOOL result;
		obj->index = GetDlgItemInt(hDlg, IDC_EDIT, &result, FALSE);
	}
	return sampleProc(hDlg,message,wParam,lParam);
}

/*********************************************************************
*		TIMEZONE (COMBOBOX * 2)
*/
INT_PTR CALLBACK TimeZoneProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	if(WM_INITDIALOG == message) {
		obj = (W10PARAM *)lParam;
		DWORD hour = obj->index >> 8;
		hour = (hour > 20)? hour+12-32 : hour+12;
		DWORD minute = obj->index & 0xff;
		TCHAR temp[8];
		for(int i = 0; i <= 25; i++) {
			swprintf(temp, 8, L"%s%2d", (12 > i)? "-":"+", i-12);
			SendDlgItemMessage(hDlg, IDC_HOUR, CB_INSERTSTRING, -1, (LPARAM)temp);
		}
		SendDlgItemMessage(hDlg, IDC_HOUR, CB_SETCURSEL, hour, 0);
		for(int i = 0; i < 60; i++) {
			swprintf(temp, 8, L"%02d", i);
			SendDlgItemMessage(hDlg, IDC_MINUTE, CB_INSERTSTRING, -1, (LPARAM)temp);
		}
		SendDlgItemMessage(hDlg, IDC_MINUTE, CB_SETCURSEL, minute, 0);
	} else if(WM_COMMAND == message && IDC_APPLY == LOWORD(wParam)) {
		//		TODO:	revise value here.
		DWORD hour = SendDlgItemMessage(hDlg, IDC_HOUR, CB_GETCURSEL, 0, 0);
		hour = (12 > hour)? 32+hour-12:hour-12;
		DWORD minute = SendDlgItemMessage(hDlg, IDC_MINUTE, CB_GETCURSEL, 0, 0);
		obj->index = hour << 8 | minute;
	}
	return sampleProc(hDlg,message,wParam,lParam);
}

/*********************************************************************
*		COMBOBOX + EDITTEXT
*/
void ComboEditRefresh(HWND, W10PARAM*);
INT_PTR CALLBACK ComboEditProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	static DWORD sel = 0;
	if(WM_INITDIALOG == message) {
		obj = (W10PARAM *)lParam;
		//		Options
		for(DWORD i = 0; i < obj->count; i++) {
			SendDlgItemMessage(hDlg, IDC_OPTIONS, CB_INSERTSTRING,
				-1, (LPARAM)w10_LoadString(obj->options[i]));
		}
		sel = obj->index;
		SendDlgItemMessage(hDlg, IDC_OPTIONS, CB_SETCURSEL, sel, 0);
		//		Options cont.
		ComboEditRefresh(hDlg, obj);

	} else if(WM_COMMAND == message) {
		if(IDC_OPTIONS == LOWORD(wParam) && CBN_SELCHANGE == HIWORD(wParam)) {
			//		revise values immediately
			obj->index = SendDlgItemMessage(hDlg, IDC_OPTIONS, CB_GETCURSEL, 0, 0);
			if(sel != obj->index) {
				obj->valueList[sel] = GetDlgItemInt(hDlg, IDC_EDIT, NULL, FALSE);
			}
			sel = obj->index;
			ComboEditRefresh(hDlg, obj);
		} else if (IDC_APPLY == LOWORD(wParam)) {
			//		TODO:	revise value here.
			obj->index = SendDlgItemMessage(hDlg, IDC_OPTIONS, CB_GETCURSEL, 0, 0);
			obj->valueList[obj->index] = GetDlgItemInt(hDlg, IDC_EDIT, NULL, FALSE);
		}
	}
	return sampleProc(hDlg,message,wParam,lParam);
}
void ComboEditRefresh(HWND hDlg, W10PARAM * obj) {
	if(MAXDWORD == obj->valueList[obj->index]) {
		SetDlgItemText(hDlg, IDC_EDIT, L"N/A");
		EnableWindow(GetDlgItem(hDlg, IDC_EDIT), FALSE);
		SetDlgItemText(hDlg, IDC_UNIT_TEXT, L"");
	} else {
		EnableWindow(GetDlgItem(hDlg, IDC_EDIT), TRUE);
		SetDlgItemInt(hDlg, IDC_EDIT, obj->valueList[obj->index], FALSE);
		SetDlgItemText(hDlg, IDC_UNIT_TEXT, w10_LoadString(obj->options[obj->count + obj->index]));
	}
}

/*********************************************************************
*		STEP (EDITTEXT * 3)
*/
INT_PTR CALLBACK StepProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	if(WM_INITDIALOG == message) {
		obj = (W10PARAM *)lParam;
		//		Options
		SetDlgItemInt(hDlg, IDC_EDIT1, obj->valueList[0], FALSE);
		SetDlgItemInt(hDlg, IDC_EDIT2, obj->valueList[1], FALSE);
		SetDlgItemInt(hDlg, IDC_EDIT3, obj->valueList[2], FALSE);
		SetDlgItemText(hDlg, IDC_RUN, w10_LoadString(obj->options[0]));
		SetDlgItemText(hDlg, IDC_SWIM, w10_LoadString(obj->options[1]));
		SetDlgItemText(hDlg, IDC_OTHER, w10_LoadString(obj->options[2]));
		TCHAR temp[16+1] = {0};
		swprintf(temp, 16, L"(%s)", w10_LoadString(obj->options[3]));
		SetDlgItemText(hDlg, IDC_UNIT_TEXT, temp);
	} else if(WM_COMMAND == message && IDC_APPLY == LOWORD(wParam)) {
		//		TODO:	revise value here.
		obj->valueList[0] = GetDlgItemInt(hDlg, IDC_EDIT1, NULL, FALSE);
		obj->valueList[1] = GetDlgItemInt(hDlg, IDC_EDIT2, NULL, FALSE);
		obj->valueList[2] = GetDlgItemInt(hDlg, IDC_EDIT3, NULL, FALSE);
	}
	return sampleProc(hDlg,message,wParam,lParam);
}


