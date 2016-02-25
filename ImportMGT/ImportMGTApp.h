/////////////////////////////////////////////////////////////////////////////
// ImportMGTApp.h : main header file for the ImportMGT DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "Resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CImportMGTApp
// See ImportMGTApp.cpp for the implementation of this class
//

class CImportMGTApp : public CWinApp
{
public:
	CImportMGTApp();

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};
