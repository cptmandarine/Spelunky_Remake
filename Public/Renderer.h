#pragma once
#include "framework.h"

class CRenderer
{
public:
	CRenderer() = default;
	~CRenderer() = default;

public:
	void Initialize(HWND hWnd, int width, int height);
	void Release();

public:
	void Begin();
	void Draw();
	void End();

private:
	HWND m_hWnd;

	HDC m_hDC;
	HDC m_hBackDC;
	HBITMAP m_hBackBmp;
	HBITMAP m_hOldBmp;

	int  m_iWidth;
	int  m_iHeight;
};

