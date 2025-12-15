#include "pch.h"
#include "LevelSystem.h"
#include "MainLevel.h"

void CLevelSystem::Initialize()
{
	Register_Scene();

}

bool CLevelSystem::Change_Scene(SCENETYPE eSceneType)
{
	if (m_pCurScene)
	{
		m_pCurScene->Clear_Scene();
		m_pCurScene.reset();
	}

	auto iter = m_SceneFactory.find(eSceneType);
	if (iter != m_SceneFactory.end())
	{
		m_pCurScene = (iter->second)(eSceneType);
		m_pCurScene->Initialize();
	}

	return (m_pCurScene != nullptr);
}


void CLevelSystem::Clear_Scene()
{
	//각종 씬 정보 삭제

}

void CLevelSystem::Update(float fTimeDelta)
{
	m_pCurScene->Update(fTimeDelta);
}

void CLevelSystem::Late_Update(float fTimeDelta)
{
	m_pCurScene->Late_Update(fTimeDelta);

}

void CLevelSystem::Register_Scene()
{
	m_SceneFactory[STAGE_MAIN] = [](SCENETYPE eType) { return make_unique<CMainLevel>(); };


}
