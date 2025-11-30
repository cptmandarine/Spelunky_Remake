#include "MainApp.h"
#include "Game.h"
#include "Window.h"

CMainApp::~CMainApp() = default;

bool CMainApp::Initilize(HINSTANCE hInstance, int nCmdShow)
{
    m_pWindow = make_unique<CWindow>();
    if (!m_pWindow->Create(hInstance, W_WDITH, W_HEIGHT, L"Spelunky2"))
    {
        return false;
    }
    m_pWindow->Show(nCmdShow);

    m_pGame = make_unique<CGame>();
    m_pGame->Initialize(m_pWindow->Get_WindowHandle(), W_WDITH, W_HEIGHT);
	return true;
}

void CMainApp::Release()
{
    m_pWindow.reset();
    m_pGame.reset();
}

int CMainApp::Run()
{
    MSG msg;

    // 기본 메시지 루프입니다:
    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        m_pGame->Render();

    }
    return static_cast<int>(msg.wParam);
}
