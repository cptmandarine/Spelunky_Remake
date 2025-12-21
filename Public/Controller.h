#pragma once
//외부 입력이라던가 상태변화를 감지하여 적용해준다.
class IInputService;

class CController abstract
{
public:
	CController(const IInputService& inputSys);
	~CController() = default;

public:
	virtual void Update(float fTimeDelta) = 0;

protected:
	const IInputService& m_pInput;
};

