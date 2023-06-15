//
// Created by Damian on 24.04.2023.
//

#include "Gui.h"

//just a constructor
Gui::Gui() : TxtFile() {
    control = 0;
}

//clears gui for when key on keyboard is clicked
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
    //if control = 0 code will start procedure of loading nick and ip from user
    if (control == 0) {
        std::cout << "please, write nick here: " << std::endl;
        //fflush make code ignore white spaces
        fflush(stdin);
        //here nick is actualised
        std::cin >> nick;
        std::cout << "please, write ip here: " << std::endl;
        fflush(stdin);
        //here ip is actualised
        std::cin >> ip;
    }
    //if control = 1 code will start procedure of loading nick from user
    else if(control == 1){
        std::cout << "please, write nick here: " << std::endl;
        std::cin >> nick;
    }
    //in any other situation control starts procedure of ip loading
    else{
        std::cout << "please, write ip here: " << std::endl;
        std::cin >> ip;
    }
}


//is adding a user
void Gui::add_user() {
    //making control ready to load both: ip and nick from user
    control = 0;
    std::cout << "So it is time to add a friend :D" << std::endl;
    getting_ip_and_nick_from_user();
    if(!guard()){
        //if ip is not correct (number.number.number.number) there will be shown text informing about that
        //and cancel whole procedure
        std::cout << "incorrect ip. I will return to menu." << std::endl;
        clearing();
        return;
    }
    //if everything is ok, data will be added to database
    add_data();
}

//is showing list of friends
void Gui::show_friends() {
    std::cout << "This is the list of all Your friends\nwho are in my system:" << std::endl;
    //all_content is a function from TxtFile, and it is responsible for showing nicks from database
    all_content();
    std::cout << "press any button to continue" << std::endl;
}


//is responsible for deleting people from database
void Gui::delete_friend() {
    std::cout << "This is the list of all Your friends\nwho are in my system:" << std::endl;
    //before deleting all from database is shown
    all_content();
    //control is made ready to take only nick
    control = 1;
    std::cout << "who do You want delete?" << std::endl;
    //nick is taken from user
    getting_ip_and_nick_from_user();
    //ip is taken from database
    get_ip();
    //both are deleted from database
    delete_data();
}

//data receivering procedure
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


