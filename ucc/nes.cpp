#include "nes.h"

void nes_setup() {
  pinMode(NES_CLOCK, OUTPUT);
  pinMode(NES_LATCH, OUTPUT);
  pinMode(NES_DATA_0, INPUT);
  pinMode(NES_DATA_3, INPUT);
  pinMode(NES_DATA_4, INPUT);
  
  digitalWrite(NES_CLOCK, HIGH);
  digitalWrite(NES_LATCH, LOW);
  digitalWrite(NES_DATA_0, HIGH);
  digitalWrite(NES_DATA_3, HIGH);
  digitalWrite(NES_DATA_4, HIGH);
}

nes nes_read() {
  nes data = {0,0,0};
  
  digitalWrite(NES_LATCH, HIGH);
  digitalWrite(NES_LATCH, LOW);
  
  // Read controller input
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(NES_CLOCK, LOW);
    data.data0 += ((~digitalRead(NES_DATA_0) & 1) << i);
    data.data3 += ((~digitalRead(NES_DATA_3) & 1) << i);
    data.data4 += ((~digitalRead(NES_DATA_4) & 1) << i);
    digitalWrite(NES_CLOCK, HIGH);
  }
  
  // Set friendly values
  data.a = !!(data.data0 & 1);
  data.b = !!(data.data0 & 2);
  data.select = !!(data.data0 & 4);
  data.start = !!(data.data0 & 8);
  data.up = !!(data.data0 & 16);
  data.down = !!(data.data0 & 32);
  data.left = !!(data.data0 & 64);
  data.right = !!(data.data0 & 128);
  
  data.pp1 = !!(data.data4 & 2);
  data.pp2 = !!(data.data4 & 1);
  data.pp3 = !!(data.data3 & 64);
  data.pp4 = !!(data.data3 & 128);
  data.pp5 = !!(data.data4 & 4);
  data.pp6 = !!(data.data4 & 16);
  data.pp7 = !!(data.data4 & 128);
  data.pp8 = !!(data.data3 & 16);
  data.pp9 = !!(data.data4 & 8);
  data.pp10 = !!(data.data4 & 32);
  data.pp11 = !!(data.data4 & 64);
  data.pp12 = !!(data.data3 & 32);
  
  return data;
}
