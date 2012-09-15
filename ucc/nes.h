/*
  NES Connector
  1 o
  2 o o 7
  3 o o 6
  4 o o 5
  
  NES Pinout
  1   GND
  2   Clock
  3   Latch
  4   Data_0
  5   Data_3
  6   Data_4
  7   VCC +5v
*/
#ifndef NES
#define NES

#include <Arduino.h>

#define NES_CLOCK 40
#define NES_LATCH 41
#define NES_DATA_0 42
#define NES_DATA_3 45
#define NES_DATA_4 44
#define TRUE "true"
#define FALSE "false"

struct nes {
  // Raw data
  uint8_t data0, data3, data4;
  // Standard
  bool a, b, select, start, up, down, left, right;
  // Power Pad
  bool pp1, pp2, pp3, pp4, pp5, pp6, pp7, pp8, pp9, pp10, pp11, pp12;
};

void nes_setup();
nes nes_read();
String nes_debug(nes data);

#endif