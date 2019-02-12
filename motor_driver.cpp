// Basic sketch for trying out the Adafruit DRV8871 Breakout
#include "motor_driver.h"
#include <Arduino.h>

const byte MOTOR1_IN1 = 8; //declares motor 1 and 2 pins
const byte MOTOR1_IN2 = 9;
const byte MOTOR2_IN1 = 10;
const byte MOTOR2_IN2 = 11;

int motor_driver::convertPercent(double input){
  if(input > 100.1){ //edge cases for invalid values
    input = 100;
  }
  if(input < -100){
    input = -100;
  }
    return (input * 2.55); //return a pwm value
}

void motor_driver::setSpeedPercent(double leftPercent, double rightPercent){ //sets speed of left and right wheel (0-100%)

  int leftSpeed = convertPercent(leftPercent); //converts percent to pwm values
  int rightSpeed = convertPercent(rightPercent);

  if(leftSpeed >0){ //For positive values
    digitalWrite(MOTOR1_IN1, LOW);
    analogWrite(MOTOR1_IN2, leftSpeed);
    Serial.print("\nPos Left %: ");
    Serial.print(leftSpeed);
  }
  if(rightSpeed > 0){
    digitalWrite(MOTOR2_IN1, LOW);
    analogWrite(MOTOR2_IN2, rightSpeed);
    Serial.print("\nPos Right %: ");
    Serial.print(rightSpeed);
    }

  if(leftSpeed < 0){ //For negative values
    digitalWrite(MOTOR1_IN2, LOW);
    Serial.print("\nNeg Left %: ");
    Serial.print(leftSpeed);
    leftSpeed *= -1; //set the negative value back to positve
    analogWrite(MOTOR1_IN1, leftSpeed);
    
    }

  if(rightSpeed < 0){
    digitalWrite(MOTOR2_IN2, LOW);
    Serial.print("\nNeg Right %: ");
    Serial.print(rightSpeed);
    rightSpeed *= -1;
    analogWrite(MOTOR2_IN1, rightSpeed);
    }

    if(rightSpeed == 0){
      digitalWrite(MOTOR2_IN1, LOW);
      digitalWrite(MOTOR2_IN2, LOW);
    }

    if(leftSpeed == 0){
      digitalWrite(MOTOR1_IN1, LOW);
      digitalWrite(MOTOR1_IN2, LOW);
    }


}

void motor_driver::setSpeedPWM(int leftPWM, int rightPWM){ //sets speed of left and right wheel via pwm value

  if(leftPWM > 0){
    digitalWrite(MOTOR1_IN1, LOW);
    analogWrite(MOTOR1_IN2, leftPWM);
    Serial.print("\nPos Left PWM: ");
    Serial.print(leftPWM);
  }
  if(rightPWM > 0){
    digitalWrite(MOTOR2_IN1, LOW);
    analogWrite(MOTOR2_IN2, rightPWM);
    Serial.print("\nPos Right PWM: ");
    Serial.print(rightPWM);
    
    }

  if(leftPWM < 0){
    digitalWrite(MOTOR1_IN2, LOW);
    analogWrite(MOTOR1_IN1, leftPWM);
    Serial.print("\nNeg Left PWM: ");
    Serial.print(leftPWM);
    }

  if(rightPWM < 0){
    digitalWrite(MOTOR2_IN2, LOW);
    analogWrite(MOTOR2_IN1, rightPWM);
    Serial.print("\nNeg Right PWM: ");
    Serial.print(rightPWM);
    }

  if(rightPWM == 0){
    digitalWrite(MOTOR2_IN1, LOW);
    digitalWrite(MOTOR2_IN2, LOW);
  }

  if(leftPWM < 0){
    digitalWrite(MOTOR1_IN1, LOW);
    digitalWrite(MOTOR1_IN2, LOW);
  }
    
}

void motor_driver::stop(){ //sets driver pwm to 0
  digitalWrite(MOTOR1_IN1, LOW);
  digitalWrite(MOTOR1_IN2, LOW);
  digitalWrite(MOTOR2_IN1, LOW);
  digitalWrite(MOTOR2_IN2, LOW);
  Serial.print("\nSTOP");
}

motor_driver::motor_driver(){ //constructor to set pins at outputs
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR2_IN1, OUTPUT);
  pinMode(MOTOR2_IN2, OUTPUT);
}

motor_driver::~motor_driver(){
//Empty
}
