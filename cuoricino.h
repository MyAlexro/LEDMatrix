#include "constants.h"
char currentFrame = 0;

typedef struct {
  uint8_t matrix[ROWS][COLS];
  uint16_t frameDuration;
} frame;

typedef struct {
  frame frames[12];
  uint8_t framesNumber;
} animation;

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

animation anim = { .frames = { f0,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11 }, .framesNumber = 12 };
