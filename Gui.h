//
// Created by Damian on 24.04.2023.
//

#ifndef KOMUNIKATOR_1_2_GUI_H
#define KOMUNIKATOR_1_2_GUI_H
#include "TxtFile.h"
#include <regex>
#include "just_clearing.h"

class Gui:public TxtFile, public just_clearing{
    int control;
    void getting_ip_and_nick_from_user(); //is getting an ip and nick from user
    int guard(); //exist only to test if ip is correct
protected:
    Gui(std::string &i, std::string &n);
    void add_user(); //is adding user being polite to user
    void show_friends();
    void delete_friend();
};


#endif //KOMUNIKATOR_1_2_GUI_H
