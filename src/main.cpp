#include <Arduino.h>


const uint8_t btnPins[] = {13, 14, 25, 27, 32};
const int NUM = sizeof(btnPins);
bool lastState[NUM];
unsigned long lastPress[NUM];

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < NUM; i++) {
    pinMode(btnPins[i], INPUT_PULLUP);
    lastState[i] = HIGH;
  }
}

void loop() {
  for (int i = 0; i < NUM; i++) {
    bool state = digitalRead(btnPins[i]);
    if (lastState[i] == HIGH && state == LOW && millis() - lastPress[i] > 30) {
      Serial.println(i + 1);   // sends "1", "2", ...
      lastPress[i] = millis();
    }
    lastState[i] = state;
  }
}