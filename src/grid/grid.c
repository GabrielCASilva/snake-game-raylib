#include "grid.h"
#include <raylib.h>

int grid[16][16] = {0};

void grid_mark_position(Vector2 pos) { grid[(int)pos.x][(int)pos.y] = 1; }

void grid_unmark_position(Vector2 pos) { grid[(int)pos.x][(int)pos.y] = 0; }

int grid_is_position_occupied(Vector2 pos) {
  return grid[(int)pos.x][(int)pos.y] == 1;
}

int random_num(int min, int max) { return rand() % (max - min + 1) + min; }

Vector2 grid_generate_collectable_position() {
  Vector2 pos;
  Vector2 pos_num;
  do {
    // Gera a posição na grade, ajustando para múltiplos de GRID_SIZE
    int grid_posx =
        random_num(MARGIN_ESQ / GRID_SIZE, GAME_SIZE / GRID_SIZE - 1);
    int grid_posy =
        random_num(MARGIN_SUP / GRID_SIZE, GAME_SIZE / GRID_SIZE - 1);

    // Converte posições de grid para coordenadas reais
    int posx = MARGIN_ESQ + grid_posx * GRID_SIZE;
    int posy = MARGIN_SUP + grid_posy * GRID_SIZE;

    pos = (Vector2){.x = posx, .y = posy};
    pos_num = (Vector2){.x = grid_posx, .y = grid_posy};

    // Verifica se a posição está ocupada, baseado na posição da grade
  } while (grid_is_position_occupied(pos_num));

  return pos; // Retorna a posição válida
}

Vector2 grid_get_position_without_offset(Vector2 pos) {
  Vector2 pos_without_offset = pos;

  int offset_x = MARGIN_ESQ / 32;
  int offset_y = MARGIN_SUP / 32;

  pos_without_offset.x = (pos_without_offset.x / 32) - offset_x;
  pos_without_offset.y = (pos_without_offset.y / 32) - offset_y;

  return pos_without_offset;
}

void grid_debug() {
  for (int y = 0; y < 16; y++) {
    for (int x = 0; x < 16; x++) {
      printf("%d ", grid[x][y]);
    }
    printf("\n");
  }
  printf("\n");
}

void grid_helper_mark(Vector2 pos) {
  Vector2 pos_grid = grid_get_position_without_offset(pos);
  grid_mark_position(pos_grid);
}

void grid_helper_unmark(Vector2 pos) {
  Vector2 pos_grid = grid_get_position_without_offset(pos);
  grid_unmark_position(pos_grid);
}
