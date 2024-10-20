#ifndef GAMEOVER_SCREEN_H
#define GAMEOVER_SCREEN_H

#include <raylib.h>

void gameover_screen_init(int score);

void gameover_screen_loop(float *dt);

void gameover_screen_destroy();

void gameover_screen_draw(int score);

#endif
