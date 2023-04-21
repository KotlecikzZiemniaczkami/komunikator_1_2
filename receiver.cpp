//
// Created by Damian on 17.04.2023.
//

#include "receiver.h"

void receiver::create_socket(){
    receiverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (receiverSocket == INVALID_SOCKET){
        std::cout << "socket() has failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
    }
    else{
        std::cout << "socket() is cool" << std::endl;
    }
}

void receiver::receive_data() {
    char mess[200] = "";
    int receive_f = recv(receiverSocket, mess, 200,0);
    if(receive_f < 0){
        std::printf("sth have fucked in receive_data: %d \n", WSAGetLastError());
    }
    else
        std::printf("Received message: %s \n", mess);
}

void receiver::disconn() {

}

void receiver::bind_socket() {
    sockaddr_in receiverbs{}; //here an Ip addres lives
    receiverbs.sin_family = AF_INET;
    InetPton(AF_INET, "127.0.0.1", &receiverbs.sin_addr);//place for sender's ip
    receiverbs.sin_port = htons(port);
    if (bind(receiverSocket, (SOCKADDR*)&receiverbs, sizeof(receiverbs))==SOCKET_ERROR){
        std::cout << "bind() has a problem" << WSAGetLastError()<< std::endl;
        WSACleanup();
    }
    else{
        std::cout << "bind is working!" << std::endl;
    }
}

void receiver::listen_on_socket() {
    if (listen(receiverSocket, 1) == SOCKET_ERROR)
        std::cout << "we are deaf. There is a failure on Listen " << WSAGetLastError() << std::endl;
    else
        std::cout << "with listen everything is fine. Let's hunt" << std::endl;
}

void receiver::accept_connection() {
    SOCKET acceptSocket;
    acceptSocket = accept(receiverSocket, NULL, NULL);
    if (acceptSocket == INVALID_SOCKET){
        std::cout << "accept failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
    }
    else
        std::cout << "sssss! I am hunting a bunny!" << std::endl;
}

receiver::receiver() {
    port = 66666;
    receiverSocket = INVALID_SOCKET;
    wVersionRequested = MAKEWORD(2, 2);
    WSAData wsaData{};
    wsaError = WSAStartup(wVersionRequested, &wsaData);
    if(wsaError != 0){
        std::cout << "The Winsock dll not found!" << std::endl;
    }
    else{
        std::cout << "The Winsock dll found!" << std::endl;
    }

}

/*do poprawy jak wszystko będzie dzialac:
1. podzielic konstruktor na konstruktor oraz funkcje wykonujaca sprawdzenie
2. stworzyc odzielna funkcje/metode na zamykanie socketu w przypadku bledu
3. wspolne funkcje dla message i receiver zamienic na normalne dziedziczenie
 */