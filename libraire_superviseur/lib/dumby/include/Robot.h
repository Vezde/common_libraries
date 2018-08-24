//
// Created by senaneuc on 18/07/18.
//

#ifndef LIBRAIRE_SUPERVISEUR_ROBOT_H
#define LIBRAIRE_SUPERVISEUR_ROBOT_H


#include <Serial.h>
#include <map>
#include <list>

#define ROBOT_ERR_CMD   -1
#define ROBOT_ERR_COM   -2
#define ROBOT_OK        0


#define CHKSUM_OK       0
#define CHKSUM_ERR      -2



class Robot : Serial {
public:
    Robot(const std::string &serialName, int baudrate, int robot_addr = 0);

    int getRobot_addr() const;

    void setRobot_addr(int robot_addr);

    int start(void);
    int stop();
    int startWithWatchDog();
    int resetWatchDog();
    int forward();
    int backward();
    int right();
    int left();
    int brake();
    int straight(int cm);
    int turn(int degres);
    int setSpeedForNextMoves(int speed);
    int moveFreely(int motorR, int motorL);

    /*Commande spé*/
    int getBattery();
    std::string getVersion();
    bool isBusy();

    bool isApi_mode() const;

private:
    bool api_mode;
    int robotId;
    unsigned int response_status_size = 7;
    unsigned int response_robot_size = 11; // à modifier

    std::map <std::string, std::string> robotCommande = {
            {"start", "u"},
            {"stop", "y"},
            {"wdStart", "z"},
            {"wdReset", "r"},
            {"bat", "V"},
            {"version","v"},
            {"busy","b"},
            {"confirm","O"},
            {"infirm", "C"},
            {"move", "M"},
            {"turn","T"},
    };

    int checkSumVerify(std::string data);
    std::string addChechSumTo(std::string data);
    std::string robotSend(std::string messageKey, int pdu_size);
};


#endif //LIBRAIRE_SUPERVISEUR_ROBOT_H
