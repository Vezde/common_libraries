//
// Created by senaneuc on 12/06/18.
//

#include <fcntl.h>
#include <termios.h>
#include <zconf.h>
#include "../include/Serial.h"

Serial::Serial(std::string serialName, int baudrate) {
    this->fd = open(serialName.c_str(), O_RDWR|O_NOCTTY);
    if(this->fd >= 0){
        struct termios options;
        fcntl(this->fd, F_SETFL,0);
        tcgetattr(this->fd, &options);;
        //options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
        cfsetospeed (&options, this->setBaudrate(baudrate));
        cfsetispeed (&options, this->setBaudrate(baudrate));
        options.c_cc[VMIN]=1;
        options.c_cc[VTIME]=1;
        tcsetattr(this->fd, TCSANOW, &options);
    }else{
        std::cerr << "Can't open serial port" << std::endl;
    }
}

bool Serial::isOpened() {
    if(this->fd >= 0)
        return true;
    else
        return false;
}

int Serial::send_data(std::string mes) {
    write(fd, mes.c_str(), mes.size());
}

std::string Serial::receive(int size) {
    int i = 0;
    std::string mes;
    while(i < size){
        mes += this->getChar();
        i++;
    }
    return mes;

}
Serial::~Serial() {
    close(this->fd);
}

char Serial::getChar() {
    char c;
    if(read(this->fd, &c, 1) > 0){
        return c;
    } else{
        return -1;
    }
}

int Serial::setBaudrate(int baudrate) {
    switch(baudrate){
        case 4800:
            return baudrate = B4800;
        case 9600:
            return baudrate = B9600;
        case 38400:
            return baudrate = B38400;
        case 57600:
            return baudrate = B57600;
        case 115200:
            return baudrate = B115200;
        default:
            std::cerr << "Baudrate not supported" << std::endl;
            return -1;
    }
}
