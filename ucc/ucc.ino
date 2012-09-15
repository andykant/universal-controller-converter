#include "nes.h"

#define LED 13

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  nes_setup();
}

void loop() {
  // Read the controller
  nes data = nes_read();
  
  // Light the LED if a button is pressed
  digitalWrite(LED, data.data0 || data.data3 || data.data4 ? HIGH : LOW);
  
  // Print button status
  if (data.data0 || data.data3 || data.data4) {
    Serial.println(nes_debug(data));
    delay(250);
  }
  
  delay(1);
}
