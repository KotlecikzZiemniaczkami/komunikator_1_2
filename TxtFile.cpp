//
// Created by Damian on 24.04.2023.
//

#include "TxtFile.h"

//adding ip and nick to the file
void TxtFile::add_data() {
    std::fstream file;
    file.open("base.txt", std::ios::out | std::ios::app);
    file << nick << std::endl;
    file << ip << std::endl;
    file.close();
}

//getting an ip form the file
void TxtFile::get_ip() {
    std::fstream file;
    int hit = 0;
    std::string word;

    //file opening
    file.open("base.txt", std::ios::in);

    //checking if file has opened correctly
    if(!file.good()){
        std::cout << "THERE IS A PROBLEM WITH TXT FILE" <<std::endl;
        return;
    }

    //searching for an ip basing on nick
    while (std::getline(file, word)) {
        if(hit == 1) {
            ip = word;
            break;
        }
        if(word == nick)
            hit = 1;
    }
    file.close();
}

//just a constructor
TxtFile::TxtFile() {
    ip = "";
    nick = "";
}

//delating user from the base
void TxtFile::delete_data() {
    int if_found = 0;
    std::vector<std::string> file_content;
    std::string word;
    std::fstream file;
    //file opening and copying data except those which user wants to delete
    file.open("base.txt", std::ios::in);
    while (std::getline(file, word)) {
        if(word == nick or word == ip) {
           continue;
        }
        file_content.push_back(word);

    }
    file.close();
    //replacing old txt file with new one without unwanted data
    file.open("base.txt", std::ios::out);
    for(int i = 0; i < file_content.size(); i++){
        file << file_content[i] << std::endl;
    }
    file.close();
}

//is showing nicks
void TxtFile::all_content() {
    int i = 0;
    int num = 1;
    std::string word;
    std::fstream file;
    file.open("base.txt", std::ios::in);
    //file.good() checks if everything in import of txt file is ok
    if(!file.good())
        return;
    //shows only nick in nice way (with actual numeration)
    while(getline(file, word)){
        if(i%2 == 0) {
            std::cout << num << '.' << word << std::endl;
            num += 1;
        }
        i += 1;
    }
    file.close();
}

