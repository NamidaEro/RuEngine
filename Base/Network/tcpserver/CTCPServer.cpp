#include "CTCPServer.h"

#include <iostream>

using namespace std;
using namespace Engine;

pthread_mutex_t mutlock = PTHREAD_MUTEX_INITIALIZER;

void* SocketConnect(void* arg)
{
    int accp_sock = (int)(*((int*)arg));

    int buf;

    ssize_t res_read;
    res_read = read(accp_sock, &buf, 4);
    cout << "@>> ";
    cout << buf << endl;
    pthread_mutex_lock(&mutlock);
    pthread_mutex_unlock(&mutlock);

    close(accp_sock);
}

CTCPServer::CTCPServer()
{

}

CTCPServer::~CTCPServer()
{

}

sockaddr_in CTCPServer::SetServer(const sockaddr_in& addr)
{
    memset(&svrAddr, 0, sizeof(svrAddr));
    svrAddr = addr;
    return svrAddr;
}

void CTCPServer::initialize(void)
{
    int listen_sock;

    listen_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(listen_sock < 0)
    {
        perror("socket failed");
        exit(0);
    }

    // bind
    int res_bind;
    res_bind = 
        bind(
            listen_sock
            , (struct sockaddr *)&svrAddr
            , sizeof(svrAddr));

    if(res_bind < 0)
    {
        perror("bind fail");
        exit(0);
    }
    
    int addrlen = sizeof(svrAddr);
    pthread_t tid[100];
    // loop
    while(1)
    {
        int res_listen = 0;
        res_listen = listen(listen_sock, 10);
        
        puts("client wait....");

        int accp_sock = 0;
        sockaddr_in* client = new sockaddr_in();
        accp_sock = 
            accept(
                listen_sock
                , (struct sockaddr *)client
                , (socklen_t*)&addrlen);

        if(accp_sock < 0)
        {
            perror("accept failed");
        }
        else
        {
            int res_trhead = 0;
            res_trhead =
                pthread_create(
                    &tid[clientNum]
                    , NULL
                    , &SocketConnect
                    , (void*)&accp_sock);

            if(res_trhead < 0)
            {
                perror("thread create failed");
            }
            else
            {
                int res_thredjoin = 0;
                res_thredjoin = pthread_join(tid[clientNum++], NULL);

                if(100 <= clientNum)
                {
                    clientNum = 0;
                }
            }
        }
    }
}