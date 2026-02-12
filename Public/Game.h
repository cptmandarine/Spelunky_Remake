#pragma once
class CRenderer;
class CLevelSystem;
class IInputService;
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
	function<void(IInputService& inputSys)> _BindInputSystemFunc;

public:
	void Initialize(HWND hWnd, int width, int height);
	void Release();

	void Update(float fTimeDelta);
	void Late_Update(float fTimeDelta);
	void Render();
	void EndFrame();

private:
	//상위
	unique_ptr<IInputService>		 m_pInput;
	unique_ptr<CRenderer>			 m_pRenderer;

	//하위 
	unique_ptr<CLevelSystem>		 m_pLevelSystem;
	//리소스 

};

