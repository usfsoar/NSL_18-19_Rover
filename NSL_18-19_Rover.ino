#include <Arduino.h>
#include "motor_driver.h"
#include "xbee.h"

const byte VAC = 9;

motor_driver motor;
xbee xb;

/**
 * @brief Automatically runs when Arduino initializes.
 */
void setup() {
  Serial.begin(9600);
  Serial.println("NSL 18-19 Test\n");

  pinMode(VAC, OUTPUT);
}

/**
 * @brief Menu for ease of changing functionality.
 *
 * @param c Character corresponding to input key.
 */
void menu(char c) {
  switch (c) {
    case 'w':
      motor.setSpeedPercent(100, 100);
      break;
    case 'a':
      motor.setSpeedPercent(0, 100);
      break;
    case 's':
      motor.setSpeedPercent(-100, -100);
      break;
    case 'd':
      motor.setSpeedPercent(100, 0);
      break;
    case ' ':
      motor.stop();
      break;
    case '1':
      Serial.print("Vacuum ON\n");
      digitalWrite(VAC, LOW);
      break;
    case '2':
      Serial.print("Vacuum OFF\n");
      digitalWrite(VAC, HIGH);
      break;
    case 'q': //Case used for rover deployment, countdowns in 30min intervals
      Serial.print("Rover Deploy In 2MIN\n");
      delay(30000);
      Serial.print("1MIN 30SEC LEFT\n");
      delay(30000);
      Serial.print("1MIN LEFT\n");
      delay(30000);
      Serial.print("30SEC LEFT\n");
      delay(30000);
      Serial.print("Forward!\n");
      motor.setSpeedPercent(100, 100);
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
