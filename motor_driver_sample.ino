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
  int output = input * 2.55;
  return output;
}


void setSpeed(double leftPercent, double rightPercent){ //sets speed of left and right wheel (0-100%)
if(leftPercent > 100.1){ //edge cases for invalid values
  leftPercent = 100;
}
if(rightPercent > 100.1){
  rightPercent = 100;
}
if(leftPercent < -100.1){
  leftPercent = -100;
}
if(rightPercent > -100.1){
  rightPercent = -100;
}

int leftSpeed = convertPercent(leftPercent); //converts percent to pwm values
int rightSpeed = convertPercent(rightPercent);
if(leftSpeed > 0){ //checks if forward or backward
  digitalWrite(MOTOR1_IN1, LOW);
  analogWrite(MOTOR1_IN2, i);
}else if (leftSpeed < 0)
  {
  digitalWrite(MOTOR1_IN2, LOW);
  analogWrite(MOTOR1_IN1, i);
  }

if(rightSpeed > 0){
  digitalWrite(MOTOR2_IN1, LOW);
  analogWrite(MOTOR2_IN2, i);
}else if (rightSpeed < 0)
  {
  digitalWrite(MOTOR2_IN2, LOW);
  analogWrite(MOTOR2_IN1, i);
  }
}


void stop(){ //sets driver pwm to 0
  digitalWrite(MOTOR1_IN1, LOW);
  digitalWrite(MOTOR1_IN2, LOW);
  digitalWrite(MOTOR2_IN1, LOW);
  digitalWrite(MOTOR2_IN2, LOW);
}

void loop() {
setSpeed(50,50);
delay(5000);
stop();
}