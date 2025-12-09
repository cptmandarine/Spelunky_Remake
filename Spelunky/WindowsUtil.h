#pragma once

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
}