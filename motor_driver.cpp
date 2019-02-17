// Basic sketch for trying out the Adafruit DRV8871 Breakout
#include "motor_driver.h"
#include <Arduino.h>

const byte MOTOR1_IN1 = 8;  // declares motor 1 and 2 pins
const byte MOTOR1_IN2 = 9;
const byte MOTOR2_IN1 = 10;
const byte MOTOR2_IN2 = 11;

const int MAX_PWM = 255;

/**
 * @brief Convert a percentage between -100 and 100 to the equivalent PWM value.
 *
 * Matches the range `[-100, 100]` to the range `[-MAX_PWM, MAX_PWM]`.
 *
 * @param percent
 * @return int
 */
int motor_driver::convertPercent(double percent) {
  if (percent > 100) {
    percent = 100;
  }
  if (percent < -100) {
    percent = -100;
  }

  return (percent / 100.0 * MAX_PWM);
}

/**
 * @brief Set the motor speeds as a percentage of the maximum speed.
 *
 * @param leftPercent Perent in range `[-100, 100]` to set the left motor.
 * @param rightPercent Perent in range `[-100, 100]` to set the right motor.
 */
void motor_driver::setSpeedPercent(double leftPercent, double rightPercent) {
  int leftSpeed = convertPercent(leftPercent);  // converts percent to pwm
                                                // values
  int rightSpeed = convertPercent(rightPercent);

  if (leftSpeed > 0) {  // For positive values
    digitalWrite(MOTOR1_IN1, LOW);
    analogWrite(MOTOR1_IN2, leftSpeed);
    Serial.print("\nPos Left %: ");
    Serial.print(leftSpeed);
  }
  if (rightSpeed > 0) {
    digitalWrite(MOTOR2_IN1, LOW);
    analogWrite(MOTOR2_IN2, rightSpeed);
    Serial.print("\nPos Right %: ");
    Serial.print(rightSpeed);
  }

  if (leftSpeed < 0) {  // For negative values
    digitalWrite(MOTOR1_IN2, LOW);
    Serial.print("\nNeg Left %: ");
    Serial.print(leftSpeed);
    leftSpeed *= -1;  // set the negative value back to positve
    analogWrite(MOTOR1_IN1, leftSpeed);
  }

  if (rightSpeed < 0) {
    digitalWrite(MOTOR2_IN2, LOW);
    Serial.print("\nNeg Right %: ");
    Serial.print(rightSpeed);
    rightSpeed *= -1;
    analogWrite(MOTOR2_IN1, rightSpeed);
  }

  if (rightSpeed == 0) {
    digitalWrite(MOTOR2_IN1, LOW);
    digitalWrite(MOTOR2_IN2, LOW);
  }

  if (leftSpeed == 0) {
    digitalWrite(MOTOR1_IN1, LOW);
    digitalWrite(MOTOR1_IN2, LOW);
  }
}

/**
 * @brief Set the motor speeds as a PWM value.
 *
 * Values should be on range [-255, 255]. Values greater than 255 or less than
 * -255 will be truncated to the range.
 * 
 * @param leftPWM Value to set the left motor.
 * @param rightPWM Value to set the right motor.
 */
void motor_driver::setSpeedPWM(int leftPWM, int rightPWM) {
  setPWM(leftPWM, MOTOR1_IN2, MOTOR1_IN1);
  setPWM(rightPWM, MOTOR2_IN2, MOTOR2_IN1);

  Serial.println("Set left motor to: ");
  Serial.print(leftPWM);
  Serial.println("Set right motor to: ");
  Serial.print(rightPWM);
}

/**
 * @brief Set PWM output. Allows for separate positive and negative outputs.
 * 
 * If the PWM value is in the range (0, inf], will set the pinIfPositive pin to
 * the value (truncating values greater than 255 to 255). If the PWM value is
 * in the range (-inf, 0), will set the negative pin, again truncating. The
 * other pin will always be set to 0.
 * 
 * @param pwmValue Value to use, on the range [-255, 255]. Other values will be
 *   truncated to that range.
 * @param pinIfPositive Pin to set if the value is positive.
 * @param pinIfNegative Pin to set if the value is negative.
 */
void motor_driver::setPWM(int pwmValue, int pinIfPositive, int pinIfNegative) {
  int positiveOutput = 0, negativeOutput = 0;

  if (pwmValue > MAX_PWM) {
    positiveOutput = MAX_PWM;
  } else if (pwmValue > 0) {
    positiveOutput = pwmValue;
  } else if (pwmValue < -MAX_PWM) {
    negativeOutput = MAX_PWM;
  } else {
    negativeOutput = -pwmValue;
  }

  analogWrite(pinIfPositive, positiveOutput);
  analogWrite(pinIfNegative, negativeOutput);
}

/**
 * @brief Stop both motors.
 */
void motor_driver::stop() {
  setPWM(0, MOTOR1_IN2, MOTOR1_IN1);
  setPWM(0, MOTOR2_IN2, MOTOR2_IN1);

  Serial.println("Stopped both motors.");
}

/**
 * @brief Constructor to set pins as outputs.
 */
motor_driver::motor_driver() {
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR2_IN1, OUTPUT);
  pinMode(MOTOR2_IN2, OUTPUT);
}

motor_driver::~motor_driver() {
  // Empty
}
