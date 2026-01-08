#include "pch.h"
#include "BaseLevel.h"

CBaseLevel::CBaseLevel(const LEVELCONTEXT& tLevelContext, const CEventBus<LEVEL_EVENT>& eventBus)
	: m_Input(tLevelContext.inputService)
	, m_EventBus(eventBus)
{
}

void CBaseLevel::Release()
{
	cout << "¾À Á¤¸®..." << "\n";
}
