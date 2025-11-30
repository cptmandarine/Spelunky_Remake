#pragma once
#include "framework.h"

class CGame;
class CWindow;

class CMainApp
{
public:
	CMainApp();
	~CMainApp();

public:
	bool Initilize(HINSTANCE hInstance, int nCmdShow);
	void Release();
public:
	int Run();
private:
	static const int W_WDITH = 1280;
	static const int W_HEIGHT = 720;

	unique_ptr<CWindow>   m_pWindow;
	unique_ptr<CGame>	  m_pGame;
};

