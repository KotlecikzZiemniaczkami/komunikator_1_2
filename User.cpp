//
// Created by Damian on 16.04.2023.
//

#include "User.h"

User::User(){
    port = 66666;
    userSocket = INVALID_SOCKET;
    wVersionRequested = MAKEWORD(2, 2);
    //WSAData wsaData{}; prawdopodobnie niepotrzebne
    wsaError = 0;
}

void User::initialize_wsa() {
    WSAData wsaData{};
    wsaError = WSAStartup(wVersionRequested, &wsaData);
    if(wsaError != 0){
        std::cout << "The Winsock dll not found!" << std::endl;
    }
}

void User::create_socket() {
    userSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (userSocket == INVALID_SOCKET){
        std::cout << "socket() has failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
    }
}