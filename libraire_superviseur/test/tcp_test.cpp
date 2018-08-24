/*
//
// Created by senaneuc on 17/07/18.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../lib/common/include/Tcp_client.h"
#include "../lib/common/include/Tcp_server.h"

namespace {
    class Test_tcp : public testing::Test{
    public:

        Tcp_server * testServer;
        Tcp_client * testClient;
        int clientFd;
        Test_tcp(){
            testServer = new Tcp_server(7777);
            testClient = new Tcp_client("localhost", 7777);
            clientFd = testServer->acceptClient();
        }

        ~Test_tcp(){
            delete testServer;
            delete testClient;
        }
    };
}

TEST_F(Test_tcp, validation_client_emit_server_receive){
    testClient->send_data("Bonjour");
    std::string mes = testServer->receive(clientFd, 7);
    ASSERT_STREQ("Bonjour", mes.c_str());
}
*/
