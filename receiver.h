//
// Created by Damian on 17.04.2023.
//

#ifndef KOMUNIKATOR_1_2_RECEIVER_H
#define KOMUNIKATOR_1_2_RECEIVER_H
#include "User.h"
#include <string>

class receiver :public User {
    //socket
    long long acceptSocket;
    //agreement is to control if somebody with good attitude wants to connect
    //and then agreement is base to let the connection begin
    int agreement;
   void bind_socket(); //binds a socket
   void listen_on_socket(); //is listening on a socket
   void selection(); //is showing how situation looks on a port
   void accept_connection(); //is accepting connection
   void receive_data(); //is receiving data
public:
   receiver(); //constructor
   void sum(); // all functions made to easy implement
};


#endif //KOMUNIKATOR_1_2_RECEIVER_H
