#include <Arduino.h>

int inputPin = A0;
int zoomPin = 8;

void setup() {
  pinMode(inputPin, INPUT);
  pinMode(zoomPin, OUTPUT);
  digitalWrite(zoomPin, LOW);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(inputPin);
  Serial.println(value);

  if(value < 280) {
    digitalWrite(zoomPin, HIGH);
  } else {
    digitalWrite(zoomPin, LOW);
  }

  delay(1000);
}
