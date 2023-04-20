cmake_minimum_required(VERSION 3.24)
project(komunikator_1_2)

set(CMAKE_CXX_STANDARD 17)

link_libraries(ws2_32 wsock32)

add_executable(komunikator_1_2 main.cpp User.h User.cpp receiver.h receiver.cpp GuiTr.h GuiTr.cpp Message.h Message.cpp targetver.h)
