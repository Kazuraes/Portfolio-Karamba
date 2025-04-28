
#include "UnoJoy.h"

// Définir les pins
int TrianglePin = 4;
int SquarePin = 5;
int CrossPin = 3;
int CirclePin = 2;
int L1Pin = 8;
int R2Pin = 9;

int LeftPin = A0;    // Pin analogique A0 pour le bouton gauche
int UpPin = A1;      // Pin analogique A1 pour le bouton haut
int RightPin = A2;   // Pin analogique A2 pour le bouton droit
int DownPin = A3;    // Pin analogique A3 pour le bouton bas

int SelectPin = 10;
int StartPin = 12;

void setup(){
  setupPins();
  setupUnoJoy();
}

void loop(){
  // Toujours obtenir les donné du controleur 
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
}

void setupPins(void){
  // Configurer toutes les pins comme entrées avec pull-up activé
  for (int i = 2; i <= 12; i++){
    pinMode(i, INPUT);
    digitalWrite(i, HIGH);
  }

  // Configurer les pins analogiques comme entrées avec pull-up activé
  pinMode(A0, INPUT);
  digitalWrite(A0, HIGH);
  pinMode(A1, INPUT);
  digitalWrite(A1, HIGH);
  pinMode(A2, INPUT);
  digitalWrite(A2, HIGH);
  pinMode(A3, INPUT);
  digitalWrite(A3, HIGH);
}

dataForController_t getControllerData(void){
  // Créer un objet vide pour les données du contrôleur
  dataForController_t controllerData = getBlankDataForController();

  // Lecture des états des boutons
  controllerData.triangleOn = !digitalRead(TrianglePin);  
  controllerData.circleOn = !digitalRead(CirclePin);
  controllerData.squareOn = !digitalRead(SquarePin);
  controllerData.crossOn = !digitalRead(CrossPin);
  controllerData.dpadUpOn = !digitalRead(UpPin);
  controllerData.dpadDownOn = !digitalRead(DownPin);
  controllerData.dpadLeftOn = !digitalRead(LeftPin);
  controllerData.dpadRightOn = !digitalRead(RightPin);
  controllerData.selectOn = !digitalRead(SelectPin);
  controllerData.startOn = !digitalRead(StartPin);
  controllerData.l1On  = !digitalRead(L1Pin );
  controllerData.r1On = !digitalRead(R2Pin);
  
  // Retourner les données
  return controllerData;
}
