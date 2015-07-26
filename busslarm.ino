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

#include <Servo.h>
Servo steeringServo;

const int led = 13;
//const int buzzerPin = 11;  // PWM
const int motorPin = 9;  // PWM
const int motorPin2 = 10;  // PWM
const int buttonPin = 12;
const int servoPin = 11; // PWM

const int joyRightPin = A1;
const int joyLeftPin = A2;
const int joyDownPin = A3;
const int joyUpPin = A4;

const int MID_ANGLE = 67;
const int MAX_ANGLE = 86;
const int MIN_ANGLE = 47;
int steeringAngle = MID_ANGLE;

int speed = 0;

void setup() {                
  pinMode(led, OUTPUT);     
  pinMode(buttonPin, INPUT_PULLUP);
  //pinMode(buzzerPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(servoPin, OUTPUT);
  steeringServo.attach(servoPin);
  steeringServo.write(steeringAngle);
  pinMode(joyRightPin, INPUT_PULLUP);
  pinMode(joyLeftPin, INPUT_PULLUP);
  pinMode(joyDownPin, INPUT_PULLUP);
  pinMode(joyUpPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  while(true) {
    const int delayTime = 3000;
    const int middleAngle = 90 + 25;

#if 0
    Serial.println("1");
    steeringServo.write(middleAngle - 25);
    analogWrite(motorPin, 0);
    analogWrite(motorPin2, 255);
    delay(delayTime);

    Serial.println("2");
    steeringServo.write(middleAngle);
    analogWrite(motorPin, 0);
    analogWrite(motorPin2, 0);
    delay(delayTime);

    Serial.println("3");
    steeringServo.write(middleAngle + 25);
    steeringServo.write(90);
    analogWrite(motorPin, 255);
    analogWrite(motorPin2, 0);
    delay(delayTime);

    Serial.println("4");
    steeringServo.write(middleAngle);
    steeringServo.write(45);
    analogWrite(motorPin, 0);
    analogWrite(motorPin2, 0);
    delay(delayTime * 2);
#else
    int newAngle = steeringAngle;
    if(digitalRead(joyRightPin) == LOW && newAngle < MAX_ANGLE) {
      newAngle += 1;
    }
    if(digitalRead(joyLeftPin) == LOW && newAngle > MIN_ANGLE) {
      newAngle -= 1;
    }
    if(newAngle != steeringAngle) {
      Serial.println(newAngle);
      steeringAngle = newAngle;
      steeringServo.write(steeringAngle);
    }

    if(digitalRead(joyUpPin) == LOW && speed < 255) {
      speed = 255;
    }
    else if(digitalRead(joyDownPin) == LOW && speed > -255) {
      speed = -255;
    }
    else {
      speed = 0;
    }
    if(speed >= 0) {
      analogWrite(motorPin, speed);
      analogWrite(motorPin2, 0);
    }
    else {
      analogWrite(motorPin, 0);
      analogWrite(motorPin2, -speed);
    }
    if(speed != 0) {
      Serial.print("Speed ");
      Serial.println(speed);
    }
    delay(20);
#endif
  }


#if 0
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
#endif
}

/* vim: set ts=2 sw=2 tw=0 syntax=cpp et :*/
