#include "application.h"
#include "grid/grid.h"
#include "macros.h"
#include "raylib.h"

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game");

  float dt = 0.0f;
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    dt += GetFrameTime();
    // GameLoop
    loop(&dt);
    // Drawing Textures
    draw();

    /* grid_debug(); */
  }

  CloseWindow();
  return 0;
}
