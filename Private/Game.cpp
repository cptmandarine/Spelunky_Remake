#include "Game.h"
#include "Renderer.h"

CGame::~CGame()
{
}

void CGame::Initialize(HWND hWnd, int width, int height)
{
	m_pRenderer = make_unique<CRenderer>();
	m_pRenderer->Initialize(hWnd, width, height);
}

void CGame::Update(float fTimeDelta)
{
}

void CGame::Late_Update(float fTimeDelta)
{
}

void CGame::Render()
{
	m_pRenderer->Draw();
}

void CGame::Release()
{
	m_pRenderer.reset();
}
