cmake_minimum_required(VERSION 3.10)
project(libraire_superviseur)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest lib/rapidjson)
include_directories(lib/googletest/googletest/include lib/googletest/googlemock/include lib/common/include lib/segway/include lib/dumby/include lib/rapidjson)

add_executable(libraire_superviseur main.cpp  lib/common/src/Xbee_Message.cpp lib/common/src/Serial.cpp
        lib/common/src/Tcp_client.cpp lib/common/include/Tcp_server.h lib/common/include/Tcp_client.h lib/common/include/Serial.h lib/common/include/Xbee_Message_Out.h
        lib/common/src/Tcp_server.cpp lib/common/src/Xbee_Message_In.cpp lib/segway/include/MessageSegway.h lib/segway/include/Segway.h lib/segway/src/MessageSegway.cpp lib/segway/src/Segway.cpp
        lib/common/include/Xbee_Message_In.h lib/common/src/Xbee_Message_Out.cpp test/xbee_message_test.cpp
        test/tcp_test.cpp lib/dumby/src/Robot.cpp lib/dumby/include/Robot.h )
target_link_libraries(libraire_superviseur gtest gtest_main)

#lib/dumby/src/Camera.cpp lib/dumby/include/Camera.h lib/dumby/src/Img.cpp lib/dumby/include/Img.h lib/dumby/include/definition.h