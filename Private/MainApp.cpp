#include "MainApp.h"

bool CMainApp::Initilize(HINSTANCE hInstance, int nCmdShow)
{
    m_pWindow = make_unique<CWindow>();

    if (!m_pWindow->Create(hInstance, W_WDITH, W_HEIGHT, L"Tetris"))
    {
        return false;
    }
    m_pWindow->Show(nCmdShow);

    m_pRenderer = make_unique<CRenderer>();
    m_pRenderer->Initialize(m_pWindow->Get_WindowHandle(), W_WDITH, W_HEIGHT);
	return true;
}

void CMainApp::Release()
{
	m_pRenderer.reset();
    m_pWindow.reset();
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

        m_pRenderer->Begin();
        m_pRenderer->Draw();
        m_pRenderer->End();

    }
    return static_cast<int>(msg.wParam);
}
