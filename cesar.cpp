//
// Created by Damian on 26.05.2023.
//

#include "cesar.h"

//decryption method is decrypting message (mess)
void cesar::decryption(char *mess) {
    int i = 0;
    //while loop is to make sure that whole text is decrypted
    while(mess[i] != '\0'){
        //purpose of distinguishing between lowercase and uppercase letters
        //is because of small differences in decryption
        if (mess[i] <= 'Z' and mess[i] >= 'A') {
            if (mess[i] - key >= 'A')
                mess[i] -= key;
            else
                mess[i] = mess[i] - key + 26;
        }
        else if(mess[i] <= 'z' and mess[i] >= 'a'){
            if (mess[i] - key >= 'a')
                mess[i] -= key;
            else
                mess[i] = mess[i] - key + 26;
        }
        i++;
    }
}

cesar::cesar(int k) {
    key = k;
}

//encryption method is encrypting message (mess)
void cesar::encryption(char *mess) {
    int i = 0;
    //while loop is to make sure that whole text is encrypted
    while(mess[i] != '\0'){
        //purpose of distinguishing between lowercase and uppercase letters
        //is because of small differences in encryption
        if (mess[i] <= 'Z' and mess[i] >= 'A') {
            if (mess[i] + key <= 'Z')
                mess[i] += key;
            else
                mess[i] = mess[i] + key - 26;
        }
        else if(mess[i] <= 'z' and mess[i] >= 'a'){
                if (mess[i] + key <= 'z')
                    mess[i] += key;
                else
                    mess[i] = mess[i] + key - 26;
        }
        i++;
    }
}

