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
    TCP();
    ~TCP();

    unsigned short getPort();
    std::string getDomain();
    sockaddr_in getOptions();

    void Connect();
    void Bind();
    void Listen(int num);
    void Accept(struct sockaddr_in sockAddr);
    void Recv(char buffer[1024]);
    void Send(std::string massage);
    void Close();

};