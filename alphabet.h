#include "constants.h"
char currentFrame=26;

typedef struct {
  uint8_t matrix[ROWS][COLS];
  uint16_t frameDuration;
} frame;

typedef struct {
  frame frames[29];
  uint8_t framesNumber;
} animation;

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
