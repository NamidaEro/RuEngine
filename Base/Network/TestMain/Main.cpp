#include <iostream>
#include "../Headers/CTCPConnect.h"
#include "../Headers/CTCPServer.h"

using namespace std;

using namespace RuEngine;

int main(int argc, char** argv)
{
    cout << argc << endl;
    if(argc == 2)
    {
        struct sockaddr_in servaddr;

        CTCPServer svr;
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servaddr.sin_port = htons(atoi(argv[1]));

        svr.SetServer(servaddr);
        
        svr.initialize();
    }
    else
    {
        CTCPConnect tcp;
        tcp.Initialize("8888", "127.0.0.1");
        tcp.Connect();

        int* a = new int;
        *a = 8;

        tcp.Send((void*)a);
        tcp.Close();

        delete a;
    }
    
    
    return 0;
}