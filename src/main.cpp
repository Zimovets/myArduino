#include <Arduino.h>

int redpin = 10;   // select the pin for the red LED
int bluepin = 8;   // select the pin for the blue LED
int greenpin = 9;  // select the pin for the green LED
void setup() {
    pinMode(redpin, OUTPUT);
    pinMode(bluepin, OUTPUT);
    pinMode(greenpin, OUTPUT);
}

void loop() {
    analogWrite(11, random(256));
    analogWrite(10, random(256));
    analogWrite(9, random(256));
    delay(200);
}
