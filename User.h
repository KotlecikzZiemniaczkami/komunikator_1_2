//
// Created by Damian on 16.04.2023.
//

#ifndef KOMUNIKATOR_1_2_USER_H
#define KOMUNIKATOR_1_2_USER_H
#include <winsock2.h>
#include <iostream>
#include <ws2tcpip.h>

class User {
protected:
    //virtual void initialize_wsa() = 0; prubuje to zrobi na zasadzie konstruktora. pruba odbywa się w receiver
    virtual void create_socket() = 0;
    virtual void disconn() = 0;

};


#endif //KOMUNIKATOR_1_2_USER_H
