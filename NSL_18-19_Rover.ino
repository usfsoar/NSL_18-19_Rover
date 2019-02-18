#include <Arduino.h>
#include "motor_driver.h"
#include "xbee.h"

#define RELAY_1 4
#define RELAY_2 5


motor_driver motor;
xbee xb;
char c;


/**
 * @brief Automatically runs when Arduino initializes.
 */
void setup() {
  Serial.begin(9600);
  Serial.println("NSL 18-19 Test\n");

  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
}

/**
 * @brief Menu for ease of changing functionality.
 * 
 * @param c Character corresponding to input key.
 */
void menu(char c){
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
        digitalWrite(RELAY_1, HIGH);
        digitalWrite(RELAY_2, LOW);
        c = '0';
        break;
      case '2':
        Serial.print("Both Low\n");
        digitalWrite(RELAY_1, LOW);
        digitalWrite(RELAY_2, LOW);
        c = '0';
        break;
    }
}

/**
 * @brief Automatically loops while Arduino is running.
 * 
 */
void loop() {
  menu(xb.readInput());
  delay(10);
}
