//
// Created by senaneuc on 02/07/18.
//

#ifndef BOOST_CLIENT_SERVER_SEGWAY_H
#define BOOST_CLIENT_SERVER_SEGWAY_H


#include "../../common/include/Serial.h"
#include "MessageSegway.h"

class Segway : Serial {
public:
    Segway(const std::string &serialName, int baudrate);

    /*Lecture d'un message segway puis synchronisation si "autoSync" est à true*/
    MessageSegway* getSensors(void);

    /*Synchronise la reception des messages avec une trame XBEE correcte*/
    void synchronizeComm(void);

    bool isAutoSync() const;
    void setAutoSync(bool autoSync);

private:
    bool autoSync=true;



};


#endif //BOOST_CLIENT_SERVER_SEGWAY_H
