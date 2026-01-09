#pragma once
class CGameObject;

class IPrototype abstract
{
public:
	virtual unique_ptr<CGameObject> Clone() = 0;
};

