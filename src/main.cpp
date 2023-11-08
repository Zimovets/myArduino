#include <Arduino.h>
#include <Servo.h>

int pinX = A0;
int pinY = A1;
int servoPin = 9;
int servoPOsition = 0;
Servo servo;

void setup() {
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  Serial.begin(9600);
  servo.attach(servoPin);
}

void loop() {
  int angle = map(analogRead(pinY), 0, 1023, 0, 180);

  if(136 < angle && angle < 180 ) {
    servoPOsition++;
  }

  if(angle == 180 && servoPOsition < 180 ) {
    servoPOsition = servoPOsition + 2;
  }

  if(44 > angle && servoPOsition > 0) {
    servoPOsition--;
  }

  if( angle == 0 && servoPOsition > 0) {
    servoPOsition = servoPOsition - 2;
  }
  servo.write(servoPOsition);
  Serial.println(servoPOsition);
}