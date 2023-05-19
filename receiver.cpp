//
// Created by Damian on 17.04.2023.
//

#include "receiver.h"

//receiving data
void receiver::receive_data() {
    //making a space in memory for the message
    char mess[200] = "";
    //receiving and saving data through socket
    int receive_f = recv(acceptSocket, mess, 200,0);
    if(receive_f < 0){
        std::printf("There is a problem in receive_data: %d \n", WSAGetLastError());
    }
    else
        std::printf("Received message: %s \n", mess);
}


//this method is responsible for "binding" a socket
void receiver::bind_socket() {
    sockaddr_in receiverbs; //here an Ip addres lives
    receiverbs.sin_family = AF_INET;
    receiverbs.sin_port = htons(port);
    receiverbs.sin_addr.s_addr = INADDR_ANY;
    memset(&(receiverbs.sin_zero), 0, 8);
    //nearly every socket function is returning an int, if everything is correct it is 0
    if (bind(userSocket, (sockaddr*)&receiverbs, sizeof(sockaddr))==SOCKET_ERROR){
        std::cout << "bind() has a problem" << WSAGetLastError()<< std::endl;
        //if method does not work properly it is important to delete socket
        WSACleanup();
    }
    else{
        std::cout << "bind is working!" << std::endl;
    }
}

//this method is starting listening on a socket
void receiver::listen_on_socket() {
    //1. argument is a socket on witch listening is being conducted, 2. argument is for how many users listen is "waiting"
    if (listen(userSocket, 1) == SOCKET_ERROR)
        std::cout << "we are deaf. There is a failure on Listen " << WSAGetLastError() << std::endl;
    else
        std::cout << "with listen everything is fine. Let's hunt" << std::endl;
}

void receiver::accept_connection() {
    if(agreement == 1) {
        int nlen = sizeof(sockaddr);
        acceptSocket = accept(userSocket, NULL, &nlen);
        if (acceptSocket == INVALID_SOCKET) {
            std::cout << "accept failed: " << WSAGetLastError() << std::endl;
            WSACleanup();
        }
        else {
            std::cout << "sssss! I am hunting a bunny!" << std::endl;
            send(acceptSocket, "Got the connection", 255, 0);
        }
    }
}

//it is just constructor
receiver::receiver():User() {
    agreement = 0;
    acceptSocket = INVALID_SOCKET;
}

//this method is only to have a view how situation looks on a port
//it is showing in real time if somebody wants to connect and for what purpose
void receiver::selection() {
    int select_helping;
    long long nMax;
    timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    fd_set fr, fw, fe;
    nMax = userSocket +1;
    while(true) {
        FD_ZERO(&fr);
        FD_ZERO(&fw);
        FD_ZERO(&fe);
        FD_SET(userSocket, &fr);
        FD_SET(userSocket, &fe);
        select_helping = select(nMax, &fr, &fw, &fe, &tv);
        if (select_helping == 0)
            std::cout << "nothing on a port" << std::endl;
        else if (select_helping > 0) {
            std::cout << "here comes communication" << std::endl;
            if(FD_ISSET(userSocket, &fe))
                std::cout<< "it is an exception. Get away" << std::endl;
            else if(FD_ISSET(userSocket, &fw))
                std::cout<< "ready to write sth" << std::endl;
            else if(FD_ISSET(userSocket, &fr)) {
                std::cout << "ready to read. Sth new come up" << std::endl;
                agreement = 1;
            }
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

/*void receiver::wait_and_receive() {
        initialize_wsa();
        create_socket();
        bind_socket();
        listen_on_socket();
        selection();
        accept_connection();
        receive_data();
        WSACleanup();
}*/
