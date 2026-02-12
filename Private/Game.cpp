#include "pch.h"
#include "Game.h"
#include "Renderer.h"
#include "KeyboardInputSystem.h"
#include "LevelSystem.h"
#include "ServiceLocater.h"

CGame::CGame()
	: m_pInput(make_unique<CKeyboardInputSystem>())
	, m_pRenderer(make_unique<CRenderer>())
	, m_pLevelSystem(make_unique<CLevelSystem>())
{
}

CGame::~CGame()
{
	m_pRenderer.reset();
	m_pInput.reset();
	m_pLevelSystem.reset();

}


void CGame::Initialize(HWND hWnd, int width, int height)
{
	m_pRenderer->Initialize(hWnd, width, height);
	m_pLevelSystem->Initialize();

	//키보드 키 초기화
	_BindInputSystemFunc(*m_pInput);
	assert(m_pInput->Initialize() && "Input Binding False");

	//인풋 서비스 등록
	CServiceLocater::Register_Service(m_pInput.get());

	//리소스 로딩
}

void CGame::Release()
{
	CServiceLocater::Unregister_Service<IInputService>();
	m_pRenderer->Release();
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
	m_pInput->Update();
}

void CGame::Render()
{
	m_pRenderer->Draw();
}

void CGame::EndFrame()
{
	m_pLevelSystem->Change_Scene();
}

