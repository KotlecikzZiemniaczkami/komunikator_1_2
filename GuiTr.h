//
// Created by Damian on 17.04.2023.
//

#ifndef KOMUNIKATOR_1_2_GUITR_H
#define KOMUNIKATOR_1_2_GUITR_H
#include <string>

class GuiTr {
    std::string nick;
    std::string message_cont;
    std::string receiver_ip;
    std::string receiver_port;

public:
    void taking_receiver_ip();
    void taking_message_cont();
};


#endif //KOMUNIKATOR_1_2_GUITR_H
