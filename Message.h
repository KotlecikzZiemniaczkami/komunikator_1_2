//
// Created by Damian on 17.04.2023.
//

#ifndef KOMUNIKATOR_1_2_MESSAGE_H
#define KOMUNIKATOR_1_2_MESSAGE_H
#include "User.h"
#include "GuiTr.h"

class Message :public User, public GuiTr{
    int wsaError;
    WORD wVersionRequested;
    int port;
    int senderSocket;
public:
    Message();
    void initialize_wsa();
    void create_socket() override;
};


#endif //KOMUNIKATOR_1_2_MESSAGE_H