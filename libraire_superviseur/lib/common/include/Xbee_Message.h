//
// Created by senaneuc on 04/05/18.
//

#ifndef LIBRAIRE_SUPERVISEUR_XBEE_MESSAGE_H
#define LIBRAIRE_SUPERVISEUR_XBEE_MESSAGE_H

#include <vector>
#include <iostream>
#define XBEE_INVALID_FRAME (-1)
#define XBEE_CHECKSUM_ERROR (-2)

class Xbee_Message {

private:
    std::vector<unsigned char> data;
    int adress;
    unsigned char checksum;
    int size;
    std::vector<unsigned char> frame;

public:
    std::vector<unsigned char> get_data();
    void set_data(std::vector<unsigned char> *userData);
    int get_adress();

    virtual ~Xbee_Message();

    void set_adress(int newAdress);
    unsigned char get_checksum();
    void set_checksum(unsigned char newChecksum);
    int get_size();
    void set_size(int size);
    std::vector<unsigned char> get_frame();
    void set_frame(std::vector<unsigned char> frame);
};

#endif //LIBRAIRE_SUPERVISEUR_XBEE_MESSAGE_H
