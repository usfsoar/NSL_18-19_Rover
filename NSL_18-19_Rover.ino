#include <Arduino.h>
#include "motor_driver.h"
#include "xbee.h"

motor_driver motor;
xbee xb;
char c;
#define DEPLOY1 12 //temp declaration for deployment
#define DEPLOY2 13

void setup() {
  Serial.begin(9600);
  Serial.println("NSL 18-19 Test\n");

  pinMode(DEPLOY1, OUTPUT);
  pinMode(DEPLOY2, OUTPUT);
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
        digitalWrite(DEPLOY1, HIGH);
        digitalWrite(DEPLOY2, HIGH);
        c = '0';
        break;
      case '2':
        digitalWrite(DEPLOY1, LOW);
        digitalWrite(DEPLOY2, LOW);
        c = '0';
        break;
    }
}


void loop() { //test code for arduino
menu(xb.readInput());
delay(10);
}