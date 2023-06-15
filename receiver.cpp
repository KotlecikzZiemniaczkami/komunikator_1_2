//
// Created by Damian on 17.04.2023.
//

#include "receiver.h"

//receiving data
void receiver::receive_data() {
    //making a space in memory for the message
    char mess[200] = "";
    // int will count not empty places in mess
    int i = 0;
    //receiving and saving data through socket
    int receive_f = recv(acceptSocket, mess, 200,0);
    if(receive_f >= 0){
        //enc takes an info from message which cypher was used
        //this information is at the end of message
        char enc;
        //finding the information of cypher used
        while (mess[i] !='\0')
            i += 1;
        enc = mess[i-1];
        //decrypting
        if(enc == '1') {
            cypher *base = new cesar(3);
            base->decryption(mess);
        }
        else {
            cypher *base = new Visionera("ababa");
            base->decryption(mess);
        }
    }


    if(receive_f < 0){
        //if receiving fails there is a comunicat shown about where fail was
        std::printf("There is a problem in receive_data: %d \n", WSAGetLastError());
    }
    else{
        //there is showing received message if everything is ok
        std::cout << "Received message:";
        for(int w = 0; w < i-1; w++){
            std::cout<< mess[w];
        }
        std::cout<<std::endl;
    }

}


//this method is responsible for "binding" a socket
void receiver::bind_socket() {
    //in sockaddr_in is every single information about receiver
    sockaddr_in receiverbs; //here an Ip addres lives
    //AF_INET is responsible for the family of adresses (in this situation ipv4)
    receiverbs.sin_family = AF_INET;
    receiverbs.sin_port = htons(port);
    //INADDR_ANY  binds the socket to all available interfaces.
    receiverbs.sin_addr.s_addr = INADDR_ANY;
    memset(&(receiverbs.sin_zero), 0, 8);
    //nearly every socket function is returning an int, if everything is correct it is 0
    if (bind(userSocket, (sockaddr*)&receiverbs, sizeof(sockaddr))==SOCKET_ERROR){
        std::cout << "bind() has a problem" << WSAGetLastError()<< std::endl;
        //if method does not work properly it is important to delete socket
        WSACleanup();
    }
}

//this method is starting listening on a socket
void receiver::listen_on_socket() {
    //1. argument is a socket on witch listening is being conducted, 2. argument is for how many users listen is "waiting"
    if (listen(userSocket, 1) == SOCKET_ERROR)
        std::cout << "we are deaf. There is a failure on Listen " << WSAGetLastError() << std::endl;
}


//this method accepts connection when any shows up
void receiver::accept_connection() {
    if(agreement == 1) {
        int nlen = sizeof(sockaddr);
        //is accepting connection
        acceptSocket = accept(userSocket, NULL, &nlen);
        if (acceptSocket == INVALID_SOCKET) {
            //shows error code
            std::cout << "accept failed: " << WSAGetLastError() << std::endl;
            WSACleanup();
        }
        else {
            //sends feedback to sender that everything is ok
            send(acceptSocket, "Got the connection", 255, 0);
        }
    }
}

//it is just constructor
receiver::receiver():User() {
    agreement = 0;
    acceptSocket = INVALID_SOCKET;
}

//this method is only to have a view how is situation on a port
//it is showing in real time if somebody wants to connect and for what purpose
void receiver::selection() {
    int select_helping;
    long long nMax;
    timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    //reading, writing, exception (sth failed)
    fd_set fr, fw, fe;
    nMax = userSocket +1;
    //while loop checks if somebody is on a port adn on what purpose
    while(true) {
        FD_ZERO(&fr);
        FD_ZERO(&fw);
        FD_ZERO(&fe);
        FD_SET(userSocket, &fr);
        FD_SET(userSocket, &fe);
        //actualising information about situation on a port
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
