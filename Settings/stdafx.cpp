// stdafx.cpp : source file that includes just the standard includes
// Settings.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

void dmsg(TCHAR * msg, DWORD x)
{
	if(0 == x)
		return;

	TCHAR buffer[1024] = {0};
	wsprintf(buffer, L"[Cosmos]\t%s\r\n", msg);
	HWND hDlg = FindWindow(NULL, L"DebugMsg");
	if(IsWindow(hDlg))
	{
		SendDlgItemMessage(hDlg, 10101, EM_REPLACESEL, 0, (LPARAM)buffer);
	}
	else {
		//MessageBox(NULL, L"Window NOT Found", NULL, 0);
	}
}

