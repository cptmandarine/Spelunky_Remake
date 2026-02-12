#include "pch.h"
#include "BaseLevel.h"

CBaseLevel::CBaseLevel(const CEventBus<LEVEL_EVENT>& eventBus)
	: m_EventBus(eventBus)
{
}

void CBaseLevel::Release()
{
	cout << "¾À Á¤¸®..." << "\n";
}
