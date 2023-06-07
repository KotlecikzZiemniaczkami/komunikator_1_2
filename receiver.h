//
// Created by Damian on 17.04.2023.
//

#ifndef KOMUNIKATOR_1_2_RECEIVER_H
#define KOMUNIKATOR_1_2_RECEIVER_H
#include "User.h"
#include <string>
#include "cypher.h"
#include "Visionera.h"
#include "cesar.h"

class receiver :public User {
    long long acceptSocket;
    int agreement;
public:
   receiver();
   void bind_socket(); //static?????
   void listen_on_socket();
   void selection();
   void accept_connection();
   void receive_data();
/*public:
   void wait_and_receive();*/
};


#endif //KOMUNIKATOR_1_2_RECEIVER_H
