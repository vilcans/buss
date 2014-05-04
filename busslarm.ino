/*
buttonPin -> motstånd -> brytare -> jord
buzzerPin -> piezo -> jord
motorPin -> transistor bas
5v -> transistor kollektor
transistor emitter -> motor -> jord


Use of the servo library disables analogWrite() (PWM)
functionality on pins 9 and 10, whether or not there is a Servo on those pins

The power wire is typically red, and should be connected to the 5V pin on the Arduino board.
The ground wire is typically black or brown and should be connected to a ground pin on the Arduino board.
The signal pin is typically yellow, orange or white and should be connected to a digital pin on the Arduino board.

*/

//#define ENABLE_SERVO

#ifdef ENABLE_SERVO
#include <Servo.h>
Servo steeringServo;
#endif

const int led = 13;
const int buzzerPin = 11;  // PWM
const int motorPin = 10;  // PWM
const int buttonPin = 12;
const int servoPin = 9; // PWM
int steeringAngle = 0;

void setup() {                
  pinMode(led, OUTPUT);     
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(servoPin, OUTPUT);
#ifdef ENABLE_SERVO
  steeringServo.attach(servoPin);
#endif
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  if(false) {
    //digitalWrite(motorPin, HIGH);
    analogWrite(motorPin, 255);
    delay(5500);
    analogWrite(motorPin, 0);
    delay(1500);
    analogWrite(motorPin, 0);
    delay(1500);
  }

#ifdef ENABLE_SERVO
  steeringAngle = 25;
  steeringServo.write(steeringAngle + 90);
  delay(1000);
  steeringAngle = 0;
  steeringServo.write(steeringAngle + 90);
  delay(1000);
  steeringAngle = -25;
  steeringServo.write(steeringAngle + 90);
  delay(1000);
#endif

  if(true) {
    int buttonState = digitalRead(buttonPin);
    Serial.print("state ");
    Serial.print(buttonState);
    if(buttonState == LOW) {
      digitalWrite(led, HIGH);
    }
    else {
      for(int i = 0; i < 1; ++i) {
        digitalWrite(led, LOW);
        tone(buzzerPin, 440);
        delay(200);
        digitalWrite(led, HIGH);
        tone(buzzerPin, 880);
        delay(200);
      }
      noTone(buzzerPin);
    }
  }
}

/*
void serialEvent() {
  while (Serial.available() != 0) {
    const char inChar = (char)Serial.read();
    if(inChar == '+') {
      steeringAngle = min(90, steeringAngle + 10);
      Serial.println(steeringAngle);
    }
    else if(inChar == '-') {
      steeringAngle = max(-90, steeringAngle - 10);
      Serial.println(steeringAngle);
    }
  }
}
*/
