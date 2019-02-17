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
  int motor_1_1 = 0, motor_1_2 = 0;
  int motor_2_1 = 0, motor_2_2 = 0;

  if (leftPWM > MAX_PWM) {
    motor_1_2 = MAX_PWM;
  } else if (leftPWM > 0) {
    motor_1_2 = leftPWM;
  } else if (leftPWM < -MAX_PWM) {
    motor_1_1 = MAX_PWM;
  } else {
    motor_1_1 = -leftPWM;
  }
  
  if (rightPWM > MAX_PWM) {
    motor_2_2 = MAX_PWM;
  } else if (rightPWM > 0) {
    motor_2_2 = rightPWM;
  } else if (rightPWM < -MAX_PWM) {
    motor_2_1 = MAX_PWM;
  } else {
    motor_2_1 = -rightPWM;
  }

  analogWrite(MOTOR1_IN1, motor_1_1);
  analogWrite(MOTOR1_IN2, motor_1_2);
  analogWrite(MOTOR2_IN1, motor_2_1);
  analogWrite(MOTOR2_IN2, motor_2_2);
}

/**
 * @brief Stop both motors.
 */
void motor_driver::stop() {
  // `LOW` sets driver PWM to 0
  digitalWrite(MOTOR1_IN1, LOW);
  digitalWrite(MOTOR1_IN2, LOW);
  digitalWrite(MOTOR2_IN1, LOW);
  digitalWrite(MOTOR2_IN2, LOW);
  Serial.println("STOP");
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
