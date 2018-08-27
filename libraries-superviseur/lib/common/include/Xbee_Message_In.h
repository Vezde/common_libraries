//
// Created by senaneuc on 04/05/18.
//

#ifndef LIBRAIRE_SUPERVISEUR_XBEE_MESSAGE_IN_H
#define LIBRAIRE_SUPERVISEUR_XBEE_MESSAGE_IN_H

#define STATUS_FRAME    0x89
#define RX_16_BIT_FRAME 0x81

#include "Xbee_Message.h"
#include <vector>

class Xbee_Message_In : public Xbee_Message {
private:
    unsigned char apiCmd;
    unsigned char rssi;
    unsigned char options;
    unsigned char status;
    bool isStatus;
public:
    bool isIsStatus() const;

public:
    Xbee_Message_In(std::vector<unsigned char> frame);
    Xbee_Message_In(std::string stringFrame);
    virtual ~Xbee_Message_In();
    char get_rssi();
    char get_api_cmd();
    char get_options();
    char get_status();
    unsigned char verify_checksum();
    std::string toString();
};


#endif //LIBRAIRE_SUPERVISEUR_XBEE_MESSAGE_IN_H
