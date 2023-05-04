//
// Created by Damian on 30.04.2023.
//

#ifndef KOMUNIKATOR_1_2_FINALGUI_H
#define KOMUNIKATOR_1_2_FINALGUI_H
#include "Gui.h"
#include "receiver.h"
#include <cstdlib>


//to co ma user: dzialajace menu, lacnosc etc
//to do: dokonczyc ta klase i dokonczyc main
class FinalGui:public Gui, public receiver, public Message{
    int decider{};
    void send();
    void wait_and_receive();
public:
    void menu();
};


#endif //KOMUNIKATOR_1_2_FINALGUI_H
