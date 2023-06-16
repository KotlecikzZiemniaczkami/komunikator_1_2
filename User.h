//
// Created by Damian on 16.04.2023.
//

#ifndef KOMUNIKATOR_1_2_USER_H
#define KOMUNIKATOR_1_2_USER_H
#include <winsock2.h>
#include <iostream>
#include <ws2tcpip.h>
#include "cypher.h"
#include "Visionera.h"
#include "cesar.h"


// It is a class responsible for start of communication
class User {
protected:
    //socket error number
    int wsaError;
    //windows variable to ask system for information about using sockets
    WORD wVersionRequested;
    //port number
    int port;
    //place for a number returned by socket functions
    long long userSocket;
    User();
public:
    //initialization wsa
    //it is start of all socket communication
    void initialize_wsa();
    //creation of start socket
    void create_socket();
};


#endif //KOMUNIKATOR_1_2_USER_H
