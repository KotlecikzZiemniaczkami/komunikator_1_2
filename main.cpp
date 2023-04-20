#include <iostream>
#include "Message.h"

using namespace std;

int main() {
    Message user;
    user.initialize_wsa();
    user.create_socket();
    user.connect_to_server();
}