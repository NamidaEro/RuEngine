#ifndef CLEAKDETECT_H__
#define CLEAKDETECT_H__
namespace Engine
{

#if _WIN64 || _WIN32
class __declspec(dllexport) CLeakdetect
#else
class CLeakdetect
#endif
{
public:
    CLeakdetect();
};
}
#endif;