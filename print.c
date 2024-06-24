#include <ledmatrix.h>

const uint8_t row[ROWS] = { ROW1, ROW2, ROW3, ROW4, ROW5, ROW6 };
const uint8_t col[COLS] = { COL1, COL2, COL3, COL4, COL5, COL6 };

char currentFrame = 26;
int i = 0;
String parola = " ";

typedef struct {
  uint8_t matrix[ROWS][COLS];
  uint16_t frameDuration;
} frame;

typedef struct {
  frame frames[29];
  uint8_t framesNumber;
} animation;

uint8_t buff_matrix[ROWS][COLS] = {
  { 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0 }
};

uint32_t prev_millis = 0;

void drawMatrix();
void resetMatrix();
void activateColumn(uint8_t);

#pragma region animation frames
frame f0 = { .matrix = {
               { 0, 1, 1, 1, 0, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 1, 1, 1, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 } },
             .frameDuration = FRAME_DURATION };
frame f1 = { .matrix = {
               { 1, 1, 1, 1, 0, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 1, 1, 1, 0, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 1, 1, 1, 0, 0 } },
             .frameDuration = FRAME_DURATION};
frame f2 = { .matrix = {
               { 0, 1, 1, 1, 0, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 0, 1, 1, 1, 0, 0 } },
             .frameDuration = FRAME_DURATION};
frame f3 = { .matrix = {
               { 1, 1, 1, 1, 0, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 1, 1, 1, 0, 0 } },
             .frameDuration = FRAME_DURATION};
frame f4 = { .matrix = {
               { 1, 1, 1, 1, 1, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 1, 1, 1, 0, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 1, 1, 1, 1, 0 } },
             .frameDuration = FRAME_DURATION};
frame f5 = { .matrix = {
                { 1, 1, 1, 1, 1, 0 },
                { 1, 0, 0, 0, 0, 0 },
                { 1, 0, 0, 0, 0, 0 },
                { 1, 1, 1, 1, 0, 0 },
                { 1, 0, 0, 0, 0, 0 },
                { 1, 0, 0, 0, 0, 0 } },
              .frameDuration = FRAME_DURATION};
frame f6 = { .matrix = {
               { 0, 1, 1, 1, 0, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 0, 0, 1, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 0, 1, 1, 1, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f7 = { .matrix = {
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 1, 1, 1, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 } },
             .frameDuration = FRAME_DURATION };
frame f8 = { .matrix = {
               { 0, 1, 1, 1, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 1, 1, 1, 0, 0 } },
             .frameDuration = FRAME_DURATION };

frame f9 = { .matrix = {
               { 0, 0, 1, 1, 1, 0 },
               { 0, 0, 0, 1, 0, 0 },
               { 0, 0, 0, 1, 0, 0 },
               { 0, 0, 0, 1, 0, 0 },
               { 0, 0, 0, 1, 0, 0 },
               { 0, 1, 1, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f10 = { .matrix = {
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 1, 0, 0 },
               { 1, 0, 1, 0, 0, 0 },
               { 1, 1, 1, 0, 0, 0 },
               { 1, 0, 0, 1, 0, 0 },
               { 1, 0, 0, 0, 1, 0 } },
             .frameDuration = FRAME_DURATION };
frame f11 = { .matrix = {
               { 1, 0, 0, 0, 0, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 1, 1, 1, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f12 = { .matrix = {
               { 1, 0, 0, 0, 1, 0 },
               { 1, 1, 0, 1, 1, 0 },
               { 1, 0, 1, 0, 1, 0 },
               { 1, 0, 1, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 } },
             .frameDuration = FRAME_DURATION };
frame f13 = { .matrix = {
               { 1, 0, 0, 0, 1, 0 },
               { 1, 1, 0, 0, 1, 0 },
               { 1, 0, 1, 0, 1, 0 },
               { 1, 0, 0, 1, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 } },
             .frameDuration = FRAME_DURATION };
frame f14 = { .matrix = {
               { 0, 1, 1, 1, 0, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 0, 1, 1, 1, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f15 = { .matrix = {
               { 1, 1, 1, 1, 0, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 1, 1, 1, 0, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 0, 0, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f16 = { .matrix = {
               { 0, 1, 1, 1, 0, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 1, 0, 1, 0 },
               { 0, 1, 1, 1, 0, 0 },
               { 0, 0, 0, 0, 1, 0 } },
             .frameDuration = FRAME_DURATION };
frame f17 = { .matrix = {
               { 1, 1, 1, 1, 0, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 1, 1, 1, 0, 0 },
               { 1, 0, 0, 1, 0, 0 },
               { 1, 0, 0, 0, 1, 0 } },
             .frameDuration = FRAME_DURATION };
frame f18 = { .matrix = {
               { 0, 1, 1, 1, 1, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 0, 1, 1, 0, 0, 0 },
               { 0, 0, 1, 1, 0, 0 },
               { 0, 0, 0, 0, 1, 0 },
               { 1, 1, 1, 1, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f19 = { .matrix = {
               { 1, 1, 1, 1, 1, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 1, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f20 = { .matrix = {
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 0, 1, 1, 1, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f21 = { .matrix = {
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 0, 1, 0, 1, 0, 0 },
               { 0, 0, 1, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f22 = { .matrix = {
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 1, 0, 1, 0 },
               { 1, 0, 1, 0, 1, 0 },
               { 1, 0, 1, 0, 1, 0 },
               { 1, 1, 0, 1, 1, 0 },
               { 1, 0, 0, 0, 1, 0 } },
             .frameDuration = FRAME_DURATION };
frame f23 = { .matrix = {
               { 1, 0, 0, 0, 1, 0 },
               { 0, 1, 0, 1, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 1, 0, 1, 0, 0 },
               { 1, 0, 0, 0, 1, 0 } },
             .frameDuration = FRAME_DURATION };
frame f24 = { .matrix = {
               { 1, 0, 0, 0, 1, 0 },
               { 1, 0, 0, 0, 1, 0 },
               { 0, 1, 0, 1, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 1, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f25 = { .matrix = {
               { 1, 1, 1, 1, 1, 0 },
               { 0, 0, 0, 1, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 1, 0, 0, 0, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 1, 1, 1, 1, 0 } },
             .frameDuration = FRAME_DURATION };
frame f26 = { .matrix = {
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f27 = { .matrix = {
               { 1, 0, 0, 0, 0, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 1, 1, 1, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f28 = { .matrix = {
               { 1, 0, 0, 0, 0, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 0, 0, 0, 0, 0 },
               { 1, 1, 1, 1, 0, 0 } },
             .frameDuration = FRAME_DURATION };

#pragma endregion

animation anim = { .frames = { f0,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26}, .framesNumber = 27 };

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
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
  // read string from serial
  if (Serial.available() > 0) {
    parola = "["+Serial.readString();
    i=0;
    parola.toUpperCase();
  }

  if (millis() - prev_millis > anim.frames[currentFrame].frameDuration) {
    if(i!= parola.length()) {
      // set default character as ' '
      if(parola[i]< 'A' || parola[i]>'Z') 
        parola[i]='[';
        currentFrame = parola[i] -'A';
        i++;
    }
    else
      currentFrame = 27;
  prev_millis = millis(); 
  }
  drawMatrix();
}

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
