#ifndef TCPSERVER_H__
#define TCPSERVER_H__

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <vector>

using namespace std;

namespace RuEngine
{

class CTCPServer
{
private:
    sockaddr_in mtag_svrAddr;
    int mi_clientNum = 0;
    vector<sockaddr_in*> mvec_client;

public:
    CTCPServer();
    ~CTCPServer();

public:
    sockaddr_in SetServer(const sockaddr_in& _addr);
    void initialize(void);
};

}
#endif