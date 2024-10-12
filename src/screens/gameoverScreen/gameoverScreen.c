#include "gameoverScreen.h"
#include <raylib.h>
/* #include <stdio.h> */

void gameover_screen_init(int score) {
  // TODO:lógica de salvar o score em um arquivo txt -> score.txt
}

void gameover_screen_loop(float *dt) {
  // TODO:
}

void gameover_screen_destroy() {
  // TODO:
}

void _draw_gameover_text(int fontsize) {
  const char *title = "GAME OVER";
  int titleWidth = MeasureText(title, fontsize);

  int titlePosX = GetScreenWidth() / 2 - titleWidth / 2;
  int titlePosY = (GetScreenHeight() / 2 - fontsize / 2) - fontsize;

  DrawText(title, titlePosX, titlePosY, fontsize, GREEN);
}

void _draw_score(int score, int fontsize) {
  const char *text = TextFormat("SCORE: %d", score);
  int textWidth = MeasureText(text, fontsize);

  int titlePosX = GetScreenWidth() / 2 - textWidth / 2;
  int titlePosY = (GetScreenHeight() / 2 - fontsize / 2) + fontsize;

  DrawText(text, titlePosX, titlePosY, fontsize, GREEN);
}

void gameover_screen_draw(int score) {
  int fontsize = 30;
  _draw_gameover_text(fontsize);
  _draw_score(score, fontsize);
}
