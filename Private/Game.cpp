#include "pch.h"
#include "Game.h"
#include "Renderer.h"
#include "LevelSystem.h"

CGame::CGame()
	: m_pRenderer(make_unique<CRenderer>())
	, m_pLevelSystem(make_unique<CLevelSystem>())
{
}

CGame::~CGame()
{
	m_pRenderer.reset();
	m_pLevelSystem.reset();

}

void CGame::Initialize(HWND hWnd, int width, int height)
{
	m_pRenderer->Initialize(hWnd, width, height);

	m_pLevelSystem->Initialize();
	m_pLevelSystem->Change_Scene(CLevelSystem::STAGE_MAIN);

}

void CGame::Update(float fTimeDelta)
{
	m_pLevelSystem->Update(fTimeDelta);
}

void CGame::Late_Update(float fTimeDelta)
{
	m_pLevelSystem->Late_Update(fTimeDelta);
}

void CGame::Render()
{
	m_pRenderer->Draw();
}

void CGame::Release()
{
}
