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
#include <cstring>
#include <functional>
#include <optional>
#include <typeinfo>
#include <typeindex>

#include <unordered_map>
#include <map>
#include <vector>
#include <array>


#ifdef _DEBUG
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 
#endif

#endif

using namespace std;
