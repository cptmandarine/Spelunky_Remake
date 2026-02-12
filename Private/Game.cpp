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

const IInputService& CGame::Get_InputService() const
{
	return *m_pKeyBoardInput;
}

void CGame::Initialize(HWND hWnd, int width, int height)
{
	m_pRenderer->Initialize(hWnd, width, height);
	m_pLevelSystem->Initialize();

	//≈∞∫∏µÂ ≈∞ √ ±‚»≠
	_BindInputSystemFunc(*m_pInput);
	assert(m_pInput->Initialize() && "Input Binding False");

	//¿Œ«≤ º≠∫ÒΩ∫ µÓ∑œ
	CServiceLocater::Register_Service(m_pInput.get());
}

void CGame::Release()
{
	CServiceLocater::Unregister_Service<IInputService>();
	m_pRenderer->Release();
}

void CGame::Update(float fTimeDelta)
{
	//ÔøΩÔøΩÔøΩÔøΩ ÔøΩÔøΩÔøΩÔøΩ ÔøΩÔøΩÔøΩÔøΩÔøΩŸ∏ÔøΩ..
	m_pLevelSystem->Update(fTimeDelta);

}

void CGame::Late_Update(float fTimeDelta)
{
	m_pLevelSystem->Late_Update(fTimeDelta);
	//¿‘∑¬ æ˜µ•¿Ã∆Æ
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