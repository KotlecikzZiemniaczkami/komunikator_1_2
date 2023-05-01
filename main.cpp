#include "Message.h"
#include "receiver.h"
#include <cstdlib>
#include "Gui.h"

using namespace std;

//to wait till user press any button and then clear all screan
void clearing(){
    int just_to_close;
    just_to_close = _getwch();
    std::system("clear");
}


void sending(){
    Message user;
    user.initialize_wsa();
    user.create_socket();
    user.connect_to_server();
    user.send_data();
    WSACleanup();
}

void receiving(){
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

int main() {
    int choice;
    cout << "HELLO IN FUTURISTIC COMUNICATOR 1.2 :D" << endl;
    return 0;
}