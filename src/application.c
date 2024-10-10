#include "application.h"
#include "gameScreen/gameScreen.h"
#include <raylib.h>

GameScreen currentScreen = SCR_GAME;
int initLoad = true;
static int gameOver = false;

void loop(float *dt) {
  if (IsKeyPressed(KEY_BACKSPACE)) {
    currentScreen = SCR_TITLE;
    initLoad = true;
    gameOver = false;
  }

  switch (currentScreen) {
  case SCR_TITLE:
    if (initLoad) {
      title_screen_loop_init();
      initLoad = false;
    }

    title_screen_loop();
    if (IsKeyPressed(KEY_ENTER)) {
      currentScreen = title_screen_change(currentScreen);
      title_screen_destroy();
      initLoad = true;
    }
    break;
  case SCR_GAME:
    if (initLoad) {
      game_screen_init();
      initLoad = false;
    }

    game_screen_loop(dt);
    game_screen_destroy(&gameOver);

    if (gameOver) {
      currentScreen = SCR_GAMEOVER;
      initLoad = true;
      gameOver = false;
    }
    break;
  case SCR_LEADER_BOARD:
    if (initLoad) {
      initLoad = false;
    }
    break;
  case SCR_CREDITS:
    if (initLoad) {
      initLoad = false;
    }
    break;
  case SCR_GAMEOVER:
    if (initLoad) {
      initLoad = false;
    }
    break;
  default:
    if (initLoad) {
      initLoad = false;
    }
    break;
  }
}

void draw() {
  BeginDrawing();
  ClearBackground(BLACK);

  switch (currentScreen) {
  case SCR_TITLE:
    title_screen_draw();
    break;
  case SCR_GAME:
    game_screen_draw();
    break;
  case SCR_LEADER_BOARD:
    temp_text_func("SCORE");
    break;
  case SCR_CREDITS:
    temp_text_func("CREDITS");
    break;
  case SCR_GAMEOVER:
    temp_text_func("GAME OVER");
    break;
  default:
    break;
  }

  EndDrawing();
}

void temp_text_func(const char *text) {
  const char *title = text;
  int fontsize = 30;
  int titleWidth = MeasureText(title, fontsize);

  int titlePosX = GetScreenWidth() / 2 - titleWidth / 2;
  int titlePosY = GetScreenHeight() / 2 - fontsize / 2;

  DrawText(title, titlePosX, titlePosY, fontsize, GREEN);
}
