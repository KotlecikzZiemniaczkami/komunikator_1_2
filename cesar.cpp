//
// Created by Damian on 26.05.2023.
//

#include "cesar.h"


void cesar::decryption(char *mess) {
    int i = 0;
    while(mess[i] != '\0'){
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

void cesar::encryption(char *mess) {
    int i = 0;
    while(mess[i] != '\0'){
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

