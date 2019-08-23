#ifndef CLEAKDETECT_H__
#define CLEAKDETECT_H__

#include "../../Include/Macro.h"

namespace Engine
{

#if _WIN64 || _WIN32
class __declspec(dllexport) CLeakdetect
#else
class CLeakdetect
#endif
{
public:
    static CLeakdetect* Instance;
private:
    CLeakdetect();
    ~CLeakdetect();

};
}
#endif;