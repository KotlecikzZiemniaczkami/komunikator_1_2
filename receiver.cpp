//
// Created by Damian on 17.04.2023.
//

#include "receiver.h"

//initialize the socket
void receiver::create_socket(){
    receiverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (receiverSocket < 0){ // zmienilem z receiverSocket == INVALID_SOCKET na receiverSocket< 0 22.04 2023 11:14
        std::cout << "socket() has failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
    }
    else{
        std::cout << "socket() is cool" << std::endl;
    }
}

void receiver::receive_data() {
    char mess[200] = "";
    int receive_f = recv(acceptSocket, mess, 200,0);
    if(receive_f < 0){
        std::printf("sth have fucked in receive_data: %d \n", WSAGetLastError());
    }
    else
        std::printf("Received message: %s \n", mess);
}

void receiver::disconn() {

}

void receiver::bind_socket() {
    sockaddr_in receiverbs; //here an Ip addres lives
    receiverbs.sin_family = AF_INET;
    receiverbs.sin_port = htons(port);
    receiverbs.sin_addr.s_addr = INADDR_ANY;
    memset(&(receiverbs.sin_zero), 0, 8);
    if (bind(receiverSocket, (sockaddr*)&receiverbs, sizeof(sockaddr))==SOCKET_ERROR){
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
    port = 55555;
    receiverSocket = INVALID_SOCKET;
    wVersionRequested = MAKEWORD(2, 2);
    WSAData wsaData{};
    wsaError = WSAStartup(wVersionRequested, &wsaData);
    SOCKET acceptSocket = INVALID_SOCKET;
    if(wsaError != 0){
        std::cout << "The Winsock dll not found!" << std::endl;
    }
    else{
        std::cout << "The Winsock dll found!" << std::endl;
    }

}

void receiver::selection() {
    int select_helping;
    long long nMax;
    timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    fd_set fr, fw, fe;
    nMax = receiverSocket +1;
    while(true) {
        FD_ZERO(&fr);
        FD_ZERO(&fw);
        FD_ZERO(&fe);
        FD_SET(receiverSocket, &fr);
        FD_SET(receiverSocket, &fe);
        select_helping = select(nMax, &fr, &fw, &fe, &tv);
        if (select_helping == 0)
            std::cout << "nothing on a port" << std::endl;
        else if (select_helping > 0) {
            std::cout << "here comes communication" << std::endl;
            if(FD_ISSET(receiverSocket, &fe))
                std::cout<< "it is an exception. Get away" << std::endl;
            else if(FD_ISSET(receiverSocket, &fw))
                std::cout<< "ready to write sth" << std::endl;
            else if(FD_ISSET(receiverSocket, &fr))
                std::cout<< "ready to read. Sth new come up" << std::endl;

            break;
        }
        else {
            std::cout << "sth failed in select" << std::endl;
            exit(EXIT_FAILURE);
        }
        std::cout << "After the select call: " << fr.fd_count << std::endl;
        Sleep(2000);
    }
}

/*do poprawy jak wszystko będzie dzialac:
1. podzielic konstruktor na konstruktor oraz funkcje wykonujaca sprawdzenie
2. stworzyc odzielna funkcje/metode na zamykanie socketu w przypadku bledu
3. wspolne funkcje dla message i receiver zamienic na normalne dziedziczenie
 */