#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444
#define IP "192.168.0.113"

int main()
{
    int clientSocket, ret;
    struct sockaddr_in serverAddr = {0};
    char buffer[1024];
    std::string massage;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(clientSocket < 0)
    {
        std::cout << "[-]Error in connection." << std::endl;
        return 1;
    }
    std::cout << "[+]Client Socket is created." << std::endl;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    //serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    inet_pton(AF_INET, IP, &serverAddr.sin_addr);

    ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(ret < 0)
    {
        std::cout << "[-]Error in connection." << std::endl;
        return 1;
    }
    std::cout << "[+]Connected to Server." << std::endl;

    while(true)
    {
        std::cout << "Enter massage:";
        std::getline(std::cin, massage);
        send(clientSocket, massage.c_str(), massage.size() + 1, 0);

        if(strcmp(buffer, ":exit") == 0)
        {
            close(clientSocket);
            std::cout << "[-]Disconnected from server." << std::endl;
            return 1;
        }

        if(recv(clientSocket, buffer, 1024, 0) < 0)
        {
            std::cout << "[-]Error in receiving data." << std::endl;
        }
        else

            {
            std::cout << "Server:" << buffer << std::endl;
        }

    }

    close(clientSocket);

    return 0;
}
