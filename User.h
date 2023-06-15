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

class User {
protected:
    int wsaError;
    WORD wVersionRequested;
    int port;
    long long userSocket;
    User();
public:
    void initialize_wsa();
    void create_socket();
};


#endif //KOMUNIKATOR_1_2_USER_H
