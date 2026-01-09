#pragma once
class CTexture abstract
{
public:
	CTexture() = default;
	virtual ~CTexture() = default;

public:
	virtual void Load_Image(wstring file) = 0;
	virtual void Release() = 0;



	virtual void Render(HDC hDC) = 0;
};

