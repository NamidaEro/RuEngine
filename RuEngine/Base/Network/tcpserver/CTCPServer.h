#ifndef TCPSERVER_H__
#define TCPSERVER_H__

#if _WIN64 || _WIN32
#else
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
#endif // _WIN64

using namespace std;

namespace RuEngine
{
#if _WIN64 || _WIN32
class __declspec(dllexport) CTCPServer
{
public:
	CTCPServer();
	~CTCPServer();
};
#else
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
#endif
}
#endif