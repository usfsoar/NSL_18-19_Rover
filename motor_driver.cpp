/**
 * @file motor_driver.cpp
 * @brief Methods for interacting with PWM motor driver.
 */

#include "motor_driver.h"
#include <Arduino.h>

const byte MOTOR1_IN1 = 13; //MOTOR 1 as LEFT
const byte MOTOR1_IN2 = 12;
const byte MOTOR2_IN1 = 11; //MOTOR 2 as RIGHT
const byte MOTOR2_IN2 = 10;

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
 * 
 * @returns The input value, unless the input value falls outside the range
 *   [-255, 255], in which case it returns the truncated value.
 */
int motor_driver::setPWM(int pwmValue, int pinIfPositive, int pinIfNegative) {
  int positiveOutput = 0, negativeOutput = 0;

  // By changing the pwmValue here instead of the output variables, we can
  // return the truncated value for output use.
  if (pwmValue > 255) {
    pwmValue = 255;
  } else if (pwmValue < -255) {
    pwmValue = -255;
  }
  
  if (pwmValue > 0) {
    positiveOutput = pwmValue;
  } if (pwmValue < 0) {
    negativeOutput = -pwmValue;
  }

  analogWrite(pinIfPositive, positiveOutput);
  analogWrite(pinIfNegative, negativeOutput);

  return pwmValue;
}

/**
 * @brief Convert a percentage between -100 and 100 to the equivalent PWM value.
 *
 * Matches the range `[-100, 100]` to the range `[-255, 255]`. Does not
 * truncate values outside the allowable range (ie, 110 input will output 280).
 * Output values are rounded to the nearest whole integer.
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

  // Float * int is float, which must be rounded because PWM needs int.
  return round(percent / 100.0 * 255);
}

/**
 * @brief Set the motor speeds as a percentage of the maximum speed.
 * 
 * Values outside of the typical percent range will be truncated to that range.
 *
 * @param leftPercent Perent in range `[-100, 100]` to set the left motor.
 * @param rightPercent Perent in range `[-100, 100]` to set the right motor.
 */
void motor_driver::setSpeedPercent(double leftPercent, double rightPercent) {
  int leftSpeed = convertPercent(leftPercent);
  int rightSpeed = convertPercent(rightPercent);

  Serial.print("Left M: ");
  Serial.print(leftPercent);
  Serial.println("%");
  Serial.print("Right M: ");
  Serial.print(rightPercent);
  Serial.println("%");

  setSpeedPWM(leftSpeed, rightSpeed);
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
  int truncatedLeftPWM = setPWM(leftPWM, MOTOR1_IN2, MOTOR1_IN1);
  int truncatedRightPWM = setPWM(rightPWM, MOTOR2_IN2, MOTOR2_IN1);

  Serial.print("Left PWM : ");
  Serial.println(truncatedLeftPWM);
  Serial.print("Right PWM: ");
  Serial.println(truncatedRightPWM);
}

/**
 * @brief Stop both motors.
 */
void motor_driver::stop() {
  setPWM(0, MOTOR1_IN2, MOTOR1_IN1);
  setPWM(0, MOTOR2_IN2, MOTOR2_IN1);

  Serial.println("Stopped");
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
