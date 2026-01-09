#include "pch.h"
#include "Game.h"
#include "Renderer.h"
#include "KeyboardInputSystem.h"
#include "LevelSystem.h"

CGame::CGame()
	: m_pKeyBoardInput(make_unique<CKeyboardInputSystem>())
	, m_tLevelContext{ *m_pKeyBoardInput }
	, m_pRenderer(make_unique<CRenderer>())
	, m_pLevelSystem(make_unique<CLevelSystem>(m_tLevelContext))
{
}

CGame::~CGame()
{
	m_pRenderer->Release();

	m_pRenderer.reset();
	m_pKeyBoardInput.reset();
	m_pLevelSystem.reset();

}


void CGame::Initialize(HWND hWnd, int width, int height)
{
	m_pRenderer->Initialize(hWnd, width, height);

	m_pLevelSystem->Initialize();

	//키보드 키 초기화
	_BindInputSystemFunc(*m_pKeyBoardInput);
	assert(m_pKeyBoardInput->Initialize() && "Input Binding False");

	//리소스 로딩
}

void CGame::Release()
{
}

void CGame::Update(float fTimeDelta)
{
	//현재 씬이 끝났다면..
	m_pLevelSystem->Update(fTimeDelta);

}

void CGame::Late_Update(float fTimeDelta)
{
	m_pLevelSystem->Late_Update(fTimeDelta);
	//입력 업데이트
	m_pKeyBoardInput->Update();
}

void CGame::Render()
{
	m_pRenderer->Draw();
}

void CGame::EndFrame()
{
	m_pLevelSystem->Change_Scene();
}

