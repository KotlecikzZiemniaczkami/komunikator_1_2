//
// Created by Damian on 26.05.2023.
//

#ifndef KOMUNIKATOR_1_2_CYPHER_H
#define KOMUNIKATOR_1_2_CYPHER_H
#include <string>

class cypher {
protected:
    int key;
    std::string word;
    virtual void encryption() = 0;
    virtual void decryption() = 0;

};


#endif //KOMUNIKATOR_1_2_CYPHER_H
