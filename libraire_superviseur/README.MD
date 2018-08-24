# Librarie C++ INSA Toulouse
Ce projet regroupe un enssemble de librairie divers en C++. Relativement récent, l’ensemble des librairies n'est pas encore fonctionnelle mais permet de base d'amélioration. Ce projet inclue des morceaux de codes spécifiques aux hardware INSA Toulouse. Dont les projets suivants : 
- "Dumby" le robot utilisé dans le cadre des TP de Temps Réels.
- Le Segway utilisé dans le cadre de TP temps Réel en Spécialité Ingénierie Système
- La mini-voiture autonome utilisé comme projet en 5éme année SIEC
- Potentiellement d'autre à venir :)

## Common

Cette partie permet de décrire certaine classe considérée comme potentiellement commune dans les différents projets. Elle regroupe des librairies pour :
* Port série
*  Modue xbee ( comme port série, ou 802.15.4)
* Clients et Serveurs TCP

>L'utilisation de la norme 802.15.4 ne se fait pour le moment que via l'intermediaire d'une classe message. Il peut être intéréssant d'implémenter une class xbee qui rende transparente ces class intermediaire.

### Port série example
Envoie de donnée
```cpp
#include "lib/common/Serial.h"
Serial mySerial("/dev/ttyUSB0", 115200);
if(mySerial.isOpened()){
	mySerial.send_data("bonjour");
}
```
Réception de donnée
```C
mySerial.receive(7); // Reception de 7 caractéres 
```

### 802.15.4
Envoie
```cpp
#include "lib/common/Serial.h"
#include "lib/common/Xbee_Message_Out.h"
#include "lib/common/Xbee_Message_In.h"
...

Serial mySerial("/dev/ttyUSB0", 115200);
if(mySerial.isOpened()){
	Xbee_Message_Out newData("Bonjour")
	mySerial.send_data(newData.toString());
}
```
Reception
```cpp
string rawData = mySerial.receive(7);
Xbee_Message_In frame(rawData);
cout << "Parsed data " << frame.toString() << endl;
```

### Tcp_client et serveur example
```cpp
#include "lib/common/Tcp_client.h"
#include "lib/common/Tcp_server.h"
...

Tcp_server myServer(7777);
Tcp_client myClient("localhost", 7777);
int fd = myServer.acceptClient();
myClient.send_data("Bonjour");
string message = myServer.receive(fd, 7);
```

## Dumby (non fonctionnel pour cause d'un \n non traité)
>Note:  Pour le TP il est necessaire d'utiliser un noyaux temps réel de linux ainsi que la librairie xenomai3 (mercury au moins pour l'API)

Les classes dans le dossier dumby sont spécifique au TP de Temps réel de 4éme année à l'INSA de Toulouse. Elles sont directement en lien avec le hardware de ce TP.
![](http://gei.insa-toulouse.fr/_contents-images/ametys-internal%253Asites/dgei/ametys-internal%253Acontents/controle-robot-article/_metadata/content/_data/mini-robot-stm32.PNG_416x453)
> Robot dumby utilisé en TP

Ces librairies contienent donc le necessaire afin communiquer avec le robot et d'utiliser une camera afin de détecter celui-ci dans une arêne. 
Il y a donc : 
* Classe Camera qui permet d'acquerir d'initialiser et d'acquerir de nouvelle image
* Classe Img qui permet de réalisé directement de par ses méthodes les traitements necessaire à la détection et à l'affichage du robot.
* Classe Robot qui permet de communiquer avec le robot directement de par les méthodes de l'objet instancié. 

> **Attention !** Afin que cette partie fonctionne correctmeent il est necessaire d'avoir installé opencv v3 ainsi que les utilitaire (utilisation des librairies aruco)
> D'autre part la plupart des fonctions ne sont pas encore implémenté. Je souhaite pouvoir modifier directement la PDU des messages directement dans un .json.

### Exemple Traitement video
```cpp
#include "lib/dumby/Camera.h"
#include "lib/dumby/Img.h"
#include "lib/dumby/definition.h"
...

Camera piCam(xs); // prends xs, sm, md, ou lg comme argument correspond à la taille de l'image
piCam.open_camera(); // ouvre la camera par défaut
Image newImg = picam.grab_image(); // capture l'image
List<Position> robotList = newImg.search_aruco(); // recherche les robots (avec un shiled aruco ici)
newImg.draw_all_robots(robotList); //les dessine sur l'image
newImg.toJpg(); // compress l'image au format jpg et retourne un vector<unsigned char>
```
### Exemple piloter dumby
En mode Serial
```cpp
#include "/lib/dumby/robot.h
...

Robot dumby("/dev/ttyUSB0", 115200);
dumby.start(); // Necessite le robot soit électriquement alimenté (pile + bouton appuyé) 
dumby.left(); 
dumby.forward();
dumby.brake();
```

En mode API ( Si robot compatible)

```cpp
#include "/lib/dumby/robot.h
...

Robot dumby("/dev/ttyUSB0", 115200, 0x115); // on donne l'adresse du robot
dumby.start(); // Necessite le robot soit électriquement alimenté (pile + bouton appuyé) 
dumby.left(); 
dumby.forward();
dumby.brake();
```
L'idée serait ainsi de donner la possibilité d'instancier plusieurs robots en mode API et de leurs donnée des ordre différents.

## Segway

L'objet Segway est une spécialisation de la classe serial et permet de communiquer, lire des messages via liaison série avec le hardware Gyropode (appelé communément segway). Ce hardware est utilisé à l'INSA Toulouse dans le cadre de TP 4éme année Ingénierie Système.

### Exemple 

```cpp
#include "/lib/segway/Segway.h"
#include "/lib/segway/MessageSegway.h"
...

Segway mySegway("/dev/ttyUSB0", 115200);
MessageSegway newMessage = mySegway.getSensors();
cout << newMessage.getAngle() << endl;
cout << newMessage.getLinearSpeed() << endl;
cout << newMessage.getBatteryVoltage() << endl;
...
```

# Architecture du projet

L'idée serait de garder une architecture standart et de normaliser les moyens de communication entre les différents
acteurs du systéme.

