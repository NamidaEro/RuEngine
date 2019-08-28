#ifndef CLEAKDETECT_H__
#define CLEAKDETECT_H__

#include "../../Include/Macro.h"
#include "../../Include/Defines.h"

#include <iostream>
#include <map>

using namespace std;

namespace Engine
{

typedef struct tagAllocInfo
{
    char szfileName[512];
    int line;
    unsigned int length;
}ALLOCINFO;

typedef std::map<void*, ALLOCINFO>  MAP_ALLOCINFO;

#if _WIN64 || _WIN32
class __declspec(dllexport) CLeakdetect
#else
class CLeakdetect
#endif
{
    SINGLETON_DECLARE(CLeakdetect)

public:
    MAP_ALLOCINFO m_info;
    int mi_allocCnt = 0;

private:
    CLeakdetect();
    ~CLeakdetect();

public:
    void* AllocPtr(size_t size, const char* _szfileName, const int& _iLine);
    void FreePtr(void* _ptr);

    void Release();
};

CLeakdetect* LeakDetectStart()
{
	return CLeakdetect::GetInstance();
}

void LeakDetectEnd()
{
	CLeakdetect::DestroyInstance();
}
}

void* operator new(size_t sz, const char* filename, int line)
{
	return Engine::CLeakdetect::GetInstance()->AllocPtr(sz, filename, line);
}

void operator delete(void *p)
{
	Engine::CLeakdetect::GetInstance()->FreePtr(p);
}

void* operator new[](size_t size, const char* filename, int line)
{
	return operator new(size, filename, line);
}

void operator delete[](void* p)
{
	operator delete(p);
}

#ifdef _DEBUG
#define new new(__FILE__, __LINE__)
#endif // _DEBUG

#endif