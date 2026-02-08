#pragma once
#include "GameContext.h"

class CRenderer;
class CLevelSystem;
class CKeyboardInputSystem;
class CTexture;

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
	//getter
	const IInputService& Get_InputService() const;

	void Initialize(HWND hWnd, int width, int height);
	void Release();

	void Update(float fTimeDelta);
	void Late_Update(float fTimeDelta);
	void Render();
	void EndFrame();

private:
	//����
	unique_ptr<CKeyboardInputSystem> m_pKeyBoardInput;
	const LEVELCONTEXT				 m_tLevelContext;

	//���� 
	unique_ptr<CLevelSystem>		 m_pLevelSystem;
	//���ҽ� 
				
	//����
	unique_ptr<CRenderer>			 m_pRenderer;

	//������Ÿ��
};

