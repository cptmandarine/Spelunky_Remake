#include "pch.h"
#include "FirstLevel.h"
#include "InputService.h"
#include "Player.h"

CFirstLevel::CFirstLevel(const LEVELCONTEXT& Context, const CEventBus<LEVEL_EVENT>& eventBus)
	: CBaseLevel(Context, eventBus)
	, m_Player(make_unique<CPlayer>())
{
}

CFirstLevel::~CFirstLevel()
{
	m_Player.reset();
}

bool CFirstLevel::Initialize()
{
	cout << "씬 준비중.." << "\n";
	return m_Player->Initialize();
}


void CFirstLevel::Update(float fTimeDelta)
{
	using KeyBoard = IInputService::KeyCode;

	m_Player->Update();
}

void CFirstLevel::Late_Update(float fTimeDelta)
{
	using KeyBoard = IInputService::KeyCode;
	if (m_Input.IsPressed(KeyBoard::Next))
	{
		cout << "전환이 완료된 씬\n";
	}

}

optional<LEVEL_ID> CFirstLevel::Evaluate_NextScene()
{
	return nullopt;
}

