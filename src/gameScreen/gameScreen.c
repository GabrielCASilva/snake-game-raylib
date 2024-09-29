#include "gameScreen.h"

static Snake *snake[TOTAL_SNAKE_LEN];

void game_screen_init() {
  float x = 200.0;
  float y = 200.0;
  int head = 1;
  Vector2 position = {.x = 200.0, .y = 200.0};
  for (int i = 0; i < SNAKE_INITIAL_SIZE; i++) {
    position.x = (int)(x / GRID_SIZE) * GRID_SIZE - i * GRID_SIZE;
    position.y = (int)(y / GRID_SIZE) * GRID_SIZE;

    if (i > 0)
      head = 0;

    snake[i] = snake_create(GRID_SIZE, position, head);
  }
}

void game_screen_loop(float *dt) {

  // Desenhar linhas verticais
  for (float x = 0.0; x <= SCREEN_WIDTH; x += GRID_SIZE) {
    DrawLine(x, 0, x, SCREEN_HEIGHT, LIGHTGRAY);
  }

  // Desenhar linhas horizontais
  for (float y = 0.0; y <= SCREEN_HEIGHT; y += GRID_SIZE) {
    DrawLine(0, y, SCREEN_WIDTH, y, LIGHTGRAY);
  }

  // controle do jogador
  snake_control(snake);

  // movimento da cobra
  if (*dt >= .2) {
    *dt = 0.0f;
    snake_move(snake);
  }
}

void game_screen_draw() {
  // TODO: DESENHAR CONTEUDO NA TELA
  snake_draw(snake, TOTAL_SNAKE_LEN);
}

void game_screen_destroy() {
  // TODO: DESTRUIR VARIAVEIS
}
