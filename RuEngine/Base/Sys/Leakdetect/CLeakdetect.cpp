#include "CLeakdetect.h"

#if _WIN64 || _WIN32
#include <Windows.h>
#else
#include <string.h>
#endif

using namespace Engine;

SINGLETON_IMPLEMENT(CLeakdetect)

CLeakdetect::CLeakdetect()
{

}

CLeakdetect::~CLeakdetect()
{
    Release();
}

void* CLeakdetect::AllocPtr(size_t size, const char* _szfileName, const int& _iLine)
{
    ALLOCINFO tmp_info;
#if _WIN64 || _WIN32
    int len = (int)strnlen_s(_szfileName, SIZE_MAX_FILENAME);
    strcpy_s(tmp_info.szfileName, len + 1, _szfileName);
    tmp_info.line = _iLine;
#else
    int len = strnlen(_szfileName, SIZE_MAX_FILENAME);
    strncpy(tmp_info.szfileName, _szfileName, len + 1);
    tmp_info.line = _iLine;
#endif

    void* pfs = malloc(size);

    if(NULL == pfs) {} // error

    tmp_info.length = (unsigned int)size;
    CLeakdetect::GetInstance()->m_info.insert(make_pair(pfs, tmp_info));
    CLeakdetect::GetInstance()->mi_allocCnt++;
}

void CLeakdetect::FreePtr(void *_ptr)
{
    for (MAP_ALLOCINFO::iterator iter = CLeakdetect::GetInstance()->m_info.begin()
        ; iter != CLeakdetect::GetInstance()->m_info.end()
        ; ++iter)
    {
        if ((*iter).first == _ptr)
        {
            CLeakdetect::GetInstance()->m_info.erase(iter);
            break;
        }
    }

    free(_ptr);
    CLeakdetect::GetInstance()->mi_allocCnt--;
}

void CLeakdetect::Release()
{
    char buffer[512];
	int a = 0;
	for (MAP_ALLOCINFO::iterator iter = m_info.begin()
		; iter != m_info.end()
		; ++iter)
	{
		int line = (*iter).second.line;
		unsigned int size = (*iter).second.length;

#if _WIN64 || _WIN32
		snprintf(
			buffer
			, sizeof(buffer)
			, "file: %s : (line %d) / size: %d bytes / add: 0x%p\n"
			, (*iter).second.szfilename
			, line
			, size
			, (*iter).first);

		OutputDebugStringA(buffer);
#else
		sprintf(
			buffer
			, "file: %s : (line %d) / size: %d bytes / add: %p\n"
			, (*iter).second.szfileName
			, line
			, size
			, (*iter).first);

		cout << buffer << endl;
#endif // _WIN32
}