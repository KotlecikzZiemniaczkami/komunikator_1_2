//
// Created by Damian on 24.04.2023.
//

#ifndef KOMUNIKATOR_1_2_GUI_H
#define KOMUNIKATOR_1_2_GUI_H
#include "TxtFile.h"
#include <regex>
#include <conio.h>
#include "receiver.h"

//Gui is a class to control processes on local computer
class Gui:public TxtFile{
    //control is to make code much shorter. It helps to inform user
    //about database status
    int control;
    void getting_ip_and_nick_from_user(); //is getting an ip and nick from user
    int guard(); //exist only to test if ip is correct
public:
    Gui();
    void clearing();//clears gui
    void show_friends();//is showing list of friends
    void add_user(); //is adding user
    void delete_friend();//is deleting address from base
};


#endif //KOMUNIKATOR_1_2_GUI_H
