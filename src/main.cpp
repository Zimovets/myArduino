#include <Arduino.h>
#include <Servo.h>

int pinX = A0;
int pinY = A1;
int servoPin = 9;
Servo servo;

void setup() {
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  Serial.begin(9600);
  servo.attach(servoPin);
}

void loop() {
  int angle = map(analogRead(pinY), 0, 1023, 0, 180);
  servo.write(angle);
  Serial.println(angle);
  delay(250);
}