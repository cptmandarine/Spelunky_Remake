#pragma once
#include "BaseLevel.h"

class CPlayer;

class CMainLevel : public CBaseLevel
{
public:
	CMainLevel();
	~CMainLevel();
public:
	// CBaseLevel을(를) 통해 상속됨
	void Initialize() override;
	void Update(float fTimeDelta) override;
	void Late_Update(float fTimeDelta) override;

private:
	unique_ptr<CPlayer> m_Player;

};

