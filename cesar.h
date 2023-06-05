//
// Created by Damian on 26.05.2023.
//

#ifndef KOMUNIKATOR_1_2_CESAR_H
#define KOMUNIKATOR_1_2_CESAR_H
#include "cypher.h"

class cesar: public cypher {
    int key;
public:
    cesar(int k);
    void encryption(char mess[200]);
    void decryption(char mess[200]);
};


#endif //KOMUNIKATOR_1_2_CESAR_H
