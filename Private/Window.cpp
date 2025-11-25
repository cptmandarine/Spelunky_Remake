#include "Window.h"


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}


CWindow::CWindow()
	: m_hWnd(nullptr)
{
	ZeroMemory(&m_wcx, sizeof(m_wcx));
}

CWindow::~CWindow()
{
	if (m_hWnd)
	{
		DestroyWindow(m_hWnd);
		m_hWnd = nullptr;
	}
}

void CWindow::Show(int cmdShow)
{
    ShowWindow(m_hWnd, cmdShow);
    UpdateWindow(m_hWnd);
}

bool CWindow::Create(HINSTANCE hInstance, int width, int height, const wstring& title)
{
    m_wcx.cbSize = sizeof(WNDCLASSEXW);
    m_wcx.style = CS_HREDRAW | CS_VREDRAW;
    m_wcx.lpfnWndProc = WndProc;
    m_wcx.cbClsExtra = 0;
    m_wcx.cbWndExtra = 0;
    m_wcx.hInstance = hInstance;
    m_wcx.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    m_wcx.hCursor = LoadCursor(nullptr, IDC_ARROW);
    m_wcx.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    m_wcx.lpszMenuName = nullptr;
    m_wcx.lpszClassName = title.c_str();
    m_wcx.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

    if (!RegisterClassExW(&m_wcx))
        return false;

    m_hWnd = CreateWindowW(
        title.c_str(),
        title.c_str(),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        width, height,
        nullptr, nullptr,
        hInstance,
        nullptr);

    return m_hWnd != nullptr;
}
