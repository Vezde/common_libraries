//
// Created by senaneuc on 02/07/18.
//

#include "../include/Segway.h"

Segway::Segway(const std::string &serialName, int baudrate) : Serial(serialName, baudrate) {
}


MessageSegway *Segway::getSensors(void) {
    std::string raw = this->receive(37); // 37 est la taille de la trame naturellement envoyé par le segway
    try{
        MessageSegway *newMes = new MessageSegway(raw);
        return newMes;
    }catch(int error){
        if(autoSync){
            synchronizeComm();
        }
        throw std::invalid_argument("Erreur dans la reception des messages segways");

    }
}

void Segway::synchronizeComm(void) {
    bool synchro = false;
    do{
        std::string mes = this->receive(1);
        if(mes[0] == 'X'){
            std::string mes2 = this->receive(1);
            if(mes2[0] == 'R'){
                synchro = true;
            }
        }
    }while(synchro != true);
}

bool Segway::isAutoSync() const {
    return autoSync;
}

void Segway::setAutoSync(bool autoSync) {
    Segway::autoSync = autoSync;
}
