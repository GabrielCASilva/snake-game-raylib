#include "gameScreen.h"
#include <raylib.h>

static Snake *snake[TOTAL_SNAKE_LEN];
static int snakeLen = SNAKE_INITIAL_SIZE;
static Collectable *c;
static int points;
static int isOver;

void game_screen_init() {
  // Inicializando as variaveis
  isOver = false;
  points = 0;
  snakeLen = SNAKE_INITIAL_SIZE;
  snake_init_vars();

  // Create snake
  float x = (int)MARGIN_ESQ +
            (GRID_SIZE * 5); // 5 é quantos quadrados a cobra vai ser criada
  float y = (int)MARGIN_SUP + (GRID_SIZE * 5);

  int head = 1;
  Vector2 position;

  for (int i = 0; i < snakeLen; i++) {
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

  // controle do jogador
  snake_control(snake);

  // movimento e ações da cobra
  if (*dt >= .2) {
    *dt = 0.0f;
    /* printf("is over: %d\n", isOver); */
    snake_move(snake, &isOver);

    if (isOver) {
      snake_die(snake);
      collectables_destroy(c);
      return;
    }

    // cobra colidindo com a margem do jogo
    snake_border_collision(snake);

    int canEat = snake_can_eat(snake[0], c);

    // colisao cobra e coletavel
    int c_points = snake_eat(snake, c, &canEat, &snakeLen);
    if (c_points) {
      collectables_destroy(c);
      Vector2 pos = grid_generate_collectable_position();
      c = collectables_create(pos);
    }
    points += c_points;
  }
}

void game_screen_pause(int *pause) {
  if (IsKeyPressed(KEY_P)) {
    if (*pause) {
      *pause = false;
    } else {
      *pause = true;
    }
  }
}

void game_screen_draw() {
  game_screen_draw_grid();
  snake_draw(snake, TOTAL_SNAKE_LEN);
  collectables_draw(c);
}

void game_screen_draw_grid() {
  // Desenhar linhas verticais
  for (int x = MARGIN_ESQ; x <= GAME_WIDTH; x += GRID_SIZE) {
    DrawLine(x, MARGIN_SUP, x, GAME_HEIGHT, DARKEST_GRAY);
  }

  // Desenhar linhas horizontais
  for (int y = MARGIN_SUP; y <= GAME_HEIGHT; y += GRID_SIZE) {
    DrawLine(MARGIN_ESQ, y, GAME_WIDTH, y, DARKEST_GRAY);
  }
}

void game_screen_destroy(int *gameOver) {
  if (isOver) {
    *gameOver = true;
    grid_reset();
  }
}
