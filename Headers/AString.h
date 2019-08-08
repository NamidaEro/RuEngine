#ifndef ASTRING_H__
#define ASTRING_H__

#include <iostream>

using namespace std;

namespace RuEngine
{
class AString
{
private:
    char* msz_str = nullptr;
    size_t mi_size = 0;
    size_t mi_len = 0;

public:
    AString();
    AString(const char* _str);
    AString(const AString& _str);

public:
    ~AString();

public:
    const char* c_str() const;

public:
    void SetString(const char* _str);
    AString& Append(const char* _str);

public:
    AString& operator= (const AString& _str);
    AString& operator+= (const AString& _str);
    friend std::ostream& operator<< (std::ostream& _os, const RuEngine::AString& _src)
    {
        _os << _src.c_str();
        return _os;
    }
    AString& operator<< (std::ostream& (*f)(std::ostream&))
    {
        cout << f;
        return *this;
    }

public:
    void Release();
};

} // namespace RuEngine

#endif