#include "./Lib/alphabet.h"
#include "./Lib/ledmatrix.h"

int j = 0;
String parola = " ";

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
    j=0;
    parola.toUpperCase();
  }

  if (millis() - prev_millis > anim.frames[currentFrame].frameDuration) {
    if(j!= parola.length()) {
      // set default character as ' '
      if(parola[j]< 'A' || parola[j]>'Z') 
        parola[j]='[';
        currentFrame = parola[j] -'A';
        j++;
    }
    else
      currentFrame = 27;
  prev_millis = millis(); 
  }
  drawMatrix();
}
