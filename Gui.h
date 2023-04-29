//
// Created by Damian on 24.04.2023.
//

#ifndef KOMUNIKATOR_1_2_GUI_H
#define KOMUNIKATOR_1_2_GUI_H
#include "TxtFile.h"
#include <regex>
#include <stdlib.h>

class Gui:public TxtFile{
public:
    Gui(std::string &i, std::string &n);
    void add_user(); //is adding user being polite to user
    void show_friends();
    void delete_friend();
    int guard(); //exist only to test if ip is correct
};


#endif //KOMUNIKATOR_1_2_GUI_H
