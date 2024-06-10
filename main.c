#define COLS 6              //Columns are controlling the LEDs' cathodes
#define ROWS 6              //Rows are controlling the LEDs' anodes
#define PULSE 3             //milliseconds
#define FRAME_DURATION 250  //milliseconds

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

const short row[ROWS] = { ROW1, ROW2, ROW3, ROW4, ROW5, ROW6 };
const short col[COLS] = { COL1, COL2, COL3, COL4, COL5, COL6 };

typedef struct {
  short matrix[ROWS][COLS];
  int frameDuration;
} frame;

typedef struct {
  frame frames[10];
  short framesNumber;
} animation;

short buff_matrix[ROWS][COLS] = {
  { 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0 }
};

uint32_t prev_millis = 0;
short counter = 0;

void drawMatrix(short[ROWS][COLS]);
void resetMatrix();
void resetBufferMatrix();
void updateBufferMatrix(short[ROWS][COLS]);
void activateColumn(short);

#pragma region animation frames

frame f1 = { .matrix = {
               { 0, 1, 0, 1, 0, 0 },
               { 1, 1, 1, 1, 1, 0 },
               { 0, 1, 1, 1, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f8 = { .matrix = {
               { 0, 1, 0, 1, 0, 0 },
               { 1, 0, 1, 0, 1, 0 },
               { 0, 1, 0, 1, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION * 3 };
frame f10 = { .matrix = {
                { 0, 1, 0, 1, 0, 0 },
                { 1, 1, 1, 1, 1, 0 },
                { 0, 1, 1, 1, 0, 0 },
                { 0, 0, 1, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0 } },
              .frameDuration = FRAME_DURATION * 2 };
frame f2 = { .matrix = {
               { 0, 0, 1, 0, 1, 0 },
               { 0, 1, 1, 1, 1, 1 },
               { 0, 0, 1, 1, 1, 0 },
               { 0, 0, 0, 1, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f3 = { .matrix = {
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 1, 0, 1, 0 },
               { 0, 1, 1, 1, 1, 1 },
               { 0, 0, 1, 1, 1, 0 },
               { 0, 0, 0, 1, 0, 0 },
               { 0, 0, 0, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f4 = { .matrix = {
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 1, 0, 1, 0 },
               { 0, 1, 1, 1, 1, 1 },
               { 0, 0, 1, 1, 1, 0 },
               { 0, 0, 0, 1, 0, 0 } },
             .frameDuration = FRAME_DURATION };

frame f5 = { .matrix = {
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 1, 0, 1, 0, 0 },
               { 1, 1, 1, 1, 1, 0 },
               { 0, 1, 1, 1, 0, 0 },
               { 0, 0, 1, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f6 = { .matrix = {
               { 0, 0, 0, 0, 0, 0 },
               { 0, 1, 0, 1, 0, 0 },
               { 1, 1, 1, 1, 1, 0 },
               { 0, 1, 1, 1, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };
frame f7 = { .matrix = {
               { 0, 1, 0, 1, 0, 0 },
               { 1, 1, 1, 1, 1, 0 },
               { 0, 1, 1, 1, 0, 0 },
               { 0, 0, 1, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 },
               { 0, 0, 0, 0, 0, 0 } },
             .frameDuration = FRAME_DURATION };

#pragma endregion

animation anim = { .frames = { f1, f8, f10, f2, f3, f4, f5, f6, f7 }, .framesNumber = 9 };

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


//animation anim = { .frames = { f1, frameProva2 }, .framesNumber = 1 };


void setup() {


  for (int i = 0; i < ROWS; i++) {
    pinMode(row[i], OUTPUT);
    digitalWrite(row[i], LOW);
  }
  for (int i = 0; i < COLS; i++) {
    pinMode(col[i], OUTPUT);
    digitalWrite(col[i], HIGH);
  }
}


void loop() {
  updateBufferMatrix(anim.frames[counter].matrix);
  if (millis() - prev_millis > anim.frames[counter].frameDuration) {
    prev_millis = millis();

    counter = counter == anim.framesNumber - 1 ? 0 : counter + 1;
  }

  drawMatrix();
}

void resetBufferMatrix() {
  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++)
      buff_matrix[i][j] = 0;
  }
}

void drawMatrix() {
  //Draw one column at a time in PULSE intervals

  for (int thisCol = 0; thisCol < COLS; thisCol++) {
    resetMatrix();
    // take the column pin (cathode) LOW:
    activateColumn(col[thisCol]);

    // draw the active rows in this column
    for (int thisRow = 0; thisRow < ROWS; thisRow++) {
      digitalWrite(row[thisRow], buff_matrix[thisRow][thisCol]);
    }
    delay(PULSE);
  }
}

void activateColumn(short column) {
  //Turn off all the other columns while turning the desired one on(OFF=HIGH, ON=LOW)
  for (int i = 0; i < COLS; i++) {
    digitalWrite(col[i], !(column == col[i]));
  }
}

void resetMatrix() {
  for (int i = 0; i < COLS; i++)
    digitalWrite(col[i], HIGH);

  for (int i = 0; i < ROWS; i++)
    digitalWrite(row[i], LOW);
}

void updateBufferMatrix(short matrix[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      buff_matrix[i][j] = matrix[i][j];
    }
  }
}
