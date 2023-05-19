//
// Created by Damian on 24.04.2023.
//

#include "Gui.h"

//just a constructor
Gui::Gui() : TxtFile() {
    control = 0;
}

void Gui::clearing() {
    int just_to_close;
    std::cout << "*PRESS ANY BUTTON*" << std::endl;
    just_to_close = _getwch();
    system("cls");
}

//is checking if ip number is correct
int Gui::guard() {
    std::regex ip_pattern(R"(\d+.\d+.\d+.\d+)");
    if(std::regex_match(ip, ip_pattern)){
        return 1;
    }
    return 0;
}

//gets an ip number  and nick
void Gui::getting_ip_and_nick_from_user(){
    if (control == 0) {
        std::cout << "please, write nick here: " << std::endl;
        fflush(stdin);
        std::cin >> nick;
        std::cout << "please, write ip here: " << std::endl;
        fflush(stdin);
        std::cin >> ip;
    }
    else if(control == 1){
        std::cout << "please, write nick here: " << std::endl;
        std::cin >> nick;
    }
    else{
        std::cout << "please, write ip here: " << std::endl;
        std::cin >> ip;
    }
}


//is adding a user
void Gui::add_user() {
    control = 0;
    std::cout << "So it is time to add a friend :D" << std::endl;
    getting_ip_and_nick_from_user();
    if(!guard()){
        std::cout << "incorrect ip. I will return to menu." << std::endl;
        clearing();
        return;
    }
    add_data();
}

//is showing list of friends
void Gui::show_friends() {
    std::cout << "This is the list of all Your friends\nwho are in my system:" << std::endl;
    all_content();
    std::cout << "press any button to continue" << std::endl;
}

void Gui::delete_friend() {
    int if_found;
    std::cout << "This is the list of all Your friends\nwho are in my system:" << std::endl;
    all_content();
    control = 1;
    std::cout << "who do You want delete?" << std::endl;
    getting_ip_and_nick_from_user();
    get_ip();
    delete_data();
}

void Gui::wait_and_receive() {
    receiver rec1;
    rec1.initialize_wsa();
    rec1.create_socket();
    rec1.bind_socket();
    rec1.listen_on_socket();
    rec1.selection();
    rec1.accept_connection();
    rec1.receive_data();
    WSACleanup();
}


