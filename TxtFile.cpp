//
// Created by Damian on 24.04.2023.
//

#include "TxtFile.h"

//dodawanie znajomych
void TxtFile::add_data(std::string newNick, std::string newIp) {

}

//z tej funkcji pobieranie ip na podstawie nicku z bazy
std::string TxtFile::get_ip() {
    file.open("base.txt", std::ios::out | std::ios::app);

    return std::string();
}

/* to do
 * dokonczyc metody
 * dodac metode usuwania znajomych