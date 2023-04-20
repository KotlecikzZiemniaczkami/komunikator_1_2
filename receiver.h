//
// Created by Damian on 17.04.2023.
//

#ifndef KOMUNIKATOR_1_2_RECEIVER_H
#define KOMUNIKATOR_1_2_RECEIVER_H
#include "User.h"
#include <string>

class receiver :public User {
    int wsaError;
    WORD wVersionRequested;
    int port;
    int receiverSocket;
public:
   receiver();
   void create_socket() override;
   void bind_socket(); //static?????
   void listen_on_socket();
   void accept_connection();
   void send_receive_data() override;
   void disconn() override;
};


#endif //KOMUNIKATOR_1_2_RECEIVER_H