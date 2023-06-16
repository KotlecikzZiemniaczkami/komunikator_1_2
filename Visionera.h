//
// Created by Damian on 26.05.2023.
//

#ifndef KOMUNIKATOR_1_2_VISIONERA_H
#define KOMUNIKATOR_1_2_VISIONERA_H
#include "cypher.h"
#include "iostream"

//this is a cypher to encrypt message (one of 2. First one is cesar)
//it "moves" character by position which has a character with the same index in key
class Visionera:public cypher {
    //it is a key to encryption and decryption
    std::string key;
    //int count counts signs in m[]
    int count(char m[200]);
public:
    Visionera(std::string k);
    //void encryption encrypts the message (mess)
    void encryption(char mess[200]);
    //void decryption decrypts the message (mess)
    void decryption(char mess[200]);
};


#endif //KOMUNIKATOR_1_2_VISIONERA_H
