#include "Renderer.h"

void CRenderer::Initialize(HWND hWnd, int width, int height)
{
	m_hWnd = hWnd;
	m_iWidth = width;
	m_iHeight = height;
}

void CRenderer::Release()
{
}

void CRenderer::Begin()
{
	m_hDC = GetDC(m_hWnd);
	m_hBackDC = CreateCompatibleDC(m_hDC);
	m_hBackBmp = CreateCompatibleBitmap(m_hDC, m_iWidth, m_iHeight);

	m_hOldBmp = static_cast<HBITMAP>(SelectObject(m_hBackDC, m_hBackBmp));

	Rectangle(m_hBackDC, 0, 0, m_iWidth, m_iHeight);
}

void CRenderer::Draw()
{
	//·»´õ Å×½ºÆ®
	//Rectangle(m_hBackDC, 220, 340, 260, 380);
}

void CRenderer::End()
{
	BitBlt(m_hDC, 0, 0, m_iWidth, m_iHeight, m_hBackDC, 0, 0, SRCCOPY);

	SelectObject(m_hBackDC, m_hOldBmp);

	DeleteObject(m_hBackBmp);
	DeleteDC(m_hBackDC);
	ReleaseDC(m_hWnd, m_hDC);

}
