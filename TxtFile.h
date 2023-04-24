//
// Created by Damian on 24.04.2023.
//

#ifndef KOMUNIKATOR_1_2_TXTFILE_H
#define KOMUNIKATOR_1_2_TXTFILE_H
#include <fstream>

class TxtFile {
    std::fstream file;
    std::string ip;
    std::string nick;
protected:
    std::string get_ip();
    void add_data(std::string nick, std::string ip); //is adding a user
};


#endif //KOMUNIKATOR_1_2_TXTFILE_H
