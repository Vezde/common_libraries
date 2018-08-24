//
// Created by senaneuc on 12/06/18.
//

#ifndef BOOST_CLIENT_SERVER_SERIAL_H
#define BOOST_CLIENT_SERVER_SERIAL_H

#include <iostream>

class Serial {
public:
    Serial(std::string serialName, int baudrate);
    int send_data(std::string mes);
    std::string receive(int size);
    virtual ~Serial();

    bool isOpened();

private:
    int fd = -1;
    int setBaudrate(int baudrate);
    char getChar(); // read 1 char
};


#endif //BOOST_CLIENT_SERVER_SERIAL_H
