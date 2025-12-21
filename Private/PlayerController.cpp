#include "pch.h"
#include "PlayerController.h"
#include "InputService.h"

CPlayerController::CPlayerController(const IInputService& inputSys, CPlayer& player)
	: CController(inputSys)
	, m_pPlayer(player)
{
}

void CPlayerController::Update(float fTimeDelta)
{
	//m_pInput.Is_KeyDown()
}
