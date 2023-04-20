//
// Created by Damian on 17.04.2023.
//

#include "Message.h"

Message::Message() {
    port = 66666;
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
    InetPton(AF_INET, "127.0.0.1", &clientService.sin_addr); //place for receiver's ip
    clientService.sin_port = htons(port);
    if (connect(senderSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR)
    {
        std::cout<<"Client: connect() - Failed to connect " << std::endl;
        WSACleanup();
    }
    else{
        std::cout << "client connect is ok" << std::endl;
    }
}

void Message::send_receive_data() {

}

void Message::disconn() {

}



