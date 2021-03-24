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

TCP::TCP()
{
   
    sockFD = 0;

    sockAdrrOps = {0};
}


std::string TCP::getDomain()
{   
    return domain;
}

unsigned short TCP::getPort()
{
    return port;
}

sockaddr_in TCP::getOptions()
{
    
    return sockAdrrOps;
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

void TCP::Recv(char buffer[1024])
{
    recv(sockFD, buffer, 1024, 0);
}

void TCP::Send(std::string massage)
{
    send(sockFD, massage.c_str(), massage.size() + 1, 0);
}

void TCP::Close()
{
    close(sockFD);
}