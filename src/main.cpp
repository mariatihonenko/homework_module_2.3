#include <Arduino.h>

#define LED1_PIN 15
#define LED2_PIN 16
#define LED3_PIN 17

#define LED1_BLINK_MS 200
#define LED2_BLINK_MS 500
#define LED3_BLINK_MS 1000

#define DURATION_BLINK_MS 100

unsigned long lastBlinkLED1 = 0;
unsigned long lastBlinkLED2 = 0;
unsigned long lastBlinkLED3 = 0;

bool isLed1On = false;
bool isLed2On = false;
bool isLed3On = false;

void setup() {
  Serial.begin(115200);

  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
}

void loop() {
  if (millis() - lastBlinkLED1 >= LED1_BLINK_MS) {
    digitalWrite(LED1_PIN, HIGH);
    isLed1On = true;
    lastBlinkLED1 = millis();
  }
  if ((millis() - lastBlinkLED1 >= DURATION_BLINK_MS) && isLed1On) {
      digitalWrite(LED1_PIN, LOW);
      isLed1On = false;
    }


  if (millis() - lastBlinkLED2 >= LED2_BLINK_MS) {
    digitalWrite(LED2_PIN, HIGH);
    isLed2On = true;
    lastBlinkLED2 = millis();
  }
  if ((millis() - lastBlinkLED2 >= DURATION_BLINK_MS) && isLed2On) {
      digitalWrite(LED2_PIN, LOW);
      isLed2On = false;
    }


  if (millis() - lastBlinkLED3 >= LED3_BLINK_MS) {
    digitalWrite(LED3_PIN, HIGH);
    isLed3On = true;
    lastBlinkLED3 = millis();
  }
  if ((millis() - lastBlinkLED3 >= DURATION_BLINK_MS) && isLed3On) {
      digitalWrite(LED3_PIN, LOW);
      isLed3On = false;
    }
}