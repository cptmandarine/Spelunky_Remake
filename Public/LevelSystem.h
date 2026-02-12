#pragma once
#include "BaseLevel.h"

class CLevelSystem
{
public:
	CLevelSystem();
	~CLevelSystem();

private:
	CLevelSystem(const CLevelSystem& other) = delete;
	CLevelSystem& operator=(const CLevelSystem& other) = delete;

public:
	using SceneCreator = function<unique_ptr<CBaseLevel>()>;

public:
	bool Initialize();
	void Update(float fTimeDelta);
	void Late_Update(float fTimeDelta);
public:
	void Change_Scene();


private:
	void Create_Scene(LEVEL_ID eID);
	void Register_Scene();

	void Request_ChangeScene(const LEVEL_EVENT& evt);

private:
	CEventBus<LEVEL_EVENT>				  m_EventBus;

	unordered_map<LEVEL_ID, SceneCreator> m_SceneFactory;
	unique_ptr<CBaseLevel>				  m_pCurScene;

	optional<LEVEL_ID>					  m_PendingChange;

};

