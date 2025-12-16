#pragma once

class CGameObject
{
public:
	CGameObject() = default;
	virtual ~CGameObject() = default;
public:
	virtual bool Initialize() = 0 ;
	virtual void Update() = 0;
	virtual void Late_Update() = 0;
	virtual void Render(HDC hDC) = 0;

};

