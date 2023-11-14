// LCD with i2c backpack test
// This example shows how to transfer an in-memory buffer to the LCD at once.
// A TwoWire instance is given as a parameter to lcd.begin to show how to pass a
// non default wire interface. Urs Utzinger, 2020

#include <Arduino.h>
#include <Wire.h>

#include "LiquidCrystal_PCF8574.h"

LiquidCrystal_PCF8574 lcd(0x27);

void setup() {
    lcd.begin(16, 2);  // у нас экран 16 столбцов на 2 строки
    lcd.setBacklight(255);  // установить яркость подсветки на максимум
    lcd.clear();  // очистить экран и установить курсор в позицию 0, 0
}
void loop() {
	lcd.print("Hello World");
	delay(3000);
	lcd.setCursor(0, 1);
	lcd.print(")))))");
	delay(3000);
	lcd.clear();
}