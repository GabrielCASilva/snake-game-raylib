#include "scoreScreen.h"
#include <stdio.h>

static int scores[5] = {0};
static int count = 0;

void score_screen_init() {
  FILE *file;

  // Abrir o arquivo para leitura e escrita, cria se não existir
  file = fopen("score.txt", "r+");
  if (file == NULL) {
    perror("Erro ao abrir o arquivo.\n");
    return;
  }

  // Leitura dos scores existentes
  count = 0;
  while (count < 5 && fscanf(file, "%d", &scores[count]) == 1) {
    count++;
  }

  fclose(file);
}

void score_screen_loop() {}

void score_screen_destroy() {}

void _score_draw_score_text(int fontsize) {
  const char *title = "LEADER BOARD";
  int titleWidth = MeasureText(title, fontsize);

  int titlePosX = GetScreenWidth() / 2 - titleWidth / 2;
  int titlePosY = (GetScreenHeight() / 4 - fontsize / 2) - fontsize * 2;

  DrawText(title, titlePosX, titlePosY, fontsize, GREEN);
}

void _score_draw_score(int score, int fontsize, int index) {
  const char *text = TextFormat("[ %d p ]", score);
  int textWidth = MeasureText(text, fontsize);

  int titlePosX = GetScreenWidth() / 2 - textWidth / 2;
  int titlePosY = (GetScreenHeight() / 4 - fontsize / 2) + fontsize * index * 2;

  DrawText(text, titlePosX, titlePosY, fontsize, GREEN);
}

void score_screen_draw() {
  int fontsize = 30;
  _score_draw_score_text(fontsize);
  if (scores[0] != 0) {
    for (int i = 0; i < count; i++) {
      _score_draw_score(scores[i], fontsize, i);
    }
  }
}
