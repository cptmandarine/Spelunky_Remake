#pragma once
#include "framework.h"

class CRenderer;

class CGame
{
public:
	CGame() = default;
	~CGame();
private:
	CGame(const CGame& other) = delete;
	const CGame& operator=(const CGame& other) = delete;

public:
	void Initialize(HWND hWnd, int width, int height);

	void Update(float fTimeDelta);
	void Late_Update(float fTimeDelta);
	void Render();
	void Release();

private:
	//弊副 按眉甫 包府
	unique_ptr<CRenderer> m_pRenderer;
};

