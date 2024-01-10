
// KrestNolDlg.h: файл заголовка
//
#include <map>
#pragma once


// Диалоговое окно CKrestNolDlg
class CKrestNolDlg : public CDialogEx
{
// Создание
public:
	CKrestNolDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KRESTNOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	int hod;
	bool check;
	std::map<int, int> pole_map = {
	{1,0},
	{2,0},
	{3,0},
	{4,0},
	{5,0},
	{6,0},
	{7,0},
	{8,0},
	{9,0}
	};

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClicked3();
//	afx_msg void OnBnClicked1();
	afx_msg void OnClicked1();
	afx_msg void OnClicked2();
	afx_msg void OnClicked3();
	afx_msg void OnClicked4();
	afx_msg void OnClicked5();
	afx_msg void OnClicked6();
	afx_msg void OnClicked7();
	afx_msg void OnClicked8();
	afx_msg void OnClicked9();
	afx_msg void winner();
	afx_msg void OnBnClickedButton1();
};
