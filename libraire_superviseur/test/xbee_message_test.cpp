//
// Created by senaneuc on 15/05/18.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../lib/common/include/Xbee_Message_In.h"
#include "../lib/common/include/Xbee_Message_Out.h"
using testing::Eq;

namespace {
    class Test_Message : public testing::Test{
    public:
        std::vector<unsigned char> testRx = {0x7E, 0x00, 0x07, 0x81, 0x01, 0x01, 0x41, 0x00, 0x75, 0x4F, 0x77} ;
        std::vector<unsigned char> testRxStatus = {0x7E, 0x00, 0x03, 0x89, 0x01, 0x00, 0x75};
        std::vector<unsigned char> testTx = {0x7E,0x00,0x08,0x01,0x01,0x01,0x01,0x00,0x75,0x00,0x00,0x86};

        Xbee_Message_In *RxMess;
        Xbee_Message_In *StatusMess;
        Xbee_Message_Out *TxMess;

        std::string data_tx = "uO";

        Test_Message(){
            RxMess = new Xbee_Message_In(testRx);
            StatusMess = new Xbee_Message_In(testTx);
            TxMess = new Xbee_Message_Out(data_tx, 0x101);
            std::cout << std::endl;
        }

        ~Test_Message(){
            delete RxMess;
            delete StatusMess;
            delete TxMess;
        }
    };
}

TEST_F(Test_Message, validation_frame){
    ASSERT_EQ(this->RxMess->get_frame(), this->testRx);
}

TEST_F(Test_Message, validation_checksum){
    ASSERT_EQ(this->RxMess->get_checksum(), this->testRx[this->testRx.size()-1]);
}

TEST_F(Test_Message, validation_address){
    ASSERT_EQ(this->RxMess->get_adress(), (this->testRx[4] << 8) + this->testRx[5]);
}

TEST_F(Test_Message, validation_size){
    ASSERT_EQ(this->RxMess->get_size(), (this->testRx[1] << 8) + this->testRx[2]);
}

TEST_F(Test_Message, rx_validation_rssi){
    ASSERT_EQ(this->RxMess->get_rssi(), this->testRx[6]);
}

TEST_F(Test_Message, rx_validation_options){
    ASSERT_EQ(this->RxMess->get_options(), this->testRx[7]);
}

TEST_F(Test_Message, rx_validation_api_cmd){
    ASSERT_EQ(this->RxMess->get_api_cmd(), (char)this->testRx[3]);
}

TEST_F(Test_Message, rx_validation_status){
    ASSERT_EQ(this->RxMess->get_status(), NULL);
}

TEST_F(Test_Message, rx_status){
    ASSERT_EQ(this->StatusMess->get_status(), testRxStatus[5]);
}

TEST_F(Test_Message, tx_data){
    std::string data = TxMess->toString();
    std::string compareString(testTx.begin(), testTx.end());
    ASSERT_STREQ(data.c_str(),compareString.c_str() );

}