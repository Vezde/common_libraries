//
// Created by senaneuc on 14/05/18.
//

#include "../include/Xbee_Message_Out.h"
#include <sstream>
#include <iterator>

unsigned int frame_counter =1;

Xbee_Message_Out::Xbee_Message_Out(std::string data, int address) {
    std::vector<unsigned char> newFrame;
    newFrame.push_back(0x7E);
    newFrame.push_back(0);
    newFrame.push_back(data.size()+5);
    newFrame.push_back(0x01);
    newFrame.push_back(frame_counter);
    frame_counter++;
    if(frame_counter==255) frame_counter = 1;
    newFrame.push_back(address >> 8);
    newFrame.push_back(address&0xFF);
    newFrame.push_back(0x00);
    for(int i =0; i <data.size(); i++){
        newFrame.push_back(data[i]);
    }
    this->set_frame(newFrame);
    this->set_checksum(compute_checksum());
    newFrame.push_back(get_checksum());
    this->set_frame(newFrame);
    this->set_frame(this->escape_chars(this->get_frame()));
}

char Xbee_Message_Out::compute_checksum() {
    unsigned char checksum = 0;
    std::vector<unsigned char> frame = get_frame();
    for (int i =3 ; i < frame.size() ; i++){
        checksum = checksum + (unsigned char) frame[i];
    }
    return (0xFF-checksum);
}

std::vector<unsigned char> Xbee_Message_Out::escape_chars(std::vector<unsigned char> frame) {
    for(int i =1; i < frame.size() ; i++){
        if(frame[i] == 0x7E || frame[i]==0x7D ||
                frame[i]==0x11 || frame[i]==0x13){
            frame.insert(frame.begin(),i+1,frame[i]^0x20);
            frame[i] = 0x7D;
        }
    }
    return frame;
}


std::string Xbee_Message_Out::toString() {
    std::vector<unsigned char> a = this->get_frame();
    std::string result(a.begin(), a.end());
    return result;
}

Xbee_Message_Out::~Xbee_Message_Out() {

}
