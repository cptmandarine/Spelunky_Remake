#pragma once
#include "BaseLevel.h"

class CGame;

class CLevelSystem
{
public:
	CLevelSystem(CGame& game);
	~CLevelSystem();

	CLevelSystem(const CLevelSystem& other) = delete;
	CLevelSystem& operator=(const CLevelSystem& other) = delete;

public:
	enum class LEVEL_ID { MAIN, STAGE_1, STAGE_2};
	using SceneCreator = function<unique_ptr<CBaseLevel>()>;

public:
	bool Initialize();

	void Clear_Scene();
	void Update(float fTimeDelta);
	void Late_Update(float fTimeDelta);

private:
	void Register_Scene();
	bool Change_Scene(LEVEL_ID eID);

private:
	const CGame&								  m_Game;

	unordered_map<LEVEL_ID, SceneCreator> m_SceneFactory;
	unique_ptr<CBaseLevel>				  m_pCurScene;



};

