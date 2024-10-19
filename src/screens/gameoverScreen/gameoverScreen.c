#include "gameoverScreen.h"
#include <raylib.h>
#include <stdio.h>

void gameover_screen_init(int score) {
  FILE *file;
  int dados[5] = {0};

  // Abrir o arquivo para leitura e escrita, cria se não existir
  file = fopen("score.txt", "r+");
  if (file == NULL) {
    perror("Erro ao abrir o arquivo.\n");
    return;
  }

  // Leitura dos scores existentes
  int count = 0;
  while (count < 5 && fscanf(file, "%d", &dados[count]) == 1) {
    count++;
  }

  // Adicionar a nova pontuação
  if (count < 5) {
    dados[count++] = score;
  } else if (score > dados[count - 1]) {
    dados[count - 1] = score;
  }

  // Ordenar do maior para o menor
  for (int i = 0; i < count - 1; i++) {
    for (int j = i + 1; j < count; j++) {
      if (dados[i] < dados[j]) {
        int temp = dados[i];
        dados[i] = dados[j];
        dados[j] = temp;
      }
    }
  }

  fclose(file);
  // Reabrir o arquivo em modo de escrita para sobrescrever os dados
  file = fopen("score.txt", "w+");

  // Escrever os scores ordenados no arquivo
  for (int i = 0; i < count; i++) {
    fprintf(file, "%d\n", dados[i]);
  }

  fclose(file);
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
  DrawText("Press backspace to return to Title Screen", 10, 10, 22, GREEN);
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
