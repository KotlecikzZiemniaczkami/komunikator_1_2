//
// Created by Damian on 24.04.2023.
//

#include "Gui.h"

//just a constructor
Gui::Gui() : TxtFile() {
    control = 0;
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
        std::cin >> nick;
        std::cout << "please, write ip here: " << std::endl;
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
    std::cout << "phase 1" << std::endl;
    getting_ip_and_nick_from_user();
    std::cout << "phase 2" << std::endl;
    get_ip();
    std::cout << "phase 3" << std::endl;
    std::cout << "phase 4" << std::endl;
    delete_data();
    std::cout << "phase 5" << std::endl;
}

//helping with connecting by giving an ip to the Message's function
void Gui::making_con() {
    control = 1;
    show_friends();
    getting_ip_and_nick_from_user();
    connect_to_server((char &) ip); //reinterpret_cast<char &>(p_ip)
}



/*to do
 * dokonczyc pisanie metod tej klasy
 * ogarnac w koncu main
 *
 * zrobic cale gui z menu etc. wybor wczytywac tak jak on bezposrednio za pomoca tamtej dziwnej komendy
 * z lapki wczytywac tylko to, co trzeba
*/