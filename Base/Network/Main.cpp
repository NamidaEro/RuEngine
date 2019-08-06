#include <iostream>
#include "./Headers/CTCPConnect.h"

using namespace std;

using namespace RuEngine;

int main(int argc, char** argv)
{
    CTCPConnect tcp;
    tcp.Initialize("8888", "localhost");
    tcp.Connect();
    tcp.Close();
    return 0;
}