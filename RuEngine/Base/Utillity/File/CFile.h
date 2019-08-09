#ifndef CFILE_H__
#define CFILE_H__

#if _WIN64 || _WIN32
#else
#endif

#include <fstream>
#include <iostream>
#include <string>

namespace RuEngine
{

enum eFileMode
{
    Add = std::ios_base::app
    , End = std::ios_base::ate
    , Binary = std::ios_base::binary
    , In = std::ios_base::in
    , Out = std::ios_base::out
    , New = std::ios_base::trunc
};

//  typedef std::ios_base::openmode FileMode;
//  /// Seek to end before each write.
//  static const FileMode Add = std::ios_base::app;

//  /// Open and seek to end immediately after opening.
//  static const FileMode End = std::ios_base::ate;

//  /// Perform input and output in binary mode (as opposed to text mode).
//  /// This is probably not what you think it is; see
//  /// https://gcc.gnu.org/onlinedocs/libstdc++/manual/fstreams.html#std.io.filestreams.binary
//  static const FileMode Binary = std::ios_base::binary;

//  /// Open for input.  Default for @c ifstream and fstream.
//  static const FileMode In = std::ios_base::in;

//  /// Open for output.  Default for @c ofstream and fstream.
//  static const FileMode Out = std::ios_base::out;

//  /// Open for input.  Default for @c ofstream.
//  static const FileMode New = std::ios_base::trunc;
#if _WIN64 || _WIN32
class __declspec(dllexport) CFile
#else
class CFile
#endif
 {
 public:
     eFileMode m_mode = (eFileMode)(Out | New);

 private:
     std::fstream *mp_in = nullptr;

     char *msz_path = nullptr;

     std::string mstr_curline;

 public:
     CFile();
     CFile(const char *_path, eFileMode _mode = (eFileMode)(Out | New));
     CFile(CFile &_src);

 public:
     ~CFile();

 public:
     void Open(const char *_path = nullptr, eFileMode _mode = (eFileMode)(Out | New));

 public:
     void Write(const char *msg);

 public:
     const char * Read();
     const char * Readline();
     const char * ReadEndline();

 public:
     const char * GetPath() const;

 public:
     void Close();
     void Release();
};

} // namespace RuEngine


#endif