#include "CTCPConnect.h"

using namespace RuEngine;

CTCPConnect::CTCPConnect()
{

}

CTCPConnect::CTCPConnect(const char* _sz_port, const char* _sz_addr)
{
    Initialize(_sz_port, _sz_addr);
}

CTCPConnect::~CTCPConnect()
{

}

void CTCPConnect::Initialize()
{
    Initialize(msz_port, msz_ip);
}

void CTCPConnect::Initialize(const char* _sz_port, const char* _sz_addr)
{
    int addrlen = strnlen(_sz_addr, 255);
    msz_ip = new char[addrlen];
    memccpy(msz_ip, _sz_addr, addrlen, 255);

    int portlen = strnlen(_sz_port, 255);
    msz_port = new char[portlen];
    memccpy(msz_port, _sz_port, portlen, 255);

	int strlen = sizeof(mtag_servaddr);
	int buf, cNum;//cNum ���� ��ȣ

	if ((mi_socketfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
		perror("socket fail");
	}
    else
    {
        memset(&mtag_servaddr, 0, strlen);
        mtag_servaddr.sin_family = AF_INET;
        inet_pton(AF_INET, _sz_addr, &mtag_servaddr.sin_addr);
        mtag_servaddr.sin_port = htons(atoi(_sz_port));
    }
}

int CTCPConnect::Connect()
{
    int result = 0;

    int strlen = sizeof(mtag_servaddr);
    
    cout << "try connect to server : ";
    cout << msz_ip << ":" << msz_port << endl;

    result = connect(mi_socketfd, (struct sockaddr *)&mtag_servaddr, strlen);

    return result;
}

void CTCPConnect::Send(void* _packet)
{
    ssize_t result = write(mi_socketfd, _packet, 4);
    
    if (result < 0)
    {
        
    }
}

void CTCPConnect::Close()
{
    int result = close(mi_socketfd);

    if(result < 0)
    {

    }
}