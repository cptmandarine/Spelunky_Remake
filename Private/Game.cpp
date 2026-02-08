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

const IInputService& CGame::Get_InptService() const
{
	return *m_pKeyBoardInput;
}

void CGame::Initialize(HWND hWnd, int width, int height)
{
	m_pRenderer->Initialize(hWnd, width, height);

	m_pLevelSystem->Initialize();

	//Ű���� Ű �ʱ�ȭ
	_BindInputSystemFunc(*m_pKeyBoardInput);
	assert(m_pKeyBoardInput->Initialize() && "Input Binding False");

	//���ҽ� �ε�
}

void CGame::Release()
{
}

void CGame::Update(float fTimeDelta)
{
	//���� ���� �����ٸ�..
	m_pLevelSystem->Update(fTimeDelta);

}

void CGame::Late_Update(float fTimeDelta)
{
	m_pLevelSystem->Late_Update(fTimeDelta);
	//�Է� ������Ʈ
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
