#include <iostream>
#include "lib/common/include/Xbee_Message_In.h"
#include "lib/common/include/Xbee_Message_Out.h"
#include "lib/common/include/Tcp_server.h"
#include "lib/common/include/Tcp_client.h"
#include "lib/dumby/include/Robot.h"
#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "lib/rapidjson/document.h"
#include "lib/rapidjson/writer.h"
#include "lib/rapidjson/stringbuffer.h"
#include "lib/rapidjson/filereadstream.h"
#include <cstdio>
#include <stdio.h>

using namespace rapidjson;

int main(int argc, char* argv[]) {
//    testing::InitGoogleTest(&argc,argv);
//    RUN_ALL_TESTS();

    Tcp_server myServer(1337);
    myServer.acceptClient();
    while(1);
    return 0;
}
