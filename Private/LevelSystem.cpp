#include "pch.h"
#include "Game.h"
#include "LevelSystem.h"

#include "InputService.h"

#include "MainLevel.h"
#include "FirstLevel.h"


CLevelSystem::CLevelSystem(CGame& game)
	: m_Game(game)
{
}

CLevelSystem::~CLevelSystem()
{
}

bool CLevelSystem::Initialize()
{
	Register_Scene();
	
	return Change_Scene(LEVEL_ID::MAIN);
}

void CLevelSystem::Clear_Scene()
{
	//각종 씬 정보 삭제

}

void CLevelSystem::Update(float fTimeDelta)
{
	//현재 씬이 끝났을 때,,
	//이벤트를 제공받고 처리
	m_pCurScene->Update(fTimeDelta);
}

void CLevelSystem::Late_Update(float fTimeDelta)
{
	m_pCurScene->Late_Update(fTimeDelta);
	if (m_pCurScene->Is_End())
	{
		cout << "씬 전환 중.. ";
		Change_Scene(LEVEL_ID::STAGE_1);
	}
}

bool CLevelSystem::Change_Scene(LEVEL_ID eID)
{
	if (m_pCurScene)
	{
		m_pCurScene->Clear_Scene();
		m_pCurScene.reset();
	}
	auto iter = m_SceneFactory.find(eID);
	assert((iter != m_SceneFactory.end()) && "unChanged Scene");

	m_pCurScene = iter->second();

	return m_pCurScene->Initialize();
}

void CLevelSystem::Register_Scene()
{
	m_SceneFactory[LEVEL_ID::MAIN]	  = [&](){ return make_unique<CMainLevel>(m_Game.Get_InptService()); };
	m_SceneFactory[LEVEL_ID::STAGE_1] = [&](){ return make_unique<CFirstLevel>(m_Game.Get_InptService()); };

}
