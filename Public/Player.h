#pragma once
#include "GameObject.h"

class IInputService;

class CPlayer : public CGameObject
{
public:
	CPlayer();
	~CPlayer();

public:
	// CGameObject을(를) 통해 상속됨
	bool Initialize() override;
	void Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;


};

