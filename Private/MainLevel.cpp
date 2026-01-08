#include "pch.h"
#include "MainLevel.h"
#include "InputService.h"
#include "Player.h"
#include "Game.h"

CMainLevel::CMainLevel(const LEVELCONTEXT& Context, const CEventBus<LEVEL_EVENT>& eventBus)
	: CBaseLevel(Context, eventBus)
	, m_Player(make_unique<CPlayer>())
{
}

CMainLevel::~CMainLevel()
{
	m_Player.reset();
}

bool CMainLevel::Initialize()
{
	cout << "씬 준비중.." << "\n";
	return m_Player->Initialize();
}


void CMainLevel::Update(float fTimeDelta)
{
	using KeyBoard = IInputService::KeyCode;

	if (m_Input.IsPressed(KeyBoard::Space))
	{
		cout << "점프 키를 누름\n";
	}
	else if (m_Input.IsPressing(KeyBoard::Space))
	{
		cout << "점프키를 누르는중\n";
	}
	else if (m_Input.IsReleased(KeyBoard::Space))
	{
		cout << "점프키를 뗌\n";
	}

	m_Player->Update();
}

void CMainLevel::Late_Update(float fTimeDelta)
{
	using KeyBoard = IInputService::KeyCode;


	if (m_Input.IsPressed(KeyBoard::Next))
	{
		LEVEL_EVENT evt = { LEVEL_ID::STAGE_1 };
		m_EventBus.Publish(evt);
	}
}
