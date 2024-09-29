#ifndef APPLICATION_H
#define APPLICATION_H

#include "enums/enums.h"
#include "gameScreen/gameScreen.h"
#include "raylib.h"
#include "titleScreen/titleScreen.h"
#include <stdio.h>

extern GameScreen currentScreen;

void loop(float *dt);

void draw();

void temp_text_func(const char *text);

#endif
