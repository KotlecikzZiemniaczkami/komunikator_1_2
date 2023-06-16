//
// Created by Damian on 17.04.2023.
//

#include "Message.h"

Message::Message():User() {
}

//connect_to_server is a method responsible for making
//connection with receiver (receiver works like server
void Message::connect_to_server(char& ip) {
    //in sockaddr_in are all information about receiver
    sockaddr_in clientService;
    //AF_INET is responsible for the family of adresses (in this situation ipv4)
    clientService.sin_family = AF_INET;
    //receiver port number
    clientService.sin_port = htons(port);
    //inet_addr remakes text version of ip to computerized version of it
    clientService.sin_addr.s_addr = inet_addr(&ip);
    memset(&clientService.sin_zero, 0, 8);
    //connect is making a connection by a socket
    if (connect(userSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR)
    {
        //if anything goes wrong notification to user will be shown on screen, and after socket is being deleted
        std::cout<<"Client: connect() - Failed to connect " << std::endl;
        WSACleanup();
    }
}

//this method reads message from user, encrypt it and then send
void Message::send_data() {
    //mess is a message which is being taken from user
    char mess[200];
    //enc is a user decision which cypher to use
    char enc;
    std::printf("What should I send Master (max 200 marks)? ");
    fflush(stdin);
    //message is being taken
    std::cin.getline(mess,200);
    std::printf("how should I encrypt it Master? 1/2 ");
    fflush(stdin);
    //decision about encryption is being taken
    std::cin >> enc;

    //message is being encrypted with use of polimorphism
    cypher *base;
    if(enc == '1') {
        //key used in cesar cypher is "3"
        base = new cesar(3);
        //here encryption takes place
        base->encryption(mess);
    }
    else {
        //key used in Visionera is "ababa"
        base = new Visionera("ababa");
        //here encryption takes place
        base->encryption(mess);
    }
    //here is placed a sign in message which says receiver in which cypher
    //message was encrypted
    int i = 0;
    while (mess[i] !='\0')
        i += 1;
    mess[i + 1] = '\0';
    mess[i] = enc;

    //here message is being sent
    int officialSender = send(userSocket, mess, 200,0);
    if (officialSender == SOCKET_ERROR){
        //if sth goes wrong, user will be informed by communicate with an error number
        std::printf("We have a problem with alighting Sir: %d.", WSAGetLastError());
        WSACleanup();
    }
    //if everythin is ok, user will be informed with special communicate
    else
        printf("we have just send %d bytes Sir\n", officialSender);
}

//this method is to make connection
//unlike to connect to server it interacts with user
//by asking him/her for giving a nickname of receiver from base
void Message::making_con() {
    //here is inquiry addressed to a user about nickname of receiver
    std::cout << "write nick: ";
    std::cin >> person.nick;
    //when nickname is known, program by the get_ip() gets ip
    //address from database
    person.get_ip();
    //string is redone to char list
    char fake_ip[person.ip.length()+1];
    strcpy(fake_ip, person.ip.c_str());
    std::cout<<person.ip<<std::endl;
    //there is initializing connection to server
    connect_to_server(*fake_ip);
}

//tsend collects all functions used to send message
//and leave in less complicated way.
void Message::tsend() {
    initialize_wsa();
    create_socket();
    making_con();
    send_data();
    WSACleanup();
}




