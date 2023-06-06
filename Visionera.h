//
// Created by Damian on 26.05.2023.
//

#ifndef KOMUNIKATOR_1_2_VISIONERA_H
#define KOMUNIKATOR_1_2_VISIONERA_H
#include "cypher.h"
#include "iostream"

class Visionera:public cypher {
    std::string key;
public:
    int count(char m[200]);
    void encryption(char mess[200]);
    void decryption(char mess[200]);
    Visionera(std::string k);
};


#endif //KOMUNIKATOR_1_2_VISIONERA_H
