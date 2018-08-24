    //
// Created by senaneuc on 29/06/18.
//

#ifndef BOOST_CLIENT_SERVER_MESSAGESEGWAY_H
#define BOOST_CLIENT_SERVER_MESSAGESEGWAY_H

#include <iostream>

class MessageSegway {
public:
    MessageSegway(std::string rawData);
    MessageSegway();

    float getAngle() const;

    void setAngle(float angle);

    float getAngularSpeed() const;

    void setAngularSpeed(float angularSpeed);

    float getLinearSpeed() const;

    void setLinearSpeed(float linearSpeed);

    float getBatteryVoltage() const;

    void setBatteryVoltage(float batteryVoltage);

    bool isUserPresence() const;

    void setUserPresence(bool userPresence);

    const std::string &getRaw() const;

    void setRaw(const std::string &raw);

private:
    bool checkRawData(std::string raw);
    std::string raw;
    float angle;
    float angularSpeed;
    float linearSpeed;
    float batteryVoltage;
    bool userPresence;
};


#endif //BOOST_CLIENT_SERVER_MESSAGESEGWAY_H
