#include "grid.h"

int grid[16][16] = {0};

void grid_mark_position(Vector2 pos) { grid[(int)pos.x][(int)pos.y] = 1; }

void grid_unmark_position(Vector2 pos) { grid[(int)pos.x][(int)pos.y] = 0; }

int grid_is_position_occupied(Vector2 pos) {
  return grid[(int)pos.x][(int)pos.y] == 1;
}

Vector2 grid_generate_collectable_position() {
  Vector2 pos = {.x = rand() % GRID_SIZE, .y = rand() % GRID_SIZE};
  if (grid_is_position_occupied(pos)) {
    return pos;
  }

  return grid_generate_collectable_position();
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
