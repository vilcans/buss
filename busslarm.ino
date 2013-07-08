int led = 13;
int buttonPin = 6;

void setup() {                
  pinMode(led, OUTPUT);     
  pinMode(buttonPin, INPUT_PULLUP);
}

// the loop routine runs over and over again forever:
void loop() {
  int buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH) {
    digitalWrite(led, HIGH);
  }
  else {
    for(int i = 0; i < 15; ++i) {
      digitalWrite(led, LOW);
      tone(3, 440);
      delay(200);
      digitalWrite(led, HIGH);
      tone(3, 220);
      delay(200);
    }
    noTone(3);
  }
}

