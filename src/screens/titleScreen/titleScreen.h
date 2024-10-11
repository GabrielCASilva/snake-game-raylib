#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H

#include "../../objects/button/button.h"
#include "../../utils/enums/enums.h"
#include <raylib.h>

void title_screen_loop_init();

void title_screen_loop();

void title_screen_destroy();

void title_screen_draw();

void title_screen_draw_title();

GameScreen title_screen_change(GameScreen current);

#endif
