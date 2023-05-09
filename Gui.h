//
// Created by Damian on 24.04.2023.
//

#ifndef KOMUNIKATOR_1_2_GUI_H
#define KOMUNIKATOR_1_2_GUI_H
#include "TxtFile.h"
#include <regex>
#include "just_clearing.h"


class Gui:protected TxtFile, public just_clearing{ //public Message
    int control;
    void getting_ip_and_nick_from_user(); //is getting an ip and nick from user
    int guard(); //exist only to test if ip is correct
protected:
    void add_user(); //is adding user being polite to user
    void show_friends();// is showing list of all friends
    void delete_friend();//is deleting some frined
public:
    Gui();
};


#endif //KOMUNIKATOR_1_2_GUI_H
