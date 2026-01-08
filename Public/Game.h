#pragma once
#include "GameContext.h"

class CRenderer;
class CLevelSystem;
class CKeyboardInputSystem;

class CGame
{
public:
	CGame();
	~CGame();

private:
	CGame(const CGame& other) = delete;
	const CGame& operator=(const CGame& other) = delete;

public:
	function<void(CKeyboardInputSystem& inputSys)> _BindInputSystemFunc;

public:
	void Initialize(HWND hWnd, int width, int height);

	void Update(float fTimeDelta);
	void Late_Update(float fTimeDelta);
	void Render();

private:
	//상위
	unique_ptr<CKeyboardInputSystem> m_pKeyBoardInput;
	const LEVELCONTEXT				 m_tLevelContext;

	//하위 
	unique_ptr<CRenderer>			 m_pRenderer;
	unique_ptr<CLevelSystem>		 m_pLevelSystem;

};

