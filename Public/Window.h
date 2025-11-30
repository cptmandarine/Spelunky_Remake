#pragma once
#include "framework.h"

class CWindow
{
public:
	CWindow();
	~CWindow();
public:
	HWND Get_WindowHandle() { return m_hWnd; };

public:
	void Show(int cmdShow);
	bool Create(HINSTANCE hInstance, int width, int height, const wstring& title);

private:
	HWND		m_hWnd; 
	WNDCLASSEXW m_wcx;
};

