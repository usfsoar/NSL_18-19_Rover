#include <Arduino.h>
#include "xbee.h"

/**
 * @brief SOL_1 controls solenoids, MOTOR_1 controls deployment motor
 */
const byte SOL_1 = 9;
const byte MOTOR_1 = 10;

xbee xb;
/**
 * @brief Automatically runs when Arduino initializes.
 */
void setup() {
  Serial.begin(9600);
  Serial.println("NSL 18-19 Deployment Test\n");

  pinMode(SOL_1, OUTPUT);
  pinMode(MOTOR_1, OUTPUT);
}


/**
 * @brief Menu for motor deployment on proper signal and an emergency stop.
 *
 * @param c Character corresponding to input key.
 */
void menu(char c) {
  switch (c) {
    case 'q':
      Serial.print("Deployment Started\n");
      digitalWrite(SOL_1, LOW);
      delay(1000);
      digitalWrite(MOTOR_1, LOW);
      break;
    case ' ':
      Serial.print("Emergency Stop\n");
      digitalWrite(SOL_1, HIGH);
      digitalWrite(MOTOR_1, HIGH);
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
