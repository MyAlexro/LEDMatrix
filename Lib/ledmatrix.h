#include <Arduino.h>
#include "constants.h"

const uint8_t row[ROWS] = { ROW1, ROW2, ROW3, ROW4, ROW5, ROW6 };
const uint8_t col[COLS] = { COL1, COL2, COL3, COL4, COL5, COL6 };

uint8_t buff_matrix[ROWS][COLS] = {
  { 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0 }
};

void resetMatrix();
void drawMatrix();
void activateColumn(uint8_t column);

uint32_t prev_millis = 0;

void drawMatrix() {
  //Draw one column at a time in PULSE intervals

  for (int thisCol = 0; thisCol < COLS; thisCol++) {
    resetMatrix();
    // take the column pin (cathode) LOW:
    activateColumn(col[thisCol]);

    // draw the active rows in this column
    for (int thisRow = 0; thisRow < ROWS; thisRow++) {
        digitalWrite(row[thisRow], anim.frames[currentFrame].matrix[thisRow][thisCol]);
        //digitalWrite(row[thisRow], 1);
    }
    delay(PULSE);
  }
}

void activateColumn(uint8_t column) {
  //Turn off all the other columns while turning the desired one on(OFF=HIGH, ON=LOW)
  for (int i = 0; i < COLS; i++) {
    digitalWrite(col[i], !(column == col[i]));
  }
}

void resetMatrix() {
  for (uint8_t i = 0; i < COLS; i++)
    digitalWrite(col[i], HIGH);

  for (uint8_t i = 0; i < ROWS; i++)
    digitalWrite(row[i], LOW);
}
