/*
buttonPin -> motstånd -> brytare -> jord
buzzerPin -> piezo -> jord
motorPin -> transistor bas
5v -> transistor kollector
transistor emitter -> motor -> jord
*/

const int led = 13;
const int buzzerPin = 3;
const int motorPin = 5;
const int buttonPin = 6;

void setup() {                
  pinMode(led, OUTPUT);     
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  /*
  //digitalWrite(motorPin, HIGH);
  analogWrite(motorPin, 64);
  delay(1500);
  analogWrite(motorPin, 8);
  delay(1500);
  analogWrite(motorPin, 0);
  delay(1500);*/
  /*
  int buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH) {
    digitalWrite(led, HIGH);
  }
  else {
    for(int i = 0; i < 15; ++i) {
      digitalWrite(led, LOW);
      tone(buzzerPin, 440);
      delay(200);
      digitalWrite(led, HIGH);
      tone(buzzerPin, 880);
      delay(200);
    }
    noTone(3);
  }*/
}

