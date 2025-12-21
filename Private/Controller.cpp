#include "pch.h"
#include "Controller.h"

CController::CController(const IInputService& inputSys)
	: m_pInput(inputSys)
{
}
