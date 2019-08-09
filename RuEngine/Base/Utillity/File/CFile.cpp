#include "CFile.h"

#include <string.h>

using namespace RuEngine;

CFile::CFile()
{

}

CFile::CFile(const char* _path, FileMode _mode)
{
    if(msz_path != nullptr)
    {
        delete msz_path;
    }

    memcpy(msz_path, _path, sizeof(char) * strlen(_path));

    Close();
    Open(msz_path, _mode);
}

CFile::CFile(CFile& _src)
{
    if(msz_path != nullptr)
    {
        delete msz_path;
    }

    memcpy(msz_path, _src.GetPath(), sizeof(char) * strlen(_src.GetPath()));

    Close();
    Open(msz_path, _src.m_mode);
}

CFile::~CFile()
{
    Close();
}

void CFile::Open(const char* _path, FileMode _mode)
{
    if(mp_in != nullptr)
    {
        mp_in->close();
        delete mp_in;
    }

    if(_path == nullptr)
    {
         mp_in = new std::ofstream(msz_path, _mode);
    }
    else
    {
         mp_in = new std::ofstream(_path, _mode);
    }

    m_mode = _mode;
}

void CFile::Write(const char* msg)
{
    *mp_in << msg;
}

const char* CFile::Read()
{
    return nullptr;
}

const char* CFile::Readline()
{
    return nullptr;
}

const char* CFile::ReadEndline()
{
    return nullptr;
}

const char* CFile::GetPath() const
{
    return msz_path;
}

void CFile::Close()
{
    mp_in->close();
}

void CFile::Release()
{
    if(mp_in != nullptr)
    {
        delete mp_in;
    }

    if(msz_path != nullptr)
    {
        delete msz_path;
    }
}