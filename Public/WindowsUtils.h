#pragma once

namespace WindowsUtils 
{
	inline long long GetCurrentTimeStamp()
	{
		QueryPerformanceFrequency();
	}
}