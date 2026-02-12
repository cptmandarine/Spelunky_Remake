#pragma once
class CGameObject;

class CCommand
{
public:
	CCommand() = default;
	virtual ~CCommand() = default;

public:
	virtual void Execute(CGameObject& obj) = 0;

};

class CMoveCommand : public CCommand
{
public:
	CMoveCommand() = default;
	virtual ~CMoveCommand() = default;

public:
	// CCommand을(를) 통해 상속됨
	void Execute(CGameObject& obj) override;
};