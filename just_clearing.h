//
// Created by Damian on 30.04.2023.
//

#ifndef KOMUNIKATOR_1_2_JUST_CLEARING_H
#define KOMUNIKATOR_1_2_JUST_CLEARING_H
#include <conio.h>
#include <iostream>

class just_clearing {
protected:
    void clearing(){
        int just_to_close;
        std::cout << "*PRESS ANY BUTTON*" << std::endl;
        std::cout<< "we are before before"<<std::endl;
        just_to_close = _getwch();
        std::cout<< "we are before"<<std::endl;
        system("cls");
        std::cout<< "we are after"<<std::endl;
    }
};


#endif //KOMUNIKATOR_1_2_JUST_CLEARING_H
