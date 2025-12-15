#pragma once
#include "GameObject.h"

class CPlayer : public CGameObject
{

public:
	// CGameObject을(를) 통해 상속됨
	void Initialize() override;
	void Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;

};

