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
	

#if _WIN64 || _WIN32
	file.Open("wintest.txt", (RuEngine::eFileMode)(Add | Out));
	file.Write("\nTest");
#else
	file.Open("/home/ubuntu/git/RuEngine/TestConsole/test.txt", (RuEngine::eFileMode)(Add | Out));
	file.Write(argv[1]);
#endif
	
	//system("pause");
	return 0;
}