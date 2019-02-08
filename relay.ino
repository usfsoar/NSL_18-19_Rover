// For powering motor with two relays per side

const int MOTOR_1_PIN = A1;
const int MOTOR_2_PIN = A2;
char c;


void setup() {
    pinMode(MOTOR_1_PIN, OUTPUT);
    digitalWrite(MOTOR_1_PIN, HIGH);

    pinMode(MOTOR_2_PIN, OUTPUT);
    digitalWrite(MOTOR_2_PIN, HIGH);

    Serial.begin(9600); 
}

void forward() {
    digitalWrite(MOTOR_1_PIN, LOW); // LOW -> Relay ON
    digitalWrite(MOTOR_2_PIN, HIGH);
}

void backward() {
    digitalWrite(MOTOR_1_PIN, HIGH);
    digitalWrite(MOTOR_2_PIN, LOW);
}

void stop() {
    digitalWrite(MOTOR_2_PIN, HIGH);     
    digitalWrite(MOTOR_1_PIN, HIGH);
}

void loop() {
    if (Serial.available() > 0) {
        c = Serial.read();
    }

    if (c == 'w') {
        forward();
    } else if(c == 's') {
        backward();
    } else if (c == ' ') {
        stop();
    }
}