//
// Created by senaneuc on 12/06/18.
//

#ifndef BOOST_CLIENT_SERVER_TCP_SERVER_H
#define BOOST_CLIENT_SERVER_TCP_SERVER_H

#define NB_CONNECTION_MAX 5

#include <iostream>
#include <vector>

class Tcp_server {
public:
    Tcp_server(int port);
    int acceptClient();
    int send_data(int clien_fd, std::string mes);
    int broadcast(std::string mes);
    std::string receive(int client_fd, int size);
    virtual ~Tcp_server();

    const std::vector<int> &getSocketClients() const;

    void setSocketClients(const std::vector<int> &socketClients);

private:
    std::vector<int> socketClients;
    int socket_fd;
};


#endif //BOOST_CLIENT_SERVER_TCP_SERVER_H
