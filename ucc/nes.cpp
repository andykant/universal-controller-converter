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

String nes_debug(nes data) {
  String debug = "{ type: 'nes', data: { ";
  debug.concat("a: ");
  debug.concat(data.a ? TRUE : FALSE);
  debug.concat(", b: ");
  debug.concat(data.b ? TRUE : FALSE);
  debug.concat(", select: ");
  debug.concat(data.select ? TRUE : FALSE);
  debug.concat(", start: ");
  debug.concat(data.start ? TRUE : FALSE);
  debug.concat(", up: ");
  debug.concat(data.up ? TRUE : FALSE);
  debug.concat(", down: ");
  debug.concat(data.down ? TRUE : FALSE);
  debug.concat(", left: ");
  debug.concat(data.left ? TRUE : FALSE);
  debug.concat(", right: ");
  debug.concat(data.right ? TRUE : FALSE);
  debug.concat(", powerpad: [");
  debug.concat(data.pp1 ? TRUE : FALSE);
  debug.concat(",");
  debug.concat(data.pp2 ? TRUE : FALSE);
  debug.concat(",");
  debug.concat(data.pp3 ? TRUE : FALSE);
  debug.concat(",");
  debug.concat(data.pp4 ? TRUE : FALSE);
  debug.concat(",");
  debug.concat(data.pp5 ? TRUE : FALSE);
  debug.concat(",");
  debug.concat(data.pp6 ? TRUE : FALSE);
  debug.concat(",");
  debug.concat(data.pp7 ? TRUE : FALSE);
  debug.concat(",");
  debug.concat(data.pp8 ? TRUE : FALSE);
  debug.concat(",");
  debug.concat(data.pp9 ? TRUE : FALSE);
  debug.concat(",");
  debug.concat(data.pp10 ? TRUE : FALSE);
  debug.concat(",");
  debug.concat(data.pp11 ? TRUE : FALSE);
  debug.concat(",");
  debug.concat(data.pp12 ? TRUE : FALSE);
  debug.concat("] } }");
  return debug;
}