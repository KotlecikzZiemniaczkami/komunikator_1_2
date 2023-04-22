#include <iostream>
#include "Message.h"
//#include "receiver.h"

using namespace std;

int main() {
    Message user;
    user.initialize_wsa();
    user.create_socket();
    user.connect_to_server();
    user.send_data();
    WSACleanup();
    /*receiver user;
    user.create_socket();
    user.bind_socket();
    user.listen_on_socket();
    user.selection();*/

    }