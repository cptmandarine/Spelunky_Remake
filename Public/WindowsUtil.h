#pragma once
#include "InputService.h"

namespace WindowsUtils 
{
	inline float GetCurrentTimeStamp()
	{
		LARGE_INTEGER currentTime;
		QueryPerformanceCounter(&currentTime);
		return static_cast<float>(currentTime.QuadPart);
	}

	inline float GetCyclesPerMillisecond()
	{
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);
		return static_cast<float>(frequency.QuadPart);
	}

	inline bool Is_Press(unsigned char keyCode)
	{
		return ((::GetAsyncKeyState(keyCode) & 0x8000) != 0);
	}

	inline void BindInput(IInputService& inputSys)
	{
		inputSys.SetInputButton(IInputService::KeyCode::Down,	[]() {return Is_Press(VK_DOWN); });
		inputSys.SetInputButton(IInputService::KeyCode::Up,		[]() {return Is_Press(VK_UP); });
		inputSys.SetInputButton(IInputService::KeyCode::Right,	[]() {return Is_Press(VK_RIGHT); });
		inputSys.SetInputButton(IInputService::KeyCode::Left,	[]() {return Is_Press(VK_LEFT); });
		inputSys.SetInputButton(IInputService::KeyCode::Space,	[]() {return Is_Press(VK_SPACE); });
		inputSys.SetInputButton(IInputService::KeyCode::N,		[]() {return Is_Press('N'); });
	}
}