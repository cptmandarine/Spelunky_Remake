#include "pch.h"
#include "Bmp.h"

CBmp::CBmp(HWND hWnd)
	: CTexture()
{
	HDC hDC = GetDC(hWnd);
	m_MemDC = CreateCompatibleDC(hDC);
	ReleaseDC(hWnd, hDC);
}

void CBmp::Load_Image(wstring file)
{
	m_CurMap = (HBITMAP)LoadImage(NULL,
		file.c_str(),
		IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	m_PreMap = (HBITMAP)SelectObject(m_MemDC, m_CurMap);
}

void CBmp::Release()
{
	SelectObject(m_MemDC, m_PreMap);
	DeleteObject(m_CurMap);
	DeleteDC(m_MemDC);
}

void CBmp::Render(HDC hDC)
{
	GdiTransparentBlt(hDC,
		300 ,
		400 ,
		(int)64,
		(int)64,
		m_MemDC,
		(int)0 ,
		(int)0,
		(int)64,
		(int)64,
		RGB(255, 0, 255));
}
