#pragma once
#include "BaseLevel.h"

class CPlayer;
class CGame;

class CMainLevel : public CBaseLevel
{
public:
	CMainLevel(const CEventBus<LEVEL_EVENT>& eventBus);
	~CMainLevel();
public:
	// CBaseLevel��(��) ���� ��ӵ�
	bool Initialize() override;

	void Update(float fTimeDelta) override;
	void Late_Update(float fTimeDelta) override;


protected:
	optional<LEVEL_ID> Evaluate_NextScene() override;

private:
	unique_ptr<CPlayer> m_Player;

};

