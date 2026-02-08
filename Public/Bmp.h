#pragma once
#include "Texture.h"

class CBmp : public CTexture
{
public:
	CBmp(HWND hWnd);
	virtual ~CBmp() = default;

public:
	// CTexture을(를) 통해 상속됨
	void Load_Image(wstring file) override;
	void Release() override;



	// CTexture을(를) 통해 상속됨
	void Render(HDC hDC) override;

private:
	HDC m_MemDC;
	HBITMAP m_PreMap;
	HBITMAP m_CurMap;

};