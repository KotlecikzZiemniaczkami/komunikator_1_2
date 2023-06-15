//
// Created by Damian on 24.04.2023.
//

#ifndef KOMUNIKATOR_1_2_TXTFILE_H
#define KOMUNIKATOR_1_2_TXTFILE_H
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

//TxtFile is a class to control database

class TxtFile {
public:
    std::string ip;
    std::string nick;
    TxtFile(); //just a constructor
    void get_ip();//is getting an ip based on a nick
    void add_data(); //is adding a user
    void all_content(); //is showing all nicks from file
    void delete_data(); //is deleting an ip and a nick from base
};


#endif //KOMUNIKATOR_1_2_TXTFILE_H
