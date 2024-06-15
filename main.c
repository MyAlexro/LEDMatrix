#define COLS 6              //Columns are controlling the LEDs' cathodes
#define ROWS 6              //Rows are controlling the LEDs' anodes
#define PULSE 2             //milliseconds
#define FRAME_DURATION 200  //milliseconds

#define ROW1 10
#define ROW2 16
#define ROW3 14
#define ROW4 15
#define ROW5 18
#define ROW6 19

#define COL1 9
#define COL2 8
#define COL3 7
#define COL4 6
#define COL5 5
#define COL6 4

const uint8_t row[ROWS] = { ROW1, ROW2, ROW3, ROW4, ROW5, ROW6 };
const uint8_t col[COLS] = { COL1, COL2, COL3, COL4, COL5, COL6 };

typedef struct {
  uint8_t matrix[ROWS][COLS];
  uint16_t frameDuration;
} frame;

typedef struct {
  frame frames[12];
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
char currentFrame = 0;

void drawMatrix();
void resetMatrix();
void activateColumn(uint8_t);

#pragma region animation frames
frame f0 = { .matrix = {
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f1 = { .matrix = {
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION*2 };
frame f2 = { .matrix = {
               { 0, 0, 0, 0, 0, 0 },
               { 0, 1, 1, 1, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION*2 };
frame f3 = { .matrix = {
               { 0, 1, 0, 1, 0, 0 },
               { 1, 1, 1, 1, 1, 0 },
               { 0, 1, 1, 1, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION*2 };
frame f4 = { .matrix = {
               { 0, 1, 0, 1, 0, 0 },
               { 1, 0, 1, 0, 1, 0 },
               { 0, 1, 0, 1, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION * 3 };
frame f5 = { .matrix = {
                { 0, 1, 0, 1, 0, 0 },
                { 1, 1, 1, 1, 1, 0 },
                { 0, 1, 1, 1, 0, 0 },
                { 0, 0, 1, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0 } },
              .frameDuration = FRAME_DURATION * 2 };
frame f6 = { .matrix = {
               { 0, 0, 1, 0, 1, 0 },
               { 0, 1, 1, 1, 1, 1 },
               { 0, 0, 1, 1, 1, 0 },
               { 0, 0, 0, 1, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f7 = { .matrix = {
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 1, 0, 1, 0 },
               { 0, 1, 1, 1, 1, 1 },
               { 0, 0, 1, 1, 1, 0 },
               { 0, 0, 0, 1, 0, 0 },
               { 0, 0, 0, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f8 = { .matrix = {
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 1, 0, 1, 0 },
               { 0, 1, 1, 1, 1, 1 },
               { 0, 0, 1, 1, 1, 0 },
               { 0, 0, 0, 1, 0, 0 } },
             .frameDuration = FRAME_DURATION };

frame f9 = { .matrix = {
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 1, 0, 1, 0, 0 },
               { 1, 1, 1, 1, 1, 0 },
               { 0, 1, 1, 1, 0, 0 },
               { 0, 0, 1, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f10 = { .matrix = {
               { 0, 0, 0, 0, 0, 0 },
               { 0, 1, 0, 1, 0, 0 },
               { 1, 1, 1, 1, 1, 0 },
               { 0, 1, 1, 1, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f11 = { .matrix = {
               { 0, 1, 0, 1, 0, 0 },
               { 1, 1, 1, 1, 1, 0 },
               { 0, 1, 1, 1, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };

#pragma endregion

frame frameProva = {
  .matrix = {
    { 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1 } },
  .frameDuration = 400,
};

frame frameProva2 = {
  .matrix = {
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0 } },
  .frameDuration = 400,
};

animation anim = { .frames = { f0,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11 }, .framesNumber = 12 };
//animation anim = { .frames = { f1, frameProva2 }, .framesNumber = 1 };


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

void drawMatrix() {
  //Draw one column at a time in PULSE intervals

  for (int thisCol = 0; thisCol < COLS; thisCol++) {
    resetMatrix();
    // take the column pin (cathode) LOW:
    activateColumn(col[thisCol]);

    // draw the active rows in this column
    for (int thisRow = 0; thisRow < ROWS; thisRow++) {
        digitalWrite(row[thisRow], anim.frames[currentFrame].matrix[thisRow][thisCol]);
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
