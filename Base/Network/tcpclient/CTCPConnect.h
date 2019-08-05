#ifndef CTCPCONNECT_H__
#define CTCPCONNECT_H__

namespace RuEngine
{

class CTCPConnect
{
public:
    char* msz_port;
    char* msz_ip;

public:
    CTCPConnect();
    ~CTCPConnect();
};

}

#endif