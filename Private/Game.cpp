#include "pch.h"
#include "Game.h"
#include "Renderer.h"
#include "KeyboardInputSystem.h"

#include "LevelSystem.h"
#include "MainLevel.h"

CGame::CGame()
	: m_pRenderer(make_unique<CRenderer>())
	, m_pKeyBoardInput(make_unique<CKeyboardInputSystem>())
	, m_pLevelSystem(make_unique<CLevelSystem>(*this))
{
}

CGame::~CGame()
{
	m_pRenderer.reset();
	m_pKeyBoardInput.reset();
	m_pLevelSystem.reset();

}

const IInputService& CGame::Get_InptService() const
{
	return *m_pKeyBoardInput;
}

void CGame::Initialize(HWND hWnd, int width, int height)
{
	m_pRenderer->Initialize(hWnd, width, height);

	m_pLevelSystem->Initialize();

	_BindInputSystemFunc(*m_pKeyBoardInput);
	assert(m_pKeyBoardInput->Initialize() && "Input Binding False");

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

