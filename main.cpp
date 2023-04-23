#include "Message.h"
#include "receiver.h"

using namespace std;

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
    cout << "HELLO IN FUTURISTIC COMUNICATOR 1.2 :D" << endl;
    cout << "If You wanna send sth select 1 \n If You wanna wait until somebody communicates with You select 2" << endl;
}