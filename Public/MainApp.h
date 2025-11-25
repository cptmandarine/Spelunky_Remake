#pragma once
#include "framework.h"
#include "Window.h"
#include "Renderer.h"

class CMainApp
{
public:
	CMainApp() = default;
	~CMainApp() = default;

public:
	bool Initilize(HINSTANCE hInstance, int nCmdShow);
	void Release();
public:
	int Run();
private:
	static const int W_WDITH = 480;
	static const int W_HEIGHT = 720;

	unique_ptr<CWindow>   m_pWindow;
	unique_ptr<CRenderer> m_pRenderer;

};

