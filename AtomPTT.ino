/**
This code uses: https://github.com/T-vK/ESP32-BLE-Keyboard
*/
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;
const int pushButton = 39;
const int delay_after_release = 500;
const int key = KEY_F12;
boolean oldstate = true;
boolean newstate;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
  pinMode(pushButton, INPUT_PULLUP);
}

void loop() {
  if (bleKeyboard.isConnected()) {
    newstate = digitalRead(pushButton);
    if (newstate != oldstate) {
      if (newstate == false) {
        bleKeyboard.press(key);
        Serial.println("press");
        delay(100);
      } else {
        Serial.println("release");
        delay(delay_after_release);
        bleKeyboard.releaseAll();
      }
      oldstate = newstate;
    }
  }
}
