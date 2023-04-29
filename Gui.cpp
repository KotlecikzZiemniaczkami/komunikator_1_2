//
// Created by Damian on 24.04.2023.
//

#include "Gui.h"

//just a constructor
Gui::Gui(std::string &i, std::string &n) : TxtFile(i, n) {
}

int Gui::guard() {
    std::regex ip_pattern(R"(\d+.\d+.\d)");
    if(std::regex_match(ip, ip_pattern)){
        return 1;
    }
    return 0;
}

//is adding a user
void Gui::add_user() {
    std::cout << "So it is time to add a friend :D" << std::endl;
    std::cout << "please, write here Your friend's nick: ";
    std::cin >> nick;
    std::cout << "please, write here Your friend's ip: ";
    std::cin >> ip;
    if(!guard()){
        std::cout << "incorrect ip. I will return to menu." << std::endl;
        return;
    }
    add_data();
}

void Gui::show_friends() {
    int just_to_close;
    std::cout << "This is the list of all Your friends\nwho are in my system:" << std::endl;
    all_content();
    std::cout << "press any button to continue" << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // To do: zrobić z tego funkckcje zaprzyjaźnioną
    just_to_close = _getwch();
    std::system("clear");

}

void Gui::delete_friend() {

}


/*to do
 * dokonczyc pisanie metod tej klasy
 * ogarnac w koncu main
 *
 * zrobic cale gui z menu etc. wybor wczytywac tak jak on bezposrednio za pomoca tamtej dziwnej komendy
 * z lapki wczytywac tylko to, co trzeba
*/