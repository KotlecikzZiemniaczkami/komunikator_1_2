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
            std::cout<< "ip found " << std::endl;
            ip = word;
            break;
        }
        if(word == nick)
            std::cout<< "user found " << std::endl;
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
    std::cout << "Im in file"<< std::endl;
    std::vector<std::string> file_content;
    std::string word;
    std::fstream file;
    std::cout << "I want to delete: " << nick << ip << std::endl;
    //file opening and copying data except those which user wants to delete
    file.open("base.txt", std::ios::in);
    while (std::getline(file, word)) {
        if(word == nick or word == ip) {
           continue;
        }
        std::cout<< "push: " << word <<std::endl;
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
    if(!file.good())
        return;
    while(getline(file, word)){
        if(i%2 == 0) {
            std::cout << num << '.' << word << std::endl;
            num += 1;
        }
        i += 1;
    }
    file.close();
}

//helping with connecting by giving an ip to the Message's function
void TxtFile::making_con() {
    std::cout << "podaj nick: ";
    std::cin >> nick;
    get_ip();
    char fake_ip[ip.length()+1];
    strcpy(fake_ip, ip.c_str());
    std::cout<<ip<<std::endl;
    connect_to_server(*fake_ip); //reinterpret_cast<char &>(p_ip)
}

void TxtFile::send() {
    initialize_wsa();
    create_socket();
    making_con();
    send_data();
    WSACleanup();
}

