#define ENA 5 //Enable A either switches power on or off to the left motor. Pin 5 is PWM, thus allowing for speed control
#define ENB 6 //Enable B either switches power on or off to the right motor. Pin 6 is PWM, thus allowing for speed control
#define IN1 2 //Input to control left motor. Output from pin 8.
#define IN2 9 //Input to control left motor. Output from pin 9.
#define IN3 10 //Input to control right motor. Output from pin 10.
#define IN4 12 //Input to control right motor. Output from pin 12.

//#define LFSensor_1 A0 //line follow sensor1
//#define LFSensor_2 A1 //line follow sensor2

/*
  ENA/ENB  IN1/IN3  IN2/IN4   Description
  0        N/A      N/A       Motor is off
  1        0        0         Motor is stopped (brakes)
  1        0        1         Motor is on and going backwards
  1        1        0         Motor is on and going forwards
  1        1        1         Motor is stopped (brakes)
*/

 void go_forward() {
  // Left motor controls
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
//  // Right motor controls
//  digitalWrite(IN3, HIGH);
//  digitalWrite(IN4, LOW);
//  
}

//void go_backward() {
//  // Left motor controls
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, HIGH);
//  
//  // Right motor controls
//  digitalWrite(IN3, LOW);
//  digitalWrite(IN4, HIGH);
//  
//}
//
//void rotate_clockwise() {
//  // Left motor controls
//  digitalWrite(IN1, HIGH);
//  digitalWrite(IN2, LOW);
//  
//  // Right motor controls
//  digitalWrite(IN3, LOW);
//  digitalWrite(IN4, HIGH);
//  
//}
//
//void rotate_counterclockwise() {
//  // Left motor controls
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, HIGH);
//  
//  // Right motor controls
//  digitalWrite(IN3, HIGH);
//  digitalWrite(IN4, LOW);
//  
//}
//
//void brake() {
//  // Left motor controls
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, LOW);
//  
//  // Right motor controls
//  digitalWrite(IN3, LOW);
//  digitalWrite(IN4, LOW);
//  
//}

void speed_control (int left_motor_speed, int right_motor_speed) {

  analogWrite(ENA, left_motor_speed); //Uses PWM to control the speed of the left motor. Takes integer values from 0 (always OFF) to 255 (always ON).
  analogWrite(ENB, right_motor_speed); //Uses PWM to control the speed of the right motor. Takes integer values from 0 (always OFF) to 255 (always ON).
  
}

void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  
}

void loop() {

 /*//wider left turn
  speed_control(80,210);
  go_forward();
  delay(2000);
  go_backward();
  delay(2000);

  //wider right turn
  speed_control(210,80);
  go_forward();
  delay(2000);
  go_backward();
  delay(2000);
  
  //Spin back and forth
  speed_control(170,170);

  int i;

  for (i = 0; i < 3; i++) {
  rotate_clockwise();
  delay(2000);
  rotate_counterclockwise();
  delay(2000);
  }

  //Get excited
  for (i = 0; i < 15; i++) {
  speed_control(200,200);
  go_forward();
  delay(300);
  go_backward();
  delay(300);
  }*/

  go_forward();
}
