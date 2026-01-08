#pragma once
#include "BaseLevel.h"

class CPlayer;

class CFirstLevel : public CBaseLevel
{
public:
	CFirstLevel(const LEVELCONTEXT& Context, const CEventBus<LEVEL_EVENT>& eventBus);
	~CFirstLevel();
public:
	// CBaseLevel을(를) 통해 상속됨
	bool Initialize() override;

	void Update(float fTimeDelta) override;
	void Late_Update(float fTimeDelta) override;

private:
	unique_ptr<CPlayer> m_Player;
};

