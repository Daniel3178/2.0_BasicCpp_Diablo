#pragma once

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define DBG_NEW
#endif // _DEBUG

#ifdef _DEBUG
#define new DBG_NEW
#endif // _DEBUG
#pragma once
