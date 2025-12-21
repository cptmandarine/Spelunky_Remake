#pragma once
#include "KeyboardInputSystem.h"

namespace WindowsUtils 
{
	inline float GetCurrentTimeStamp()
	{
		LARGE_INTEGER currentTime;
		QueryPerformanceCounter(&currentTime);
		return static_cast<float>(currentTime.QuadPart);
	}

	inline float GetCyclesPerMiliSeconed()
	{
		LARGE_INTEGER frequency;
		if (!QueryPerformanceFrequency(&frequency))
		{
			return 0;
		}
		return static_cast<float>(frequency.QuadPart);
	}

	inline bool Is_Press(unsigned char keyCode)
	{
		return ((::GetAsyncKeyState(keyCode) & 0x8000) != 0);

	}

	inline void BindInput(CKeyboardInputSystem& inputSys)
	{
		inputSys.SetInputButton(CKeyboardInputSystem::KeyCode::Down,	[]() {return Is_Press(VK_DOWN); });
		inputSys.SetInputButton(CKeyboardInputSystem::KeyCode::Up,		[]() {return Is_Press(VK_UP); });
		inputSys.SetInputButton(CKeyboardInputSystem::KeyCode::Right,	[]() {return Is_Press(VK_RIGHT); });
		inputSys.SetInputButton(CKeyboardInputSystem::KeyCode::Left,	[]() {return Is_Press(VK_LEFT); });
		inputSys.SetInputButton(CKeyboardInputSystem::KeyCode::Jump,	[]() {return Is_Press(VK_SPACE); });
	}
}