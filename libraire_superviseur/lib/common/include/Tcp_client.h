//
// Created by senaneuc on 12/06/18.
//

#ifndef BOOST_CLIENT_SERVER_TCP_CLIENT_H
#define BOOST_CLIENT_SERVER_TCP_CLIENT_H

#include <iostream>

class Tcp_client {
public:
    Tcp_client(std::string address, int port);
    int send_data(std::string mes);
    std::string receive(int size);
    std::string receiveUntil(std::string pattern);
    virtual ~Tcp_client();

private:
    int csocket_fd;
};


#endif //BOOST_CLIENT_SERVER_TCP_CLIENT_H
