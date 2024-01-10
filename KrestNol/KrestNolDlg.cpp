
// KrestNolDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "KrestNol.h"
#include "KrestNolDlg.h"
#include "afxdialogex.h"
#include <map>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CKrestNolDlg



CKrestNolDlg::CKrestNolDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_KRESTNOL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	hod = 0;
	check = FALSE;
}
void CKrestNolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CKrestNolDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_3, &CKrestNolDlg::OnBnClicked3)
//	ON_BN_CLICKED(IDC_1, &CKrestNolDlg::OnBnClicked1)
ON_BN_CLICKED(IDC_1, &CKrestNolDlg::OnClicked1)
ON_BN_CLICKED(IDC_2, &CKrestNolDlg::OnClicked2)
ON_BN_CLICKED(IDC_3, &CKrestNolDlg::OnClicked3)
ON_BN_CLICKED(IDC_4, &CKrestNolDlg::OnClicked4)
ON_BN_CLICKED(IDC_5, &CKrestNolDlg::OnClicked5)
ON_BN_CLICKED(IDC_6, &CKrestNolDlg::OnClicked6)
ON_BN_CLICKED(IDC_7, &CKrestNolDlg::OnClicked7)
ON_BN_CLICKED(IDC_8, &CKrestNolDlg::OnClicked8)
ON_BN_CLICKED(IDC_9, &CKrestNolDlg::OnClicked9)
ON_BN_CLICKED(IDC_WINNER, &CKrestNolDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений CKrestNolDlg

BOOL CKrestNolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CKrestNolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CKrestNolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CKrestNolDlg::OnBnClicked3()
//{
//	// TODO: добавьте свой код обработчика уведомлений
//}


//void CKrestNolDlg::OnBnClicked1()
//{
//	// TODO: добавьте свой код обработчика уведомлений
//}
void CKrestNolDlg::winner() {
	int value=0;
	for (int i = 1; i < 10; i++) {
		if ((pole_map[i] ==1&& pole_map[i+2] ==1&& pole_map[i+4] == 1 )|| (pole_map[i] ==2&& pole_map[i + 2] ==2&& pole_map[i + 4]==2)) {
			if (pole_map[i] == 1 && pole_map[i + 2] == 1 && pole_map[i + 4] == 1) {
				value = 1;
				break;
			}
			else {
				value = 2;
				break;
			}
		}
		if ((pole_map[i] ==1&& pole_map[i + 3] ==1&& pole_map[i + 6]==1)|| (pole_map[i] ==2 &&pole_map[i + 3]==2&&pole_map[i + 6]==2)) {
			if (pole_map[i] == 1 && pole_map[i + 3] == 1 && pole_map[i + 6] == 1){
				value = 1;
				break;
			}
			else {
				value = 2;
				break;
			}
			
		}
		if ((pole_map[i] == 1 && pole_map[i + 1] == 1 && pole_map[i + 2] == 1) || (pole_map[i] == 2 && pole_map[i + 1] == 2 && pole_map[i + 2] == 2)) {
			if (pole_map[i] == 1 && pole_map[i + 1] == 1 && pole_map[i + 2] == 1) {
				value = 1;
				break;
			}
			else {
				value = 2;
				break;
			}

		}

	}
	if (value!=0){
	CButton* pButton = (CButton*)GetDlgItem(IDC_WINNER); // Замените IDC_MY_BUTTON на идентификатор вашей кнопки

	switch (value) {
	case(0): break;
	case(1): pButton->SetWindowText(_T("Победитель: X"));
	case(2): pButton->SetWindowText(_T("Победитель: O"));
	}
}
}

void CKrestNolDlg::OnClicked1()
{
	CButton* pButton = (CButton*)GetDlgItem(IDC_1); 
	if (pole_map[1] == 0) {
		if (hod % 2 == 0 || hod == 0) {
			pButton->SetWindowText(_T("X"));
			pole_map[1] = 1;
			hod = hod + 1;
		}
		else {
			pButton->SetWindowText(_T("O"));
			pole_map[1] = 2;
			hod = hod + 1;
		}

	}
	winner();
}


void CKrestNolDlg::OnClicked2()
{
	CButton* pButton = (CButton*)GetDlgItem(IDC_2); // Замените IDC_MY_BUTTON на идентификатор вашей кнопки
	if (pole_map[2] == 0) {
		if (hod % 2 == 0 || hod == 0) {
			pButton->SetWindowText(_T("X"));
			pole_map[2] = 1;
			hod = hod + 1;
		}
		else {
			pButton->SetWindowText(_T("O"));
			pole_map[2] = 2;
			hod = hod + 1;
		}

	}
	winner();
}


void CKrestNolDlg::OnClicked3()
{
	CButton* pButton = (CButton*)GetDlgItem(IDC_3); // Замените IDC_MY_BUTTON на идентификатор вашей кнопки
	if (pole_map[3] == 0) {
		if (hod % 2 == 0 || hod == 0) {
			pButton->SetWindowText(_T("X"));
			pole_map[3] = 1;
			hod = hod + 1;
		}
		else {
			pButton->SetWindowText(_T("O"));
			pole_map[3] = 2;
			hod = hod + 1;
		}

	}
	winner();
}


void CKrestNolDlg::OnClicked4()
{
	CButton* pButton = (CButton*)GetDlgItem(IDC_4); // Замените IDC_MY_BUTTON на идентификатор вашей кнопки
	if (pole_map[4] == 0) {
		if (hod % 2 == 0 || hod == 0) {
			pButton->SetWindowText(_T("X"));
			pole_map[4] = 1;
			hod = hod + 1;
		}
		else {
			pButton->SetWindowText(_T("O"));
			pole_map[4] = 2;
			hod = hod + 1;
		}

	}
	winner();
}


void CKrestNolDlg::OnClicked5()
{
	CButton* pButton = (CButton*)GetDlgItem(IDC_5); // Замените IDC_MY_BUTTON на идентификатор вашей кнопки
	if (pole_map[5] == 0) {
		if (hod % 2 == 0 || hod == 0) {
			pButton->SetWindowText(_T("X"));
			pole_map[5] = 1;
			hod = hod + 1;
		}
		else {
			pButton->SetWindowText(_T("O"));
			pole_map[5] = 2;
			hod = hod + 1;
		}

	}
	winner();
}


void CKrestNolDlg::OnClicked6()
{
	CButton* pButton = (CButton*)GetDlgItem(IDC_6); // Замените IDC_MY_BUTTON на идентификатор вашей кнопки
	if (pole_map[6] == 0) {
		if (hod % 2 == 0 || hod == 0) {
			pButton->SetWindowText(_T("X"));
			pole_map[6] = 1;
			hod = hod + 1;
		}
		else {
			pButton->SetWindowText(_T("O"));
			pole_map[6] = 2;
			hod = hod + 1;
		}

	}
	winner();
}


void CKrestNolDlg::OnClicked7()
{
	CButton* pButton = (CButton*)GetDlgItem(IDC_7); // Замените IDC_MY_BUTTON на идентификатор вашей кнопки

	if (pole_map[7] == 0) {
		if (hod % 2 == 0 || hod==0) {
			pButton->SetWindowText(_T("X"));
			pole_map[7] = 1;
			hod = hod + 1;
		}
		else {
			pButton->SetWindowText(_T("O"));
			pole_map[7] = 2;
			hod = hod + 1;
		}

	}
	winner();
}


void CKrestNolDlg::OnClicked8()
{
	CButton* pButton = (CButton*)GetDlgItem(IDC_8); // Замените IDC_MY_BUTTON на идентификатор вашей кнопки
	if (pole_map[8] == 0) {
		if (hod % 2 == 0 || hod == 0) {
			pButton->SetWindowText(_T("X"));
			pole_map[8] = 1;
			hod = hod + 1;
		}
		else {
			pButton->SetWindowText(_T("O"));
			pole_map[8] = 2;
			hod = hod + 1;
		}

	}
	winner();
}


void CKrestNolDlg::OnClicked9()
{
	CButton* pButton = (CButton*)GetDlgItem(IDC_9); // Замените IDC_MY_BUTTON на идентификатор вашей кнопки
	if (pole_map[9] == 0) {
		if (hod % 2 == 0 || hod == 0) {
			pButton->SetWindowText(_T("X"));
			pole_map[9] = 1;
			hod = hod + 1;
		}
		else {
			pButton->SetWindowText(_T("O"));
			pole_map[9] = 2;
			hod = hod + 1;
		}

	}
	winner();
}



void CKrestNolDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
}
