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

int main()
{
	CFile file("text.txt");

	file.Write("되나?");
	
	system("pause");
	return 0;
}