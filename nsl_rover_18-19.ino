#include <Arduino.h>
#include "motor_driver.h"
#include "xbee.h"

motor_driver motor;
xbee xb;
char c;
void setup() {
  Serial.begin(9600);
  Serial.println("NSL 18-19 Test\n");
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR2_IN1, OUTPUT);
  pinMode(MOTOR2_IN2, OUTPUT);
}

void menu(char c){
    switch (c){
      case 'w':
        motor.setSpeedPercent(100,100);
        break;
      case 'a':
        motor.setSpeedPercent(0,100);
        break;
      case 's':
        motor.stop();
        break;
      case 'd':
        motor.setSpeedPercent(100,0);
        break;
      case 'r':
        motor.setSpeedPercent(-100,-100);
        break;
    }
}


void loop() { //test code for arduino
menu(xb.readInput());
delay(10);
}