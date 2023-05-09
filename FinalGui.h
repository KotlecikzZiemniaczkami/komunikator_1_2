//
// Created by Damian on 30.04.2023.
//

#ifndef KOMUNIKATOR_1_2_FINALGUI_H
#define KOMUNIKATOR_1_2_FINALGUI_H
#include "Gui.h"
#include "receiver.h"
#include <cstdlib>
#include "TxtFile.h"

class FinalGui:public Gui, public receiver{
    void wait_and_receive();
public:
    void menu();
};


#endif //KOMUNIKATOR_1_2_FINALGUI_H
