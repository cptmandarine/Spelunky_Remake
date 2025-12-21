#pragma once
#include "Controller.h"

class CPlayer;


class CPlayerController : public CController
{
public:
	CPlayerController(const IInputService& inputSys, CPlayer& player);
	// CInputController을(를) 통해 상속됨
	void Update(float fTimeDelta) override;

private:
	CPlayer& m_pPlayer;
};

