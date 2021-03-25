#include "Network/TCP/TCP.hpp"

int main()
{
    TCP server("THIS", 4444);

    server.Bind();
    server.Listen(10);

    int clientSocket;
    std::string massage;

    while(true)
    {
        clientSocket = server.Accept();

        if (server.Fork() == 0)
        {
            server.Close();

            while(true)
            {
                massage = server.Recv(clientSocket);

                std::cout << massage;
            }
        }
    }

    server.Close(clientSocket);

    return 0;
}