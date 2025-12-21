#pragma once
#include "InputService.h"

class CKeyboardInputSystem : public IInputService
{
public:
	CKeyboardInputSystem();
	~CKeyboardInputSystem() = default;

	CKeyboardInputSystem(const CKeyboardInputSystem& other) = delete;
	CKeyboardInputSystem& operator=(const CKeyboardInputSystem& ohter) = delete;

public:
	bool Initialize();
	void Update();

public:
	void SetInputButton(KeyCode eCode, function<bool()>);

	// IInputServcie을(를) 통해 상속됨
	bool IsPressed(KeyCode eCode) const override;
	bool IsPressing(KeyCode eCode) const override;
	bool IsReleased(KeyCode eCode) const override;

private:

	array<bool, static_cast<size_t>(KeyCode::Last)>			    m_mapPreKey;
	array<function<bool()>, static_cast<size_t>(KeyCode::Last)> m_mapCurKey;

};

