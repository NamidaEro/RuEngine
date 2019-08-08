#include <iostream>

#include "AString.h"
#include "CTCPConnect.h"

using namespace std;
using namespace RuEngine;

int main()
{
	AString str("hello");

	cout << str << endl;

	CTCPConnect con("8888", "127.0.0.1");
	con.Connect();

	system("pause");
	return 0;
}