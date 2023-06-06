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
       if(mess[i] <= 'z' and mess[i] >= 'a'){
           std::cout<<'z' - 'a';
           mess[i] = ((mess[i]-97) + (key[i]-97))%27 + 97;}
   }
}

void Visionera::decryption(char *mess) {
    char a;
    int size = count(mess);
    while (size >= key.length()){
        key += key;
    }
    for(int i = 0; i < size; i++){
        if(mess[i] <= 'z' and mess[i] >= 'a'){
            std::cout<< "I:" << (mess[i]-97) - (key[i]-97) << std::endl;
            std::cout<< "II:" << ((mess[i]-97) - (key[i]-97))%27 << std::endl;
            if (((mess[i]-97) - (key[i]-97))%27 < 0)
                mess[i] = ((mess[i]-97) - (key[i]-97))%27 + 27 + 97;
            else
                mess[i] = ((mess[i]-97) - (key[i]-97))%27 + 97;

        }

    }
}

Visionera::Visionera(std::string k) {
    key = k;
}
