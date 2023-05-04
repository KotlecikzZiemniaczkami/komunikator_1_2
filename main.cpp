#include "Message.h"
#include "receiver.h"
#include <cstdlib>
#include "FinalGui.h"

using namespace std;

//to wait till user press any button and then clear all screan
void clearing(){
    int just_to_close;
    just_to_close = _getwch();
    std::system("clear");
}

int main() {
    FinalGui start;
    cout << "HELLO IN FUTURISTIC COMUNICATOR 1.2 :D" << endl;
    while (true) {
        start.menu();
    }
    return 0;
}