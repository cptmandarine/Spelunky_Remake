#pragma once
#include "BaseLevel.h"

class CLevelSystem
{
public:
	enum SCENETYPE { STAGE_MAIN, STAGE_0, STAGE_1, STAGE_2 };
	using SceneCreator = function<unique_ptr<CBaseLevel>(SCENETYPE)>;

public:
	CLevelSystem() = default;
	~CLevelSystem() = default;


public:
	void Initialize();
	bool Change_Scene(SCENETYPE eSceneType);
	void Clear_Scene();

	void Update(float fTimeDelta);
	void Late_Update(float fTimeDelta);

private:
	void Register_Scene();

private:
	unordered_map<SCENETYPE, SceneCreator> m_SceneFactory;
	unique_ptr<CBaseLevel> m_pCurScene;

};

