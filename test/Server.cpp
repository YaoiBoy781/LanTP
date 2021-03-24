#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

int main(){

    int sockfd, ret;
    struct sockaddr_in serverAddr = {0};

    int newSocket;
    struct sockaddr_in newAddr;

    socklen_t addr_size;

    char buffer[1024] = {0};
    pid_t childpid;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        std::cout << "[-]Error in connection.\n" << std::endl;
        return 1;
    }

    std::cout << "[+]Server Socket is created.\n" << std::endl;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    //serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    if(ret < 0)
    {
        std::cout << "[-]Error in binding.\n" << std::endl;
        return 1;

    }

    std::cout << "[+]Bind to port:" << 4444 << std::endl;

    if(listen(sockfd, 10) == 0)
    {
        std::cout << "[+]Listening....\n" << std::endl;
    }
    else
        {
        std::cout << "[-]Error in binding.\n" << std::endl;
        return 1;
    }


    while(true)
    {
        newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
        if(newSocket < 0)
        {
            return 1;
        }
        std::cout << "Connection accepted from:" <<  inet_ntoa(newAddr.sin_addr) << ntohs(newAddr.sin_port) << std::endl;

        if((childpid = fork()) == 0)
        {
            close(sockfd);

            while(true)
            {
                recv(newSocket, buffer, 1024, 0);
                if(strcmp(buffer, ":exit") == 0)
                {
                    std::cout << "Disconnected from:" << inet_ntoa(newAddr.sin_addr) << ntohs(newAddr.sin_port) << std::endl;
                    break;
                }else
                    {
                    std::cout << "Client: " <<  buffer << std::endl;
                    send(newSocket, buffer, sizeof(buffer), 0);
                    bzero(buffer, strlen(buffer));
                }
            }

        }

    }
    close(newSocket);

    return 0;
}
