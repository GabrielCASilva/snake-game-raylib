#ifndef APPLICATION_H
#define APPLICATION_H

#include "screens/gameScreen/gameScreen.h"
#include "screens/gameoverScreen/gameoverScreen.h"
#include "screens/titleScreen/titleScreen.h"
#include "utils/enums/enums.h"
#include <raylib.h>
#include <stdio.h>

extern GameScreen currentScreen;

void loop(float *dt);

void draw();

void temp_text_func(const char *text);

#endif
