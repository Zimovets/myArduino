#include <Arduino.h>

unsigned long previousMillis = 0;
const unsigned long interval = 2000;  // 2 seconds

float voltageCalc(int readVal) { return 5. / 1023 * readVal; }

void setup() {
    pinMode(A2, INPUT);
    pinMode(9, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    unsigned long currentMillis = millis();

    int resistorValue = analogRead(A2);
    int resistorMappedValue = map(resistorValue, 0, 1023, 0, 255);
    analogWrite(9, resistorMappedValue);

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

        Serial.println("Read value " + String(resistorValue));
        Serial.println("Mapped value " + String(resistorMappedValue));
        Serial.println("Voltage resister " +
                       String(voltageCalc(resistorValue)));
    }
}
