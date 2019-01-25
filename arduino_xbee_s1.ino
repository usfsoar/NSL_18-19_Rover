

char c;
int n;
int relay = 10;
void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);

}



void onLED(){
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(relay, LOW);
  Serial.print('H');
    }

void offLED(){
  digitalWrite(LED_BUILTIN, LOW);
  Serial.print('L');
  digitalWrite(relay, HIGH);

    }
 

void loop()
{
 if (Serial.available() > 0){
  {
    c = Serial.read();
    if (c == 'H'){
      onLED();
  }

    if( c == 'L'){
      offLED();
    }
  }

}
}
