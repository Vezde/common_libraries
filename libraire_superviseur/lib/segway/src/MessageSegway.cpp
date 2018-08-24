//
// Created by senaneuc on 29/06/18.
//

#include "../include/MessageSegway.h"

MessageSegway::MessageSegway(std::string rawData) {
    if(!checkRawData(rawData)){ /*Verification des erreurs*/
        throw -1;
    }

    this->raw = rawData;
    int temp;
    float * data;

    temp = rawData.find("<p");// position angulaire
    data = (float *)&rawData[temp+1];
    this->angle = *data;

    temp = rawData.find("<s"); //  vitesse angulaire
    data = (float *)&rawData[temp+1];
    this->angularSpeed = *data;

    temp = rawData.find("<b"); // vitesse linéaire
    data = (float *)&rawData[temp+1];
    this->linearSpeed = *data;

    temp = rawData.find("<v"); // voltage batterie
    data = (float *)&rawData[temp+1];
    this->batteryVoltage = *data;

    temp = rawData.find("<u"); // Presence user
    data = (float *)&rawData[temp+1];
}

bool MessageSegway::checkRawData(std::string raw) {
    std::string a[] = { "<b", "<p", "<u", "<v", "s"};
    if(raw[raw.size()-1] != 'R' || raw[raw.size()-2] != 'X' ){
//        std::cout << "Le message n'est pas entouré de la bonne trame" << std::endl;
        return false;
    }else{
        for(int i = 0; i < 5; i++){
            int b = raw.find(a[i]);
            if(b == std::string::npos){
                return false;
            }
        }
        return true;
    }
}

const std::string &MessageSegway::getRaw() const {
    return raw;
}

void MessageSegway::setRaw(const std::string &raw) {
    MessageSegway::raw = raw;
}

float MessageSegway::getAngle() const {
    return angle;
}

void MessageSegway::setAngle(float angle) {
    MessageSegway::angle = angle;
}

float MessageSegway::getAngularSpeed() const {
    return angularSpeed;
}

void MessageSegway::setAngularSpeed(float angularSpeed) {
    MessageSegway::angularSpeed = angularSpeed;
}

float MessageSegway::getLinearSpeed() const {
    return linearSpeed;
}

void MessageSegway::setLinearSpeed(float linearSpeed) {
    MessageSegway::linearSpeed = linearSpeed;
}

float MessageSegway::getBatteryVoltage() const {
    return batteryVoltage;
}

void MessageSegway::setBatteryVoltage(float batteryVoltage) {
    MessageSegway::batteryVoltage = batteryVoltage;
}

bool MessageSegway::isUserPresence() const {
    return userPresence;
}

void MessageSegway::setUserPresence(bool userPresence) {
    MessageSegway::userPresence = userPresence;
}

MessageSegway::MessageSegway() {
    /*Message Output*/
}
