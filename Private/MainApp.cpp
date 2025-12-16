#include "pch.h"
#include "MainApp.h"
#include "Game.h"
#include "Window.h"
#include "Renderer.h"

CMainApp::CMainApp()
    : m_pGame(make_unique<CGame>())
    , m_pWindow(make_unique<CWindow>())
    , m_fPrevTime(0.f)
    , m_fAccumulator(0.f)
{
}

CMainApp::~CMainApp()
{
    m_pGame.reset();
    m_pWindow.reset();
}

bool CMainApp::Initilize(HINSTANCE hInstance, int nCmdShow)
{
    if (!m_pWindow->Create(hInstance, W_WDITH, W_HEIGHT, L"Spelunky2"))
    {
        return false;
    }

    m_pWindow->Show(nCmdShow);

    m_pWindow->_CaculateCurrentFreqFunc = WindowsUtils::GetCyclesPerMiliSeconed;
    m_pWindow->_CaculateCurrentTimeFunc = WindowsUtils::GetCurrentTimeStamp;

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

    const float fFrequency = m_pWindow->_CaculateCurrentFreqFunc();
    m_fPrevTime = m_pWindow->_CaculateCurrentTimeFunc();

    const float FPS = 60.f;
    const float fixedDeltaTime = 1.f / FPS;


    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        //60FPS
        else
        {
            float fCurrentTime = m_pWindow->_CaculateCurrentTimeFunc();
            float fDeltaTime = (fCurrentTime - m_fPrevTime) / fFrequency;

            m_fPrevTime = fCurrentTime;
            m_fAccumulator += fDeltaTime;

            while (m_fAccumulator >= fixedDeltaTime)
            {
                m_pGame->Update(fixedDeltaTime);
                m_pGame->Late_Update(fixedDeltaTime);

                m_fAccumulator -= fixedDeltaTime;
            }
        }

        m_pGame->Render();

    }
    return static_cast<int>(msg.wParam);
}
