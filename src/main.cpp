#include <Arduino.h>
#include <Servo.h>

int servoPin = 9;
int servoPosition = 180;

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  int rundomNum = random(180);
  Serial.println(rundomNum);
  myServo.write(rundomNum);
  delay(1000);
}