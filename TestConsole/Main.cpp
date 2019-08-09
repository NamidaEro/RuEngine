#include <iostream>

#if _WIN64 | _WIN32
#include "AString.h"
#include "CTCPConnect.h"
#include "CFile.h"
#else
#include "../Headers/CFile.h"
#endif

using namespace std;
using namespace RuEngine;

int main(int argc, char** argv)
{
	CFile file;
	file.Open("/home/ubuntu/git/RuEngine/TestConsole/test.txt", (RuEngine::eFileMode)(Add | Out));

	file.Write(argv[1]);
	
	//system("pause");
	return 0;
}