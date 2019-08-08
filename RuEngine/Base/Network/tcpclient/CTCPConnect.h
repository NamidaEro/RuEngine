#ifndef CTCPCONNECT_H__
#define CTCPCONNECT_H__

#if _WIN64 || _WIN32
#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32")
#else
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
#endif


using namespace std;

namespace RuEngine
{
#if _WIN64 || _WIN32
class __declspec(dllexport) CTCPConnect
{
private:
	char* msz_port;
	char* msz_ip;

	WSADATA mtag_data;
	SOCKADDR_IN mtag_addr;
	SOCKET mtag_socket;

public:
	CTCPConnect();
	CTCPConnect(const char* _sz_port, const char* _sz_addr);
	~CTCPConnect();

public:
	void Initialize();
	void Initialize(const char* _sz_port, const char* _sz_addr);

public:
	int Connect();
	void Send(void* _packet);
	void Close();

public:
	void Release();
};
#else
class CTCPConnect
{
private:
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

public:
	void Release();
};
#endif
}

#endif