#include "gameoverScreen.h"

void gameover_screen_init() {
  // TODO:
}

void gameover_screen_loop(float *dt) {
  // TODO:
}

void gameover_screen_destroy() {
  // TODO:
}

void gameover_screen_draw() {
  const char *title = "GAME OVER";
  int fontsize = 30;
  int titleWidth = MeasureText(title, fontsize);

  int titlePosX = GetScreenWidth() / 2 - titleWidth / 2;
  int titlePosY = GetScreenHeight() / 2 - fontsize / 2;

  DrawText(title, titlePosX, titlePosY, fontsize, GREEN);
}
