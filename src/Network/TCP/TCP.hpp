#include "../NetLibsHeader.hpp"


class TCP
{
private:
    std::string domain;
    unsigned short port;

    int sockFD;
    struct sockaddr_in sockAdrrOps = {0};

public:
    TCP(std::string domain, unsigned short port);

    unsigned short getPort();
    std::string getDomain();

    void Connect();
    void Bind();
    void Listen(int num);
    int Accept();
    int Fork();
    std::string Recv(int clientSockFD);
    void Send(std::string massage);
    void Close();
    void Close(int sockFD);

};