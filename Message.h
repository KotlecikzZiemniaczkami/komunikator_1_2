//
// Created by Damian on 17.04.2023.
//

#ifndef KOMUNIKATOR_1_2_MESSAGE_H
#define KOMUNIKATOR_1_2_MESSAGE_H
#include "User.h"

class Message :public User{
public:
    Message();
    void connect_to_server(char &ip);
    void send_data();
};


#endif //KOMUNIKATOR_1_2_MESSAGE_H
