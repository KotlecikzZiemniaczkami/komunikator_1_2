//
// Created by Damian on 30.04.2023.
//

#include "FinalGui.h"

///////////////////////////////////////////////!RISK!///////////////////////////////////////////////////////////////////////////////////////
void FinalGui::send() {
    Gui sending;
    sending.initialize_wsa();
    sending.create_socket();
    sending.making_con();
    sending.send_data();
    WSACleanup();
}

void FinalGui::wait_and_receive() {
    receiver user;
    user.initialize_wsa();
    user.create_socket();
    user.bind_socket();
    user.listen_on_socket();
    user.selection();
    user.accept_connection();
    user.receive_data();
    WSACleanup();
}

void FinalGui::menu() {
    int choice;
    std::cout << "MENU\n1.Send Message\n2.Wait for the Message\n3.See a list of Your friends\n4.Add a friend\n5.Delete a friend\n6.Quit" << std::endl;
    choice = _getwch();
    switch(choice){
        case 49:
            send();
            break;
        case 50:
            wait_and_receive();
            break;
        case 51:
            show_friends();
            break;
        case 52:
            add_user();
            break;
        case 53:
            delete_friend();
            break;
        case 54:
            std::abort();
    }
    clearing();
}
