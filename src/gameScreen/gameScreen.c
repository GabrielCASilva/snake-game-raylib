#include "gameScreen.h"

static Snake *snake[TOTAL_SNAKE_LEN];
static Collectable *c;

void game_screen_init() {
  // Create snake
  float x = (int)MARGIN_ESQ +
            (GRID_SIZE * 5); // 5 é quantos quadrados a cobra vai ser criada
  float y = (int)MARGIN_SUP + (GRID_SIZE * 5);

  int head = 1;
  Vector2 position;

  for (int i = 0; i < SNAKE_INITIAL_SIZE; i++) {
    // A posição da cobra deve ser sempre alinhada à grid
    position.x = x - i * GRID_SIZE; // Move cada parte para a esquerda
    position.y = y;

    if (i > 0)
      head = 0; // Apenas a primeira parte é a cabeça

    // Cria cada segmento da cobra
    snake[i] = snake_create(GRID_SIZE, position, head);
  }

  // Create Collectable
  float c_x = (int)MARGIN_ESQ + (GRID_SIZE * 10);
  float c_y = (int)MARGIN_SUP + (GRID_SIZE * 10);

  c = collectables_create((Vector2){c_x, c_y});
}

void game_screen_loop(float *dt) {
  // Desenhar linhas verticais
  for (int x = MARGIN_ESQ; x <= GAME_WIDTH; x += GRID_SIZE) {
    DrawLine(x, MARGIN_SUP, x, GAME_HEIGHT, DARKEST_GRAY);
  }

  // Desenhar linhas horizontais
  for (int y = MARGIN_SUP; y <= GAME_HEIGHT; y += GRID_SIZE) {
    DrawLine(MARGIN_ESQ, y, GAME_WIDTH, y, DARKEST_GRAY);
  }

  // controle do jogador
  snake_control(snake);

  // movimento da cobra
  if (*dt >= .2) {
    *dt = 0.0f;
    snake_move(snake);
    // cobra colidindo com a margem do jogo
    snake_border_collision(snake);
  }
}

void game_screen_draw() {
  snake_draw(snake, TOTAL_SNAKE_LEN);
  collectables_draw(c);
}

void game_screen_destroy() {
  // TODO: DESTRUIR VARIAVEIS
}
