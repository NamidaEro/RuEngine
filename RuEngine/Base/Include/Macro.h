#ifndef MACRO_H__
#define MACRO_H__
namespace Engine
{
#define NO_COPY(CLASSNAME)  \
        private:    \
        CLASSNAME(const CLASSNAME&); \
        CLASSNAME& operator = (const CLASSNAME&);

#define SINGLETON_DECLARE(CLASSNAME)    \
        NO_COPY(CLASSNAME)  \
        static CLASSNAME* mp_instance;  \
        public: \
        static CLASSNAME* GetInstance();    \
        static void DestroyInstance();

#define SINGLETON_IMPLEMENT(CLASSNAME)  \
        CLASSNAME* CLASSNAME::mp_instance = nullptr;    \
        CLASSNAME* CLASSNAME::GetInstance() \
        {   \
            if(nullptr == mp_instance)  \
            {   \
                mp_instance = new CLASSNAME;    \
            }   \
            return mp_instance; \
        }   \
        void CLASSNAME::DestroyInstance()   \
        {   \
            if(nullptr != mp_instance)  \
            {   \
                delete mp_instance; \
                mp_instance = nullptr;  \
            }   \
        }
}
#endif