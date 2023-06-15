//
// Created by Damian on 26.05.2023.
//

#include "Visionera.h"

int Visionera::count(char *m){
    int num = 0;
    while(m[num+1] != '\0'){
        num += 1;
    }
    return num;
}


void Visionera::encryption(char *mess) {
    int size = count(mess);
    while (size >= key.length()){
        key += key;
    }
   for(int i = 0; i < size; i++){
       if(mess[i] <= 'z' and mess[i] >= 'a')
           mess[i] = ((mess[i]-97) + (key[i]-97))%27 + 97;
       else if (mess[i] <= 'Z' and mess[i] >= 'A')
           mess[i] = ((mess[i]-65) + (key[i]-65))%26 + 65;

   }
}

void Visionera::decryption(char *mess) {
    char a;
    int size = count(mess)+1;
    while (size >= key.length()){
        key += key;
    }
    for(int i = 0; i <= size; i++){
        if(mess[i] <= 'z' and mess[i] >= 'a'){
            if (((mess[i]-97) - (key[i]-97))%27 < 0)
                mess[i] = ((mess[i]-97) - (key[i]-97))%27 + 27 + 97;
            else
                mess[i] = ((mess[i]-97) - (key[i]-97))%27 + 97;
        }
        else if(mess[i] <= 'Z' and mess[i] >= 'A') {
            if (((mess[i] - 65) - (key[i] - 65)) % 27 < 0) {
                mess[i] = ((mess[i] - 65) - (key[i] - 65) + 1) % 26 + 26 + 64;
            }
            else {
                mess[i] = ((mess[i] - 65) - (key[i] - 65) + 1) % 26 + 64;
            }
            if (mess[i-1] == '@')
                mess[i] = 'Z';
        }
    }
    mess[size-1] -= 2;
}

Visionera::Visionera(std::string k) {
    key = k;
}
