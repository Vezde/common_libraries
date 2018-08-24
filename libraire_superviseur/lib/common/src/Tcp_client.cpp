//
// Created by senaneuc on 12/06/18.
//

#include "../include/Tcp_client.h"
#include <netinet/in.h>
#include<arpa/inet.h>
#include <zconf.h>
#include <vector>

Tcp_client::Tcp_client(std::string address, int port) {
    if(address.compare("localhost") == true){
        address = "127.0.0.1";
    }
    struct sockaddr_in server;
    this->csocket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(this->csocket_fd < 0 ){
        throw std::invalid_argument("Couldn't create socket");
    }
    server.sin_addr.s_addr = inet_addr(address.c_str());
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if(connect(this->csocket_fd , (struct sockaddr *)&server , sizeof(server)) < 0){
        throw std::invalid_argument("Couldn't connect to server");
    }
}

std::string Tcp_client::receive(int size) {
    char array[size];
    if(recv(this->csocket_fd ,array  , size , 0)>0){
        array[size] = 0;
        return std::string(array);
    }else{
        return std::string();
    }
}
std::string Tcp_client::receiveUntil(std::string pattern) {
    std::string data;
    char lastChar;
    while(data.find(pattern) == false){
        recv(this->csocket_fd,&lastChar,1,0);
        data.push_back(lastChar);
    }
    data.push_back('\0');
    return data;
}

int Tcp_client::send_data(std::string mes) {
    return send(this->csocket_fd, mes.c_str(), mes.size(),0);
}

Tcp_client::~Tcp_client() {
    close(this->csocket_fd);
}