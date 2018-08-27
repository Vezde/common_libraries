//
// Created by senaneuc on 14/05/18.
//

#ifndef LIBRAIRE_SUPERVISEUR_XBEE_MESSAGE_OUT_H
#define LIBRAIRE_SUPERVISEUR_XBEE_MESSAGE_OUT_H

#include "Xbee_Message.h"
#include <iostream>
#include <vector>

extern unsigned int frame_counter;

class Xbee_Message_Out : public Xbee_Message {
public:
    Xbee_Message_Out(std::string data, int address);

    virtual ~Xbee_Message_Out();

    std::string toString();
private:
    char compute_checksum();
    std::vector<unsigned char> escape_chars(std::vector<unsigned char> data); // 802.15.4 escape char
    std::vector<unsigned char> escape_chars_robot(std::vector<unsigned char> data); // escape char for Robot


};


#endif //LIBRAIRE_SUPERVISEUR_XBEE_MESSAGE_OUT_H
