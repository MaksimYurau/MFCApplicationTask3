
// KrestNol.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CKrestNolApp:
// Сведения о реализации этого класса: KrestNol.cpp
//

class CKrestNolApp : public CWinApp
{
public:
	CKrestNolApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CKrestNolApp theApp;
