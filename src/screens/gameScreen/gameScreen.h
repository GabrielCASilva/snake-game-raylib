#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "../../macros.h"
#include "../../objects/collectables/collectables.h"
#include "../../objects/snake/snake.h"

void game_screen_init();

void game_screen_loop(float *dt, int *points);

void game_screen_destroy(int *p);

void game_screen_pause(int *pause);

void game_screen_draw(int points);

void game_screen_draw_ui(int points);

void game_screen_draw_grid();

#endif
