/*
#include <iostream>
#include <string.h>

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

unsigned short port = 4444;

int main()
{   
    int serverSocketFD;
    serverSocketFD = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in ServerAddrOps = {0};

    ServerAddrOps.sin_family = AF_INET;
    ServerAddrOps.sin_port = htons(port);
    ServerAddrOps.sin_addr.s_addr = htonl(INADDR_ANY);

    int ret = bind(serverSocketFD, (struct sockaddr*) &ServerAddrOps, sizeof(ServerAddrOps));

    listen(serverSocketFD, 1);

    int clientSocketFD;
    struct sockaddr_in clientAddrOps;
    socklen_t addr_size;
    pid_t childPid;

    char buffer[1024];

    while(true)
    {
        clientSocketFD = accept(serverSocketFD, (struct sockaddr*)&clientAddrOps, &addr_size);

        if ((childPid = fork()) == 0)
        {
            close(serverSocketFD);
            
            while(true)
            {
                recv(clientSocketFD, buffer, 1024, 0);
                std::cout << buffer;
                
                bzero(buffer, strlen(buffer));
            }
        }
    }
    close(clientSocketFD);

    return 0;
}
*/

#include <iostream>
#include "Network/TCP/TCP.hpp"

int main()
{
    TCP server("THIS", 4444);

    server.Bind();

    server.Listen(10);

    TCP newss();

    while(true)
    {
        server.Accept()
    }
}