#include <Arduino.h>

#include <NewPing.h>

// Используйте свои значения для выводов
#define PIN_TRIG 12
#define PIN_ECHO 11
#define MAX_DISTANCE 200 // Константа для определения максимального расстояния, которое мы будем считать корректным.

// Создаем объект, методами которого будем затем пользоваться для получения расстояния.
// В качестве параметров передаём номера пинов, к которым подключены выходы ECHO и TRIG датчика
NewPing sonar(PIN_TRIG, PIN_ECHO, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Стартовая задержка, необходимая для корректной работы.
  delay(50);
  // Получаем значение от датчика расстояния
  unsigned int distance = sonar.ping_cm();
  // Выводим в монитор порта
  Serial.print(distance);
  Serial.println(" см");
}