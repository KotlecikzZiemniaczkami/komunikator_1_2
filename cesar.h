//
// Created by Damian on 26.05.2023.
//

#ifndef KOMUNIKATOR_1_2_CESAR_H
#define KOMUNIKATOR_1_2_CESAR_H
#include "cypher.h"

//one of the ciphers
//it encrypts and decrypts based on number
class cesar: public cypher {
    //key is the number of shifts
    int key;
public:
    //constructor makes change of key in code easier
    cesar(int k);
    //encryption method encrypts message (which is in char mess[200])
    void encryption(char mess[200]);
    //decryption method decrypts message
    void decryption(char mess[200]);
};


#endif //KOMUNIKATOR_1_2_CESAR_H
