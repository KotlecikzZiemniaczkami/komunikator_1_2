//
// Created by Damian on 24.04.2023.
//

#ifndef KOMUNIKATOR_1_2_GUI_H
#define KOMUNIKATOR_1_2_GUI_H
#include "TxtFile.h"

class Gui:public TxtFile{
public:
    Gui(std::string &i, std::string &n);
    void add_user();
    void show_friends();
    void delete_friend();
};


#endif //KOMUNIKATOR_1_2_GUI_H
