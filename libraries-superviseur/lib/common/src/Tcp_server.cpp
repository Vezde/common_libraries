//
// Created by senaneuc on 12/06/18.
//

#include "../include/Tcp_server.h"
#include <netinet/in.h>
#include <zconf.h>
#include <vector>

Tcp_server::Tcp_server(int port) {
    struct sockaddr_in server;
    this->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(this->socket_fd < 0){
        throw std::invalid_argument("Can not create socket");
    }

    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if(bind(this->socket_fd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        throw std::invalid_argument("Can not bind socket");
    }
    listen(this->socket_fd , NB_CONNECTION_MAX);
}

int Tcp_server::acceptClient() {
    struct sockaddr_in client;
    int c;
    int fd = accept(this->socket_fd,(struct sockaddr *) &client, (socklen_t*)&c);
    this->socketClients.push_back(fd);
    return fd;
}

int Tcp_server::send_data(int client_fd, std::string mes) {
    return write(client_fd, mes.c_str(), mes.size());
}

std::string Tcp_server::receive(int client_fd, int size){
    char tab[size];
    if(recv(client_fd,tab,size,0) >0) {
        tab[size] = 0;
        return std::string(tab);
    }else
        return std::string();

}

int Tcp_server::broadcast(std::string mes) {
    for(int socket : this->socketClients){
        int err = write(socket, mes.c_str(), mes.size());
    }
    return 0;
}

const std::vector<int> &Tcp_server::getSocketClients() const {
    return socketClients;
}

void Tcp_server::setSocketClients(const std::vector<int> &socketClients) {
    Tcp_server::socketClients = socketClients;
}

Tcp_server::~Tcp_server() {
    close(this->socket_fd);
}
