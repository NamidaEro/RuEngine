#ifndef CTCPCONNECT_H__
#define CTCPCONNECT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>
#include <iostream>

using namespace std;

namespace RuEngine
{

class CTCPConnect
{
public:
    char* msz_port;
    char* msz_ip;

private:
    int mi_socketfd;
    struct sockaddr_in mtag_servaddr;

public:
    CTCPConnect();
    CTCPConnect(const char* _sz_port, const char* _sz_addr);

public:
    ~CTCPConnect();

public:
    void Initialize();
    void Initialize(const char* _sz_port, const char* _sz_addr);

public:
    int Connect();
    void Send(void* _packet);
    void Close();
};

}

#endif