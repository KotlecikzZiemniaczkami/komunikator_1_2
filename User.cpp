//
// Created by Damian on 16.04.2023.
//

#include "User.h"

User::User(){
    //port number
    port = 66666;
    //in userSocket will be saved information about eventual error
    userSocket = INVALID_SOCKET;
    //The MAKEWORD(2,2) makes a request for version 2.2 of Winsock on the system
    wVersionRequested = MAKEWORD(2, 2);
    wsaError = 0;
}

//wsa initialization
void User::initialize_wsa() {
    //WSAData struct is a struct which contains
    //information about the Windows Sockets implementation
    WSAData wsaData{};
    //WSAStartup function is responsible for initiating use of WS2_32.dll
    wsaError = WSAStartup(wVersionRequested, &wsaData);
    //if everything is ok, wsaError is 0
    if(wsaError != 0){
        std::cout << "The Winsock dll not found!" << std::endl;
    }
}

//create_socket is creating first socket which is used to make first connection
void User::create_socket() {
    //AF_INET is just a family of ip addresses (AF_INET is ipv4)
    //SOCK_STREAM, how Windows says "The type specification for the new socket" and SOCK_STREAM is "A socket type that provides sequenced,
    //reliable, two-way, connection-based byte streams with an OOB data transmission mechanism"
    //IPPROTO_TCP is a protocol (IPPROTO_TCP is a TCP protocol)
    userSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (userSocket == INVALID_SOCKET){
        //if socket() returnes number of any error there is notification for a user
        //shown on the screen
        std::cout << "socket() has failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
    }
}