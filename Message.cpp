//
// Created by Damian on 17.04.2023.
//

#include "Message.h"

Message::Message():User() {
}

//?
void Message::connect_to_server(char& ip) {
    sockaddr_in clientService;
    std::cout<<"Im in: " << &ip<<std::endl;
    clientService.sin_family = AF_INET;
    clientService.sin_port = htons(port);
    clientService.sin_addr.s_addr = inet_addr(&ip);
    std::cout << "Im still in" << std::endl;
    memset(&clientService.sin_zero, 0, 8);
    if (connect(userSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR)
    {
        std::cout<<"Client: connect() - Failed to connect " << std::endl;
        WSACleanup();
    }
    else{
        std::cout << "client connect is ok" << std::endl;
    }
}

void Message::send_data() {
    char mess[200];
    char enc;
    std::printf("What should I send Master (max 200 marks)? ");
    fflush(stdin);
    std::cin.getline(mess,200);
    std::printf("how should I encrypt it Master? 1/2 ");
    fflush(stdin);
    std::cin >> enc;

    if(enc == '1') {///////////////////////////////////////////////////////////////////////////////////////////
        cypher *base = new cesar(3);
        base->encryption(mess);
    }
    else {
        cypher *base = new Visionera("klucz");
        base->encryption(mess);
    }

    int i = 0;
    while (mess[i] !='\0')
        i += 1;
    mess[i + 1] = '\0';
    mess[i] = enc;


    int officialSender = send(userSocket, mess, 200,0);
    if (officialSender == SOCKET_ERROR){
        std::printf("We have a problem with alighting Sir: %d.", WSAGetLastError());
        WSACleanup();
    }
    else
        printf("we have just send %d bytes Sir", officialSender);
}

void Message::making_con() {
    std::cout << "podaj nick: ";
    std::cin >> person.nick;
    person.get_ip();
    char fake_ip[person.ip.length()+1];
    strcpy(fake_ip, person.ip.c_str());
    std::cout<<person.ip<<std::endl;
    connect_to_server(*fake_ip); //reinterpret_cast<char &>(p_ip)
}

void Message::tsend() {
    initialize_wsa();
    create_socket();
    making_con();
    send_data();
    WSACleanup();
}




