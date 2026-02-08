#pragma once
class CRenderer;
class CLevelSystem;
class CKeyboardInputSystem;
class IInputService;

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

public:
	void Initialize(HWND hWnd, int width, int height);

	void Update(float fTimeDelta);
	void Late_Update(float fTimeDelta);
	void Render();

private:
	unique_ptr<CRenderer>			 m_pRenderer;

	unique_ptr<CKeyboardInputSystem> m_pKeyBoardInput;
	unique_ptr<CLevelSystem>		 m_pLevelSystem;

};

