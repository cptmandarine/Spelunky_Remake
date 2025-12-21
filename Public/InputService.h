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
		Jump,
		Next,
		Last
	};

public:
	virtual bool IsPressed(KeyCode eCode) const = 0;
	virtual bool IsPressing(KeyCode eCode) const = 0;
	virtual bool IsReleased(KeyCode eCode) const = 0;
};

