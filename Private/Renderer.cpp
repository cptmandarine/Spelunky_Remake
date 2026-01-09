#include "pch.h"
#include "Renderer.h"
#include "Bmp.h"

CRenderer::CRenderer()
{
}

CRenderer::~CRenderer()
{
}

void CRenderer::Initialize(HWND hWnd, int width, int height)
{
	m_hWnd = hWnd;
	m_iWidth = width;
	m_iHeight = height;

	m_hDC = GetDC(m_hWnd);
	m_hBackDC = CreateCompatibleDC(m_hDC);
	m_hBackBmp = CreateCompatibleBitmap(m_hDC, m_iWidth, m_iHeight);

	m_hOldBmp = static_cast<HBITMAP>(SelectObject(m_hBackDC, m_hBackBmp));

	m_testTex = new CBmp(hWnd);
	m_testTex->Load_Image(L"../Resource/Assets/player.bmp");
}

void CRenderer::Release()
{
	delete m_testTex;
}

void CRenderer::Begin()
{
}

void CRenderer::Draw()
{
	PatBlt(m_hBackDC, 0, 0, m_iWidth, m_iHeight, BLACKNESS);

	//오브젝트들을 레이어별로 렌더
	m_testTex->Render(m_hBackDC);


	BitBlt(m_hDC, 0, 0, m_iWidth, m_iHeight, m_hBackDC, 0, 0, SRCCOPY);

}

void CRenderer::End()
{
	BitBlt(m_hDC, 0, 0, m_iWidth, m_iHeight, m_hBackDC, 0, 0, SRCCOPY);

	SelectObject(m_hBackDC, m_hOldBmp);

	DeleteObject(m_hBackBmp);
	DeleteDC(m_hBackDC);
	ReleaseDC(m_hWnd, m_hDC);
}
