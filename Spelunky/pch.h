#pragma once
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>

#include <assert.h>
#include <memory.h>
#include <memory>
#include <iostream>

#include <tchar.h>
#include <string>
#include <functional>

#include <unordered_map>
#include <map>
#include <vector>
#include <array>


#ifdef _DEBUG
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#endif

using namespace std;
