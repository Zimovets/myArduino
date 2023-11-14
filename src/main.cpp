#include <Arduino.h>

#include <Wire.h> // библиотека для управления устройствами по I2C 
#include <LiquidCrystal_I2C.h> // подключаем библиотеку для QAPASS 16x2

LiquidCrystal_I2C LCD(0x27,16,2); // присваиваем имя LCD для дисплея

void setup() {
   LCD.init();    // инициализация LCD дисплея
   LCD.backlight(); // включение подсветки дисплея

   LCD.blink(); // включение мигающего курсора
   delay(2000);
   LCD.noBlink();
   
   LCD.setCursor(1, 0);    // ставим курсор на 1 символ первой строки
   LCD.print("I LOVE");   // печатаем сообщение на первой строке
   LCD.setCursor(8, 1);        // ставим курсор на 1 символ второй строки
   LCD.print("ARDUINO");  // печатаем сообщение на второй строке
   delay(2000);

   LCD.cursor(); // включение текущей позиции курсора
   delay(2000);
   LCD.noCursor();
}

void loop() {
   LCD.noBacklight(); // выключаем и включаем подсветку экрана
   delay(1000);
   LCD.backlight();
   delay(1000);
}