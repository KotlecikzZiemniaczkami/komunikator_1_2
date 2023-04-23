//
// Created by Damian on 17.04.2023.
//

#ifndef KOMUNIKATOR_1_2_MESSAGE_H
#define KOMUNIKATOR_1_2_MESSAGE_H
#include "User.h"
#include "GuiTr.h"

class Message :public User, public GuiTr{
public:
    Message();
    void connect_to_server();
    void send_data();
};


#endif //KOMUNIKATOR_1_2_MESSAGE_H
