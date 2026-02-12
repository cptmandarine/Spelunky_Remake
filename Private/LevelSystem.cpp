#include "pch.h"
#include "LevelSystem.h"

#include "MainLevel.h"
#include "FirstLevel.h"


CLevelSystem::CLevelSystem()
{
}

CLevelSystem::~CLevelSystem()
{
	m_pCurScene->Release();
	m_pCurScene.reset();
}

bool CLevelSystem::Initialize()
{
	Register_Scene();
	Create_Scene(LEVEL_ID::MAIN);

	//µî·Ï.. publishÇÏ¸é Äã!
	m_EventBus.Subscribe([this](const LEVEL_EVENT& evt) { Request_ChangeScene(evt); });

	return true;
}


void CLevelSystem::Update(float fTimeDelta)
{
	m_pCurScene->Update(fTimeDelta);
}

void CLevelSystem::Late_Update(float fTimeDelta)
{
	m_pCurScene->Late_Update(fTimeDelta);
}

void CLevelSystem::Create_Scene(LEVEL_ID eID)
{
	auto iter = m_SceneFactory.find(eID);
	assert((iter != m_SceneFactory.end()) && "inValid Scene");
	m_pCurScene = iter->second();
}


void CLevelSystem::Register_Scene()
{
	m_SceneFactory[LEVEL_ID::MAIN]	  = [&](){ return make_unique<CMainLevel> (m_EventBus); };
	m_SceneFactory[LEVEL_ID::STAGE_1] = [&](){ return make_unique<CFirstLevel>(m_EventBus); };

}

void CLevelSystem::Change_Scene()
{
	if (!m_PendingChange) return;

	if (m_pCurScene)
	{
		m_pCurScene->Release();
		m_pCurScene.reset();
	}

	Create_Scene(*m_PendingChange);
	m_PendingChange.reset();
}

void CLevelSystem::Request_ChangeScene(const LEVEL_EVENT& evt)
{
	m_PendingChange = evt.nextLevel;
}
