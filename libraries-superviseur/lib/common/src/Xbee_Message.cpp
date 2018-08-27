//
// Created by senaneuc on 04/05/18.
//

#include <iterator>
#include "../include/Xbee_Message.h"


std::vector<unsigned char> Xbee_Message::get_data() {
    return this->data;
}

void Xbee_Message::set_data(std::vector<unsigned char> *userData) {
    this->data = *userData;
}

int Xbee_Message::get_adress(){
    return this->adress;
}

void Xbee_Message::set_adress(int newAdress) {
    this->adress = newAdress;
}

unsigned char Xbee_Message::get_checksum() {
    return this->checksum;
}

void Xbee_Message::set_checksum(unsigned char newChecksum) {
    this->checksum= newChecksum;
}

int Xbee_Message::get_size(){
    return this->size;
}

void Xbee_Message::set_size(int size) {
    this->size = size;
}

std::vector<unsigned char> Xbee_Message::get_frame() {
    return this->frame;
}

void Xbee_Message::set_frame(std::vector<unsigned char> frame) {
    this->frame = frame;
}

Xbee_Message::~Xbee_Message() {

}
