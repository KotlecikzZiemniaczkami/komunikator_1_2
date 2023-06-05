//
// Created by Damian on 26.05.2023.
//

#ifndef KOMUNIKATOR_1_2_CYPHER_H
#define KOMUNIKATOR_1_2_CYPHER_H
#include <string>

class cypher {
public:
    virtual void encryption(char mess[200]) = 0;
    virtual void decryption(char mess[200]) = 0;

};


#endif //KOMUNIKATOR_1_2_CYPHER_H
