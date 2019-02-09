// Basic sketch for trying out the Adafruit DRV8871 Breakout

#define MOTOR1_IN1 9
#define MOTOR1_IN2 10
#define MOTOR2_IN1 11
#define MOTOR2_IN2 12

void setup() {
  Serial.begin(9600);
  Serial.println("DRV8871 test");
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR2_IN1, OUTPUT);
  pinMode(MOTOR2_IN2, OUTPUT);
}

int convertPercent(double input){

  if(input > 100.1){ //edge cases for invalid values
    input = 100;
  }
  if(input < -100){
    input = -100;
  }
    return (input * 2.55); //return a pwm value
}

void setSpeedPercent(double leftPercent, double rightPercent){ //sets speed of left and right wheel (0-100%)

  int leftSpeed = convertPercent(leftPercent); //converts percent to pwm values
  int rightSpeed = convertPercent(rightPercent);

  if(leftSpeed >0){
    digitalWrite(MOTOR1_IN1, LOW);
    analogWrite(MOTOR1_IN2, leftSpeed);
    Serial.print(leftSpeed);
    Serial.print("Pos Left\n");
  }
  if(rightSpeed > 0){
    digitalWrite(MOTOR2_IN1, LOW);
    analogWrite(MOTOR2_IN2, rightSpeed);
    Serial.print(rightSpeed);
    Serial.print("Pos Right\n");
    }

  if(leftSpeed < 0){
    digitalWrite(MOTOR1_IN2, LOW);
    analogWrite(MOTOR1_IN1, leftSpeed);
    Serial.print(leftSpeed);
    Serial.print("Neg Left\n");
    }

  if(rightSpeed < 0){
    digitalWrite(MOTOR2_IN2, LOW);
    analogWrite(MOTOR2_IN1, rightSpeed);
    Serial.print(rightSpeed);
    Serial.print("Neg Right\n");
    }
}

void setSpeedPWM(int leftPWM, int rightPWM){ //sets speed of left and right wheel via pwm value

  if(leftPWM > 0){
    digitalWrite(MOTOR1_IN1, LOW);
    analogWrite(MOTOR1_IN2, leftPWM);
    Serial.print(leftPWM);
    Serial.print("Pos Left PWM\n");
  }
  if(rightPWM > 0){
    digitalWrite(MOTOR2_IN1, LOW);
    analogWrite(MOTOR2_IN2, rightPWM);
    Serial.print(rightPWM);
    Serial.print("Pos Right PWM\n");
    }

  if(leftPWM < 0){
    digitalWrite(MOTOR1_IN2, LOW);
    analogWrite(MOTOR1_IN1, leftPWM);
    Serial.print(leftPWM);
    Serial.print("Neg Left PWM\n");
    }

  if(rightPWM < 0){
    digitalWrite(MOTOR2_IN2, LOW);
    analogWrite(MOTOR2_IN1, rightPWM);
    Serial.print(rightPWM);
    Serial.print("Neg Right PWM\n");
    }
}

void stop(){ //sets driver pwm to 0
  digitalWrite(MOTOR1_IN1, LOW);
  digitalWrite(MOTOR1_IN2, LOW);
  digitalWrite(MOTOR2_IN1, LOW);
  digitalWrite(MOTOR2_IN2, LOW);
}

void loop() { //test code for arduino
  setSpeedPercent(100, 100);
  delay(1000);
  stop();
  delay(1000);
  setSpeedPWM(-100, -100);
  stop();
  delay(1000);
}