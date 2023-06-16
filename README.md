# komunikator_1_2

## A fully functional LAN chat
I made this project, because I really wanted to learn socket programming and make a chat application
which will not collect any user's private information and will work in p2p system.
I hope, You will learn something or use it to something cool too.

## Features
This project has following features:
1. It collects no data about user and works on p2p system, so there is no server to collect information
2. Communication is encryptet
3. All communication is deleted immediately after reading
4. Project is made in easy-to-use blocks so it is easy to redo or implement to other, bigger code

## Functions
This project is a chat application, enabeling communication in local network. It was made for Windows operating system, and it has following functions:
1. sending messeges using Windows sockets
2. receiving messeges using Windows sockets
3. adding addresses to database
4. deleting addresses from database
5. showing the list of "friends" from database
6. encrypting and decrypting messeges

## Why Windows sockets?
The main reason is I wanted to make something fun which will be used for as many people as possible and Windows is the most popular system.
I also used sockets because this technology is truly amazing, and really suits to a simple LAN communicator as the komunikator_1_2.

## diagrams
### class diagram
![image](https://github.com/KotlecikzZiemniaczkami/komunikator_1_2/assets/127383477/59ac0107-073d-4cd0-a5f5-5154bca26000)
### use cases diagram
![image](https://github.com/KotlecikzZiemniaczkami/komunikator_1_2/assets/127383477/8d1d334e-50fc-4e26-afeb-d245a94c3742)

## How to run this project
This project is made for the Windows operating system and it should not be run on any other.
There is no version of this project in .exe on the internet at the moment when the file is being created, so here comes instructions
how to compile it on Clion:
1. Clone this project
2. Open it "with Clion"
3. To work properly this project should be open in cmd, not in clion console
4. If You open it with cmd everything should work properly

## How to remake this project to own uses
This project is based on Windows sockets so if You wants to open it on the other operating system You should equip Your system in 
Win32.dll, libereries: winsock2.h, ws2tcpip.h.
If You open this project on the Windows operating system there should be no problems in remaking or using.

## If You find a bug
please, contact me by email: debickidamian@o2.pl

## Use instructions
Project is made in console, so to select anything You need to select it on a keyboard. Programme shows exact instructions up to date, but there is
needed to read instructions cerfully (some functions are made non-standard, like when You choose who to send message, You need to write his accurately his nickname)
if anything in communication goes wrong, programme will show the error number. In some cases (like when You send the message) programme is carrying on, but
it should be like that. if you encounter such a situation, You should carry on until You will return to main menu.

## Author
Damian Dębicki



