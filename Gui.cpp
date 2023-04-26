//
// Created by Damian on 24.04.2023.
//

#include "Gui.h"

//just a constructor
Gui::Gui(std::string &i, std::string &n) : TxtFile(i, n) {
}

void Gui::add_user() {
    std::cout << "So it is time to add a friend :D" << std::endl;
    std::cout << "please, write there Your friend's nick: ";
    std::cin >> nick;
    std::cout << "please, write there Your friend's ip: ";
    std::cin >> ip;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    add_data();
}

void Gui::show_friends() {

}

void Gui::delete_friend() {

}

/*to do
 * dodac zabezpieczenie przed podaniem niepoprawnego
 * ip (moze byc w tej klasie, moze byc w TxtFile)
 * dokonczyc pisanie metod tej klasy
 * ogarnac w koncu main
*/