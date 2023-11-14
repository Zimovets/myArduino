#include <Arduino.h>
#include <Adafruit_I2CDevice.h>
#include <SPI.h>
#include <AFMotor.h>

int dataPin = 9;    // к выводу 14 регистра SD
int clockPin = 11;  // к выводу 11 регистра (SH_CP)
int latchPin = 12;  // к выводу 12 регистра (ST_CP)

void setByte(byte value) {
	digitalWrite(latchPin, LOW); // начинаем передачу данных
	// устанавливаем нужный байт
	shiftOut(dataPin, clockPin, LSBFIRST, value);
	digitalWrite(latchPin, HIGH); // прекращаем передачу данных
}

void setup() {
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
	digitalWrite(latchPin, LOW);
}

void loop() {
	setByte(0b11111111);
	delay(3000);
}


