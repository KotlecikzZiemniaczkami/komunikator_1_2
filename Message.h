//
// Created by Damian on 17.04.2023.
//

#ifndef KOMUNIKATOR_1_2_MESSAGE_H
#define KOMUNIKATOR_1_2_MESSAGE_H
#include "User.h"
#include "TxtFile.h"

//message is a class responsible for sender's side of comunication

class Message :public User{
    //person lets to take data from database
    TxtFile person;
    //connect_to_server is a method responsible for making
    //connection with receiver (receiver works like server
    //that's from name of method)
    void connect_to_server(char &ip);
    //send_data is responsible for correct send message
    void send_data();
    //making_con is responsible for taking data about receiver from user
    //and starting connection
    void making_con();
public:
    Message();
    //tsend is whole work of message class in one method
    void tsend();
};


#endif //KOMUNIKATOR_1_2_MESSAGE_H
