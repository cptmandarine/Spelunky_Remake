#include "pch.h"
#include "Player.h"
#include "InputService.h"
#include "ServiceLocater.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

bool CPlayer::Initialize()
{
	cout << " 플레이어 등장 " << "\n";

	auto leftMove  = [&](CGameObject& obj){ obj.Move(-1, 0); };
	auto rightMove = [&](CGameObject& obj){ obj.Move(1, 0); };
	
	m_KeyBindings[static_cast<int>(KeyBoard::Left)]  = leftMove;
	m_KeyBindings[static_cast<int>(KeyBoard::Right)] = rightMove;

	return true;
}

void CPlayer::Update()
{
	auto& Input = CServiceLocater::Get_Service<IInputService>();

	
	if(Input.IsPressed(KeyBoard::Left) || Input.IsPressing(KeyBoard::Left))  m_KeyBindings[static_cast<int>(KeyBoard::Left)](*this);
	if(Input.IsPressed(KeyBoard::Right) || Input.IsPressing(KeyBoard::Right)) m_KeyBindings[static_cast<int>(KeyBoard::Right)](*this);
	
	//cout << " 플레이어 업데이트 " << "\n";
	//각종 소유한 컴포넌트를 업데이트 해주면 될 거 같고,,

}

void CPlayer::Late_Update()
{
}

void CPlayer::Render(HDC hDC)
{
}
