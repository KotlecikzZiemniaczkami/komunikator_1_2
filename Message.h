//
// Created by Damian on 17.04.2023.
//

#ifndef KOMUNIKATOR_1_2_MESSAGE_H
#define KOMUNIKATOR_1_2_MESSAGE_H
#include "User.h"
#include "TxtFile.h"

class Message :public User{
    TxtFile person;
protected:
    Message();
    void connect_to_server(char &ip);
    void send_data();
    void making_con();
    void tsend();
};


#endif //KOMUNIKATOR_1_2_MESSAGE_H
