//
// Created by Damian on 26.05.2023.
//

#ifndef KOMUNIKATOR_1_2_CYPHER_H
#define KOMUNIKATOR_1_2_CYPHER_H
#include <string>

//cypher is an abstract class which main task is
//to make change of cyphers and optional adding new
//cyphers to code easier
class cypher {
public:
    //encryption and decryption are methods which mandatory for
    //a new cypher class/
    virtual void encryption(char mess[200]) = 0;
    virtual void decryption(char mess[200]) = 0;

};


#endif //KOMUNIKATOR_1_2_CYPHER_H
