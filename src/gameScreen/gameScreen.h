#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "../collectables/collectables.h"
#include "../macros.h"
#include "../snake/snake.h"

void game_screen_init();

void game_screen_loop(float *dt);

void game_screen_draw();

void game_screen_destroy();

#endif
