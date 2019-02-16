#include <Arduino.h>
#include "motor_driver.h"
#include "xbee.h"

#define RELAY1 4
#define RELAY2 5


motor_driver motor;
xbee xb;
char c;


void setup() {
  Serial.begin(9600);
  Serial.println("NSL 18-19 Test\n");

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
}

void menu(char c){ //menu for ease of changing functionality
    switch (c){
      case 'w':
        motor.setSpeedPercent(100,100);
        c = '0';
        break;
      case 'a':
        motor.setSpeedPercent(0,100);
        c = '0';
        break;
      case 's':
        motor.setSpeedPercent(-100,-100);
        break;
      case 'd':
        motor.setSpeedPercent(100,0);
        c = '0';
        break;
      case ' ':
        motor.stop();
        c = '0';
        break;
      case '1':
        Serial.print("Both High\n");
        digitalWrite(RELAY1, HIGH);
        digitalWrite(RELAY2, LOW);
        c = '0';
        break;
      case '2':
        Serial.print("Both Low\n");
        digitalWrite(RELAY1, LOW);
        digitalWrite(RELAY2, LOW);
        c = '0';
        break;
    }
}

void loop() { //test code for arduino
menu(xb.readInput());
delay(10);
}
