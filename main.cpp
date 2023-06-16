#include "Gui.h"
#include "Message.h"
#include "receiver.h"
using namespace std;


//heart of the program
int main() {
    //Gui start controls local procedures
    Gui start;
    //message controls procedures of sending
    Message mess;
    //receiver is to control messeges receiving
    receiver rec;
    //welcome message
    cout << "HELLO IN FUTURISTIC COMUNICATOR 1.2 :D" << endl;
    //main menu
    while (true) {
        int choice;
        std::cout << "MENU\n1.Send Message\n2.Wait for the Message\n3.See a list of Your friends\n4.Add a friend\n5.Delete a friend\n6.Quit" << std::endl;
        //place taking a choice from user without mark on cmd
        choice = _getwch();
        switch(choice){
            case 49:
                start.show_friends();
                mess.tsend();
                break;
            case 50:
                rec.sum();
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
            //abort function is killing programme
            case 54:
                std::abort();
        }
        //screen is clearing in nice way
        start.clearing();
    }
}