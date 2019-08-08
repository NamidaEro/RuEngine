#include "AString.h"

#include <string.h>

using namespace RuEngine;

AString::AString()
{

}

AString::AString(const char* _str)
{
    SetString(_str);
}

AString::AString(const AString& _str)
{
    SetString(_str.c_str());
}

AString::~AString()
{
    Release();
}

const char* AString::c_str() const
{
    return msz_str;
}

void AString::SetString(const char* _str)
{
    Release();

    size_t tmpi_len = strnlen(_str, 255);
    msz_str = new char[tmpi_len + 1];
    memset(msz_str, 0, (sizeof(char) * tmpi_len) + 1);
#if _WIN64 || _WIN32
	memcpy_s(
		msz_str, (sizeof(char) * tmpi_len) + 1
		, _str, (sizeof(char) * tmpi_len) + 1);
#else
    memcpy(msz_str, _str, (sizeof(char) * tmpi_len) + 1);
#endif

    mi_len = strnlen(_str, 255);
    mi_size = tmpi_len + 1;
}

AString& AString::Append(const char* _str)
{
    size_t tmpi_len = strnlen(_str, 255);
    size_t tmpi_total = mi_len + tmpi_len;

    char* tmpsz_newstr = new char[tmpi_total + 1];
    memset(tmpsz_newstr, 0, (sizeof(char) * tmpi_total) + 1);
#if _WIN64 || _WIN32
	strcpy_s(tmpsz_newstr, mi_len, msz_str);
	strcat_s(tmpsz_newstr, tmpi_len, _str);
#else
	strncpy(tmpsz_newstr, msz_str, mi_len);
	strncat(tmpsz_newstr, _str, tmpi_len);
#endif
    

    Release();

    msz_str = tmpsz_newstr;

    return *this;
}

AString & AString::operator=(const AString & _str)
{
    SetString(_str.c_str());
    return *this;
}

AString & AString::operator+=(const AString & _str)
{
    return Append(_str.c_str());
}

void AString::Release()
{
    if(nullptr != msz_str)
    {
        delete msz_str;
    }
}