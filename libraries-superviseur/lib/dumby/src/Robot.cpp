//
// Created by senaneuc on 18/07/18.
//

#include <Xbee_Message_Out.h>
#include <Xbee_Message_In.h>
#include "../include/Robot.h"

Robot::Robot(const std::string &serialName, int baudrate, int robot_addr) : Serial(serialName, baudrate) {
    if(robot_addr == 0){
        this->api_mode = false;
    }else{
        this->api_mode = true;
        this->robotId = robot_addr;
    }
}

int Robot::start(void) {
    std::string cmd = this->robotCommande["start"];
    std::string res = robotSend(cmd,1);
    if(this->api_mode == true) { // Pas de checksum ni en \n en mode API

    }else {
        res.pop_back(); // on enleve le \n
        // verification du chksum
        // verification du résultat
    }



//    if(this->api_mode ==  false && checkSumVerify(res) == CHKSUM_ERR){
//        return ROBOT_ERR_COM;
//    }else if(this->api_mode == false){
//        res.pop_back(); // on enleve le checksum
//    }else{}
//     if(!res.compare(this->robotCommande["confirm"])){
//        return ROBOT_OK;
//    }else if(res.compare(this->robotCommande["infirm"])){
//        return ROBOT_ERR_CMD;
//    }else{
//        return ROBOT_ERR_COM;
//    }
}


int Robot::stop() {
    std::string cmd = this->robotCommande["stop"];
    std::string res = robotSend(cmd,1);
    if(this->api_mode ==  false && checkSumVerify(res) == CHKSUM_ERR){
        return ROBOT_ERR_COM;
    }else if(this->api_mode == false){
        res.pop_back(); // on enleve le checksum
    }
    if(!res.compare(this->robotCommande["confirm"])){
        return ROBOT_OK;
    }else if(res.compare(this->robotCommande["infirm"])){
        return ROBOT_ERR_CMD;
    }else{
        return ROBOT_ERR_COM;
    }
}

int Robot::startWithWatchDog() {
    std::string cmd = this->robotCommande["wdStart"];
    std::string res = robotSend(cmd,1);
    if(this->api_mode ==  false && checkSumVerify(res) == CHKSUM_ERR){
        return ROBOT_ERR_COM;
    }else if(this->api_mode == false){
        res.pop_back(); // on enleve le checksum
    }
    if(!res.compare(this->robotCommande["confirm"])){
        return ROBOT_OK;
    }else if(res.compare(this->robotCommande["infirm"])){
        return ROBOT_ERR_CMD;
    }else{
        return ROBOT_ERR_COM;
    }
}

int Robot::resetWatchDog() {
    std::string cmd = this->robotCommande["wdReset"];
    std::string res = robotSend(cmd,1);
    if(this->api_mode ==  false && checkSumVerify(res) == CHKSUM_ERR){
        return ROBOT_ERR_COM;
    }else if(this->api_mode == false){
        res.pop_back(); // on enleve le checksum
    }
    if(!res.compare(this->robotCommande["confirm"])){
        return ROBOT_OK;
    }else if(res.compare(this->robotCommande["infirm"])){
        return ROBOT_ERR_CMD;
    }else{
        return ROBOT_ERR_COM;
    }
}
int Robot::forward() {
    std::string cmd = this->robotCommande["move"];
    cmd.append("=+64000");
    std::string res = robotSend(cmd,1);
    if(this->api_mode ==  false && checkSumVerify(res) == CHKSUM_ERR){
        return ROBOT_ERR_COM;
    }else if(this->api_mode == false){
        res.pop_back(); // on enleve le checksum
    }
    if(!res.compare(this->robotCommande["confirm"])){
        return ROBOT_OK;
    }else if(res.compare(this->robotCommande["infirm"])){
        return ROBOT_ERR_CMD;
    }else{
        return ROBOT_ERR_COM;
    }
}

int Robot::backward() {
    std::string cmd = this->robotCommande["move"];
    cmd.append("=-64000");
    std::string res = robotSend(cmd,1);
    if(this->api_mode ==  false && checkSumVerify(res) == CHKSUM_ERR){
        return ROBOT_ERR_COM;
    }else if(this->api_mode == false){
        res.pop_back(); // on enleve le checksum
    }
    if(!res.compare(this->robotCommande["confirm"])){
        return ROBOT_OK;
    }else if(res.compare(this->robotCommande["infirm"])){
        return ROBOT_ERR_CMD;
    }else{
        return ROBOT_ERR_COM;
    }
}

int Robot::right() {
    std::string cmd = this->robotCommande["turn"];
    cmd.append("=+64000");
    std::string res = robotSend(cmd,1);
    if(this->api_mode ==  false && checkSumVerify(res) == CHKSUM_ERR){
        return ROBOT_ERR_COM;
    }else if(this->api_mode == false){
        res.pop_back(); // on enleve le checksum
    }
    if(!res.compare(this->robotCommande["confirm"])){
        return ROBOT_OK;
    }else if(res.compare(this->robotCommande["infirm"])){
        return ROBOT_ERR_CMD;
    }else{
        return ROBOT_ERR_COM;
    }
}

int Robot::left() {
    std::string cmd = this->robotCommande["turn"];
    cmd.append("=-64000");
    std::string res = robotSend(cmd,1);
    if(this->api_mode ==  false && checkSumVerify(res) == CHKSUM_ERR){
        return ROBOT_ERR_COM;
    }else if(this->api_mode == false){
        res.pop_back(); // on enleve le checksum
    }
    if(!res.compare(this->robotCommande["confirm"])){
        return ROBOT_OK;
    }else if(res.compare(this->robotCommande["infirm"])){
        return ROBOT_ERR_CMD;
    }else{
        return ROBOT_ERR_COM;
    }
}

int Robot::brake() {
    std::string cmd = this->robotCommande["move"];
    cmd.append("=0");
    std::string res = robotSend(cmd,1);
    if(this->api_mode ==  false && checkSumVerify(res) == CHKSUM_ERR){
        return ROBOT_ERR_COM;
    }else if(this->api_mode == false){
        res.pop_back(); // on enleve le checksum
    }
    if(!res.compare(this->robotCommande["confirm"])){
        return ROBOT_OK;
    }else if(res.compare(this->robotCommande["infirm"])){
        return ROBOT_ERR_CMD;
    }else{
        return ROBOT_ERR_COM;
    }
}

int Robot::straight(int cm) {
    return 0;
}

int Robot::turn(int degres) {
    return 0;
}

int Robot::setSpeedForNextMoves(int speed) {
    return 0;
}

int Robot::moveFreely(int motorR, int motorL) {
    return 0;
}

int Robot::getBattery() {


}

std::string Robot::getVersion() {

    return std::__cxx11::string();
}

bool Robot::isBusy() {
    std::string cmd = this->robotCommande["stop"];
    std::string res = robotSend(cmd,1);
    if(this->api_mode ==  false && checkSumVerify(res) == CHKSUM_ERR){
        return ROBOT_ERR_COM;
    }else if(this->api_mode == false){
        res.pop_back(); // on enleve le checksum
    }
    if(!res.compare(this->robotCommande["confirm"])){
        return ROBOT_OK;
    }else if(res.compare(this->robotCommande["infirm"])){
        return ROBOT_ERR_CMD;
    }else{
        return ROBOT_ERR_COM;
    }
}

std::string Robot::robotSend(std::string data, int pdu_size) {
    std::string result;
    if(this->api_mode){
            Xbee_Message_Out tx(data, this->robotId);
            this->send_data(tx.toString());
            std::string dataRx = this->receive(this->response_status_size); // lecture de la trame de status
            Xbee_Message_In status_rx(dataRx);
            dataRx = this->receive(pdu_size+1); // lecture de la réponse du Robot
            Xbee_Message_In response_rx(dataRx);
            result = response_rx.toString();

            delete &response_rx;
            delete &status_rx;
            delete &tx;

            return result;
    }else{
        std::string tx = this->addChechSumTo(data);
        this->send_data(tx);
        std::string rx = this->receive(pdu_size+1);
        std::cout << rx << std::endl;
        return rx;
    }
}

int Robot::checkSumVerify(std::string data) {
    char checkSumResult =0;
    int i;
    for(i =0; i< data.length() -1 ; i++){
        checkSumResult ^=data[i];
    }
    if(checkSumResult == data[i])
        return CHKSUM_OK;
    else
        return CHKSUM_ERR;
}

std::string Robot::addChechSumTo(std::string data) {
    std::string result = data;
    char checkSumResult =0;
    //std::cout << data << std::endl;
    int i;
    for(i =0; i< data.length() ; i++){
        checkSumResult ^=data[i];
    }
    result.push_back(checkSumResult);
    return result;
}


bool Robot::isApi_mode() const {
    return api_mode;
}

int Robot::getRobot_addr() const {
    return robotId;
}

void Robot::setRobot_addr(int robot_addr) {
    Robot::robotId = robot_addr;
}




