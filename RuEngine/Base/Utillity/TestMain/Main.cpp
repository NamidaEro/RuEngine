#include <iostream>

#include "../Headers/AString.h"

using namespace std;
using namespace RuEngine;

int main(int argc, char** argv)
{
    AString str("Hello, World!");

   // cout << str << endl;

    str.Append("\nHi, there");

    cout << str << endl;

    return 0;
}