//
// Created by senaneuc on 04/05/18.
//

#include <iostream>
#include "../include/Xbee_Message_In.h"
#include <sstream>
#include <iterator>

Xbee_Message_In::Xbee_Message_In(std::vector<unsigned char> frame) {
    set_size((frame[1] << 8) + frame[2]);
    this->set_frame(frame);
    unsigned char checksum = this->verify_checksum();
    if(checksum != frame[frame.size()-1])
        throw XBEE_CHECKSUM_ERROR;
    else {
        set_checksum(checksum);
        this->apiCmd = frame[3];
        if (this->apiCmd == STATUS_FRAME) { /*Transmit Frame Status*/
            this->isStatus = true;
            this->status = frame[5];
            if ((this->status<0) && (this->status>4)){
                throw XBEE_INVALID_FRAME;
            }
        } else if (this->apiCmd == RX_16_BIT_FRAME) {
            this->isStatus = false;
            this->status=NULL;
            this->set_adress((frame[4] << 8) + frame[5]);
            this->rssi = frame[6];
            this->options = frame[7];
            if ((this->options<0) && (this->options>2)){
                throw XBEE_INVALID_FRAME;
            }
            std::vector<unsigned char> temp;
            for (int i = 0; i < frame.size() - (this->get_size()+2); i++) {
                temp.push_back(frame[i + (this->get_size()+1)]);
            }
            this->set_data(&temp);
        }
    }
}

Xbee_Message_In::Xbee_Message_In(std::string stringFrame) {
    std::vector<unsigned char> frame(stringFrame.begin(), stringFrame.end());
    set_size((frame[1] << 8) + frame[2]);
    this->set_frame(frame);
    unsigned char checksum = this->verify_checksum();
    if(checksum != frame[frame.size()-1])
        throw XBEE_CHECKSUM_ERROR;
    else {
        set_checksum(checksum);
        this->apiCmd = frame[3];
        if (this->apiCmd == STATUS_FRAME) { /*Transmit Frame Status*/
            this->isStatus = true;
            this->status = frame[5];
            if ((this->status<0) && (this->status>4)){
                throw XBEE_INVALID_FRAME;
            }
        } else if (this->apiCmd == RX_16_BIT_FRAME) {
            this->isStatus = false;
            this->status=NULL;
            this->set_adress((frame[4] << 8) + frame[5]);
            this->rssi = frame[6];
            this->options = frame[7];
            if ((this->options<0) && (this->options>2)){
                throw XBEE_INVALID_FRAME;
            }
            std::vector<unsigned char> temp;
            for (int i = 0; i < frame.size() - (this->get_size()+2); i++) {
                temp.push_back(frame[i + (this->get_size()+1)]);
            }
            this->set_data(&temp);
        }
    }
}
Xbee_Message_In::~Xbee_Message_In() {

}

char Xbee_Message_In::get_rssi() {
    return this->rssi;
}

char Xbee_Message_In::get_options() {
    return options;
}

char Xbee_Message_In::get_status() {
    return status;
}

char Xbee_Message_In::get_api_cmd() {
    return apiCmd;
}

unsigned char Xbee_Message_In::verify_checksum() {
    unsigned char checksum = 0;
    std::vector<unsigned char> frame = get_frame();
    for (int i =3; i< this->get_size()+3; i++){
        checksum = checksum + (unsigned char) frame[i];
    }
    return (0xFF-checksum);
}

std::string Xbee_Message_In::toString() {
    std::vector<unsigned char> a = this->get_data();
    std::string result(a.begin(), a.end());
    return result;
}

bool Xbee_Message_In::isIsStatus() const {
    return isStatus;
}

