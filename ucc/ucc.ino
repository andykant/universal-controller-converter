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
  if (data.a) Serial.print("A ");
  if (data.b) Serial.print("B ");
  if (data.select) Serial.print("SELECT ");
  if (data.start) Serial.print("START ");
  if (data.up) Serial.print("UP ");
  if (data.down) Serial.print("DOWN ");
  if (data.left) Serial.print("LEFT ");
  if (data.right) Serial.print("RIGHT ");
  if (data.pp1) Serial.print("PP1 ");
  if (data.pp2) Serial.print("PP2 ");
  if (data.pp3) Serial.print("PP3 ");
  if (data.pp4) Serial.print("PP4 ");
  if (data.pp5) Serial.print("PP5 ");
  if (data.pp6) Serial.print("PP6 ");
  if (data.pp7) Serial.print("PP7 ");
  if (data.pp8) Serial.print("PP8 ");
  if (data.pp9) Serial.print("PP9 ");
  if (data.pp10) Serial.print("PP10 ");
  if (data.pp11) Serial.print("PP11 ");
  if (data.pp12) Serial.print("PP12 ");
  if (data.data0 || data.data3 || data.data4) {
    Serial.println();
    Serial.print(data.data0, BIN);
    Serial.print(" ");
    Serial.print(data.data3, BIN);
    Serial.print(" ");
    Serial.print(data.data4, BIN);
    Serial.println();
    Serial.println();
    delay(250);
  }
  
  delay(1);
}
