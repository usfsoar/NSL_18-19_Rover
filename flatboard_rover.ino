// Flat test rover control code

const int MOTOR_1_PIN = 38;
const int MOTOR_2_PIN = 36;
const int SOLENOIDS_PIN = A8;
const int DEPLOYMENT_MOTORS_PIN = A9;
char c;


void setup() {
  pinMode(MOTOR_1_PIN, OUTPUT);
  digitalWrite(MOTOR_1_PIN, HIGH);

  pinMode(MOTOR_2_PIN, OUTPUT);
  digitalWrite(MOTOR_2_PIN, HIGH);

  pinMode(SOLENOIDS_PIN, OUTPUT);
  digitalWrite(SOLENOIDS_PIN, HIGH);

  pinMode(DEPLOYMENT_MOTORS_PIN, OUTPUT);
  digitalWrite(DEPLOYMENT_MOTORS_PIN, HIGH);

  Serial.begin(9600); 
}

void deploy() {
  digitalWrite(SOLENOIDS_PIN, LOW);
  delay(500);
  digitalWrite(DEPLOYMENT_MOTORS_PIN, LOW);
  delay(5000);
  digitalWrite(SOLENOIDS_PIN, HIGH);
  digitalWrite(DEPLOYMENT_MOTORS_PIN, HIGH);
  delay(1000);
  drive();
}

void drive() {
  right();
  delay(500);
  
  left();
  delay(500);
  
  stop();
  delay(500);
  
  forward();
  delay(5000);
  
  stop();
}

void right() {
  digitalWrite(MOTOR_1_PIN, LOW); // LOW -> Relay ON
  digitalWrite(MOTOR_2_PIN, HIGH);
}

void left() {
  digitalWrite(MOTOR_1_PIN, HIGH);
  digitalWrite(MOTOR_2_PIN, LOW);
}

void stop() {
  digitalWrite(MOTOR_2_PIN, HIGH);     
  digitalWrite(MOTOR_1_PIN, HIGH);
}

void forward() {
  digitalWrite(MOTOR_2_PIN, LOW);     
  digitalWrite(MOTOR_1_PIN, LOW);
}

void inputOption(char input) {
  if(input == 'd') {
    right();
  }
  else if(input == 'a') {
    left();
  }
  else if(input == 's') {
    stop();
  }
  else if(input == 'w') {
    forward();
  }
  else if(input == '1') {
    deploy();
  }
}

void loop() {
  if (Serial.available() > 0) {
    c = Serial.read();
    inputOption(c);
  }
}
