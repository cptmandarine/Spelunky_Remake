#pragma once

class IInputService abstract
{
public:
	enum class KeyCode
	{
		Down,
		Up,
		Left,
		Right,
		Space,
		N,
		Last
	};

public:
	virtual bool Initialize() = 0; 
	virtual void SetInputButton(KeyCode eCode, function<bool()>) = 0;
	virtual void Update() = 0;

	virtual bool IsPressed (KeyCode eCode) const = 0;
	virtual bool IsPressing(KeyCode eCode) const = 0;
	virtual bool IsReleased(KeyCode eCode) const = 0;
};

using KeyBoard = IInputService::KeyCode;
