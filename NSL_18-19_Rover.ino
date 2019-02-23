#include <Arduino.h>
#include "motor_driver.h"
#include "xbee.h"

const byte RELAY_1 = 4;
const byte RELAY_2 = 5;

motor_driver motor;
xbee xb;

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
      Serial.print("Both High\n");
      digitalWrite(RELAY_1, HIGH);
      digitalWrite(RELAY_2, HIGH);
      break;
    case '2':
      Serial.print("Both Low\n");
      digitalWrite(RELAY_1, LOW);
      digitalWrite(RELAY_2, LOW);
      break;
    case 'q':
    Serial.print("Rover Deploy\n");
    delay(120000)
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
