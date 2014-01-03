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
		//		Options
	} else if(WM_COMMAND == message && IDC_APPLY == LOWORD(wParam)) {
		//		TODO:	revise value here.
		DWORD hour = SendDlgItemMessage(hDlg, IDC_HOUR, CB_GETCURSEL, 0, 0);
		hour = (12 > hour)? 32+hour-12:hour-12;
		DWORD minute = SendDlgItemMessage(hDlg, IDC_MINUTE, CB_GETCURSEL, 0, 0);
		obj->index = hour << 8 | minute;
	}
	return sampleProc(hDlg,message,wParam,lParam);
}
