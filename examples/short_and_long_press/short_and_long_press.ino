#include <Button.h>

Button button1(2); // Connect your button between pin 2 and GND

void setup() {
  button1.begin();
  button1.set_repeat(500, 200); // long press & debounce in ms

  while (!Serial) { }; // for Leos
  Serial.begin(9600);
}

void loop() {
  if (button1.released()) {
    bool longPress = button1.repeat_count() > 0;
    if (longPress) {
      Serial.println("Long press!");
    } else {
      Serial.println("Short press!");
    }
  }
}
