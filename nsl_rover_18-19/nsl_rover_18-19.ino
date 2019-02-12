#include <Arduino.h>
#include "motor_driver.h"
#include "xbee.h"

motor_driver motor;
xbee xb;
char c;
void setup() {
  Serial.begin(9600);
  Serial.println("NSL 18-19 Test\n");
}

void menu(char c){ //menu for ease of changing functionality
    switch (c){
      case 'w':
        motor.setSpeedPercent(100,100);
        c = '0';
        break;
      case 'a':
        motor.stop();
        motor.setSpeedPercent(0,100);
        c = '0';
        break;
      case 's':
        motor.setSpeedPercent(-100,-100);
        break;
      case 'd':
        motor.stop();
        motor.setSpeedPercent(100,0);
        c = '0';
        break;
      case ' ':
        motor.stop();
        c = '0';
        break;
    }
}


void loop() { //test code for arduino
menu(xb.readInput());
delay(10);
}