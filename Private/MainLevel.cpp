#include "pch.h"
#include "MainLevel.h"
#include "Player.h"
#include "Game.h"
#include "ServiceLocater.h"

CMainLevel::CMainLevel(const CEventBus<LEVEL_EVENT>& eventBus)
	: CBaseLevel(eventBus)
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
	auto& Input = CServiceLocater::Get_Service<IInputService>();
	using KeyBoard = IInputService::KeyCode;

	if (Input.IsPressed(KeyBoard::Space))
	{
		cout << "점프 키를 누름\n";
	}
	else if (Input.IsPressing(KeyBoard::Space))
	{
		cout << "점프키를 누르는중\n";
	}
	else if (Input.IsReleased(KeyBoard::Space))
	{
		cout << "점프키를 뗌\n";
	}

	m_Player->Update();
}

void CMainLevel::Late_Update(float fTimeDelta)
{
	if (auto next = Evaluate_NextScene())
	{
		LEVEL_EVENT evt = {*next};
		m_EventBus.Publish(evt);
	}

}

optional<LEVEL_ID> CMainLevel::Evaluate_NextScene()
{
	auto& Input = CServiceLocater::Get_Service<IInputService>();
	using KeyBoard = IInputService::KeyCode;

	if (Input.IsPressed(KeyBoard::N))
	{
		return LEVEL_ID::STAGE_1;
	}

	return nullopt;
}
