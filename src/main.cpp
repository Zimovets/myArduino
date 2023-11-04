#include <Arduino.h>

int inputPin = A0;

void setup() {
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  Serial.println(String(analogRead(inputPin) * (5.0 / 1023.0)) + 'v');
  delay(500);
}