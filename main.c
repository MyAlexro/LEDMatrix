#include "./Lib/cuoricino.h"
#include "./Lib/ledmatrix.h"

void setup() {
  for (uint8_t i = 0; i < ROWS; i++) {
    pinMode(row[i], OUTPUT);
    digitalWrite(row[i], LOW);
  }
  for (uint8_t i = 0; i < COLS; i++) {
    pinMode(col[i], OUTPUT);
    digitalWrite(col[i], HIGH);
  }
}

void loop() {
  if (millis() - prev_millis > anim.frames[currentFrame].frameDuration) {
    prev_millis = millis();

    currentFrame = currentFrame == anim.framesNumber - 1 ? 0 : currentFrame + 1;
  }
  drawMatrix();
}
  for (uint8_t i = 0; i < ROWS; i++)
    digitalWrite(row[i], LOW);
}
