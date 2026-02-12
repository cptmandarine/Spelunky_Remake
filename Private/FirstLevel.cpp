#include "pch.h"
#include "FirstLevel.h"
#include "ServiceLocater.h"
#include "Player.h"

CFirstLevel::CFirstLevel(const CEventBus<LEVEL_EVENT>& eventBus)
	: CBaseLevel(eventBus)
	, m_Player(make_unique<CPlayer>())
{
}

CFirstLevel::~CFirstLevel()
{
	m_Player.reset();
}

bool CFirstLevel::Initialize()
{
	cout << "¾À ÁØºñÁß.." << "\n";
	return m_Player->Initialize();
}


void CFirstLevel::Update(float fTimeDelta)
{
	auto& Input = CServiceLocater::Get_Service<IInputService>();

	m_Player->Update();
	if (Input.IsPressed(KeyBoard::N))
	{
		cout << "¾À ÀüÈ¯ ¿Ï·áµÊ" << "\n";
	}
}

void CFirstLevel::Late_Update(float fTimeDelta)
{

}

optional<LEVEL_ID> CFirstLevel::Evaluate_NextScene()
{
	return nullopt;
}

