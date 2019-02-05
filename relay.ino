
// For powering motor with two relays per side

int motor1 = A1;
int motor2 = A2;
char c;


void setup() {
  pinMode(motor1, OUTPUT);
  digitalWrite(motor1, HIGH);
    pinMode(motor2, OUTPUT);
  digitalWrite(motor2, HIGH);
    Serial.begin(9600); 
  pinMode(led, OUTPUT);
}
void loop() {
 if (Serial.available() > 0)
    c = Serial.read();

    if (c == 'w')
    forward();
    else if(c == 's')
    backward();
    else if (c == ' ')
    stop();
}
void forward()
{
    digitalWrite(motor1, LOW); //low is RELAY ON
    digitalWrite(motor2, HIGH);
}

void backward()
{
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
}

void stop()
{
    digitalWrite(motor2, HIGH);     
    digitalWrite(motor1, HIGH);
}
