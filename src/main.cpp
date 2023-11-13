#include <Arduino.h>
#include <Adafruit_I2CDevice.h>
#include <SPI.h>
#include <AFMotor.h>

AF_DCMotor motor(1);

void setup() 
{
	//Set initial speed of the motor & stop
	motor.setSpeed(255);
	motor.run(FORWARD);
}

void loop() 
{
	
}

