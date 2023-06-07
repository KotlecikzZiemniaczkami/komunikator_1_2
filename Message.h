//
// Created by Damian on 17.04.2023.
//

#ifndef KOMUNIKATOR_1_2_MESSAGE_H
#define KOMUNIKATOR_1_2_MESSAGE_H
#include "User.h"
#include "TxtFile.h"
#include "cypher.h"
#include "Visionera.h"
#include "cesar.h"

class Message :public User{
    TxtFile person;
    void connect_to_server(char &ip);
    void send_data();
    void making_con();
public:
    Message();
    void tsend();
};


#endif //KOMUNIKATOR_1_2_MESSAGE_H
