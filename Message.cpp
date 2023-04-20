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



