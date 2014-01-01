// Settings.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Settings.h"
#include "mmi_frame.h"
#include "resource.h"

TCHAR msg[1024+1];

GLOBAL_SETTING g_Setting;


HINSTANCE g_hInst;
HWND g_hDlg;
INT_PTR CALLBACK	SettingProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	g_hInst = hInstance;
	memset(&g_Setting, 0, sizeof(GLOBAL_SETTING));
	swprintf(msg, 1024, L"%d", sizeof(GLOBAL_SETTING));
	dmsg(msg);

	DialogBox(hInstance, MAKEINTRESOURCE(IDD_SETTINGS), NULL, SettingProc);
	return 0;
}

void Refresh(void);
// Message handler for about box.
INT_PTR CALLBACK SettingProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		g_hDlg = hDlg;
		Refresh();
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}


TCHAR* w10_LoadString(DWORD id);
void Refresh(void) {
	TCHAR temp[128+1];
	//		Mode
	swprintf(temp, 128, L"%s ", w10_LoadString(IDS_WWE_MODE));
	DWORD len = wcslen(temp);
	if(1 <= g_Setting.Mode && 5 >= g_Setting.Mode) {
		swprintf(temp+len, 128 - len, L"%s ", w10_LoadString(10001 + g_Setting.Mode));
	}
	SetDlgItemText(g_hDlg, IDC_MODE, temp);
	//		Language
	swprintf(temp, 128, L"%s ", w10_LoadString(IDS_WWE_LANGUAGE));
	len = wcslen(temp);
	if(0 < g_Setting.Language && 4 > g_Setting.Language) {
		swprintf(temp + len, 128 - len, L"%s", w10_LoadString(10006 + g_Setting.Language));
	}
	SetDlgItemText(g_hDlg, IDC_LANG, temp);
	//		Key Tone
	swprintf(temp, 128, L"%s ", w10_LoadString(IDS_WWE_KEY_TONE));
	len = wcslen(temp);
	if(0 <= g_Setting.KeyTone && 2 > g_Setting.KeyTone) {
		swprintf(temp + len, 128 - len, L"%s", w10_LoadString((0 == g_Setting.KeyTone)? IDS_WWE_OFF:IDS_WWE_ON));
	}
	SetDlgItemText(g_hDlg, IDC_KEYTONE, temp);
	//		Message Tone
	swprintf(temp, 128, L"%s ", w10_LoadString(IDS_WWE_MESSAGE_TONE));
	len = wcslen(temp);
	if(0 <= g_Setting.MessageTone && 2 > g_Setting.MessageTone) {
		swprintf(temp + len, 128 - len, L"%s", w10_LoadString((0 == g_Setting.MessageTone)? IDS_WWE_OFF:IDS_WWE_ON));
	}
	SetDlgItemText(g_hDlg, IDC_MESSAGETONE, temp);
	//		Vibration
	swprintf(temp, 128, L"%s ", w10_LoadString(IDS_WWE_VIBRATION));
	len = wcslen(temp);
	if(0 <= g_Setting.Vibration && 2 > g_Setting.Vibration) {
		swprintf(temp + len, 128 - len, L"%s", w10_LoadString((0 == g_Setting.Vibration)? IDS_WWE_OFF:IDS_WWE_ON));
	}
	SetDlgItemText(g_hDlg, IDC_VIBRATION, temp);
	//		Backlight Timeout
	swprintf(temp, 128, L"%s ", w10_LoadString(IDS_WWE_BACKLIGHT_TIMEOUT));
	len = wcslen(temp);
	if(0 < g_Setting.BacklightTimeout) {
		swprintf(temp + len, 128 - len, L"%d %s", g_Setting.BacklightTimeout, w10_LoadString(IDS_WWE_SECONDS));
	} else if(0 == g_Setting.BacklightTimeout) {
		swprintf(temp + len, 128 - len, L"%s", w10_LoadString(IDS_WWE_STAYS_ON));
	}
	SetDlgItemText(g_hDlg, IDS_WWE_BACKLIGHT_TIMEOUT, temp);
	//		Backlight Level
	swprintf(temp, 128, L"%s ", w10_LoadString(IDS_WWE_BACKLIGHT_LEVEL));
	len = wcslen(temp);
	if(0 <= g_Setting.BacklightLevel && 3 > g_Setting.BacklightLevel) {
		swprintf(temp + len, 128 - len, L"%s", w10_LoadString(IDS_WWE_SECONDS + g_Setting.BacklightLevel));
	}
	SetDlgItemText(g_hDlg, IDS_WWE_BACKLIGHT_TIMEOUT, temp);
}

TCHAR* w10_LoadString(DWORD id) {
	static TCHAR str[256+1];
	memset(str ,0, sizeof(str));
	LoadString(g_hInst, id, str, 256);
	return str;
}

