#include "pch.h"
#include "Player.h"
#include "InputService.h"


CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

bool CPlayer::Initialize()
{
	cout << " 플레이어 등장 " << "\n";
	return true;
}

void CPlayer::Update()
{
	//cout << " 플레이어 업데이트 " << "\n";
	//각종 소유한 컴포넌트를 업데이트 해주면 될 거 같고,,

}

void CPlayer::Late_Update()
{
}

void CPlayer::Render(HDC hDC)
{
}
