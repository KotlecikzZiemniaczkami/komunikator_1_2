cmake_minimum_required(VERSION 3.24)
project(komunikator_1_2)

set(CMAKE_CXX_STANDARD 20)

link_libraries(ws2_32 wsock32)

add_executable(komunikator_1_2 main.cpp User.h User.cpp receiver.h receiver.cpp Message.h Message.cpp TxtFile.h TxtFile.cpp Gui.h Gui.cpp cypher.h cesar.h cesar.cpp Visionera.h Visionera.cpp)
