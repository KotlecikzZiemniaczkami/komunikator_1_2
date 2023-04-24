//
// Created by Damian on 17.04.2023.
//

#include "Message.h"

Message::Message() {
    port = 55555;
    senderSocket = INVALID_SOCKET;
    wVersionRequested = MAKEWORD(2, 2);
    WSAData wsaData{};
    wsaError = 0;
}

void Message::initialize_wsa() {
    WSAData wsaData{};
    wsaError = WSAStartup(wVersionRequested, &wsaData);
    if(wsaError != 0){
        std::cout << "The Winsock dll not found!" << std::endl;
    }
    else{
        std::cout << "The Winsock dll found!" << std::endl;
    }
}

void Message::create_socket() {
    senderSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (senderSocket == INVALID_SOCKET){
        std::cout << "socket() has failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
    }
    else{
        std::cout << "socket() is cool" << std::endl;
    }
}

void Message::connect_to_server() {
    sockaddr_in clientService;
    clientService.sin_family = AF_INET;
    clientService.sin_port = htons(port);
    clientService.sin_addr.s_addr = inet_addr("192.168.1.13");
    memset(&clientService.sin_zero, 0, 8);
    if (connect(senderSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR)
    {
        std::cout<<"Client: connect() - Failed to connect " << std::endl;
        WSACleanup();
    }
    else{
        std::cout << "client connect is ok" << std::endl;
    }
}

void Message::send_data() {
    char mess[200];
    std::printf("What should I send Master? ");
    std::cin.getline(mess,200);
    int officialSender = send(senderSocket, mess, 200,0);
    if (officialSender == SOCKET_ERROR){
        std::printf("We have a problem with alighting Sir: %d.", WSAGetLastError());
        WSACleanup();
    }
    else
        printf("we have just send %d bytes Sir", officialSender);
}

void Message::disconn() {

}



