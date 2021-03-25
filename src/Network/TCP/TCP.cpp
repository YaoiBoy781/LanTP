#include "./TCP.hpp"

TCP::TCP(std::string domain, unsigned short port)
{
    this->domain = domain;
    this->port = port;

    sockFD = socket(AF_INET, SOCK_STREAM, 0);

    sockAdrrOps.sin_family = AF_INET;
    sockAdrrOps.sin_port = htons(port);
    if (domain == "THIS")
    {
        sockAdrrOps.sin_addr.s_addr = htonl(INADDR_ANY);
    }

    else
    {
        sockAdrrOps.sin_addr.s_addr = htonl(stoi(domain));
    }
}

std::string TCP::getDomain()
{   
    return domain;
}

unsigned short TCP::getPort()
{
    return port;
}


void TCP::Connect()
{   
    connect(sockFD, (struct sockaddr*)&sockAdrrOps, sizeof(sockAdrrOps));
}

void TCP::Bind()
{
    bind(sockFD, (struct sockaddr*)&sockAdrrOps, sizeof(sockAdrrOps));
}

void TCP::Listen(int num)
{
    listen(sockFD, num);
} 

int TCP::Accept()
{   

    struct sockaddr_in clientSockAddrOps = {0};
    socklen_t lenAddr;

    return accept(sockFD,(struct sockaddr*)&clientSockAddrOps, &lenAddr);
}

int TCP::Fork()
{
    return fork();
}

std::string TCP::Recv(int clientSockFD)
{   
    char buffer[1024] = {0};

    recv(clientSockFD, buffer, 1024, 0);

    std::string massage(buffer);
    bzero(buffer, 1024);

    return massage;
}

void TCP::Send(std::string massage)
{
    send(sockFD, massage.c_str(), sizeof(massage), 0);
}

void TCP::Close()
{
    close(sockFD);
}

void TCP::Close(int sockFD)
{
    close(sockFD);
}