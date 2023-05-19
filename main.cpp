
#include "Gui.h"

using namespace std;

int main() {
    Gui start;
    cout << "HELLO IN FUTURISTIC COMUNICATOR 1.2 :D" << endl;
    while (true) {
        int choice;
        std::cout << "MENU\n1.Send Message\n2.Wait for the Message\n3.See a list of Your friends\n4.Add a friend\n5.Delete a friend\n6.Quit" << std::endl;
        choice = _getwch();
        switch(choice){
            case 49:
                start.show_friends();
                start.send();
                break;
            case 50:
                start.wait_and_receive();
                break;
            case 51:
                start.show_friends();
                break;
            case 52:
                start.add_user();
                break;
            case 53:
                start.delete_friend();
                break;
            case 54:
                std::abort();
        }
        start.clearing();
    }
    return 0;
}