//
// Created by Damian on 24.04.2023.
//

#ifndef KOMUNIKATOR_1_2_GUI_H
#define KOMUNIKATOR_1_2_GUI_H
#include "TxtFile.h"
#include <regex>
#include <conio.h>
#include "receiver.h"


class Gui:public TxtFile{ //public Message
    int control;
    void getting_ip_and_nick_from_user(); //is getting an ip and nick from user
    int guard(); //exist only to test if ip is correct
public:
    Gui();
    void clearing();
    void show_friends();
    void wait_and_receive();
    void add_user();
    void delete_friend();
};


#endif //KOMUNIKATOR_1_2_GUI_H
