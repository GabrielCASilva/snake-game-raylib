#include "snake.h"
#include "stdio.h"
#include <raylib.h>

static int allowMove = false;

Snake *snake_create(int grid, Vector2 position, int head) {
  Snake *snake = (Snake *)malloc(sizeof(Snake));

  if (snake != NULL) {
    snake->position = position;
    snake->direction = (Vector2){0, 0};
    snake->size = (Vector2){grid, grid};
    snake->speed = 5;
    if (head) {
      snake->color = GREEN;
    } else {
      snake->color = (Color){0, 228 - 40, 48, 255};
    }
  }

  return snake;
}

void snake_control(Snake *snake[]) {
  Snake *head = snake[0];
  if (IsKeyPressed(KEY_RIGHT) && !head->direction.x) {
    head->direction = (Vector2){1, 0};
    allowMove = true;
  }

  if (IsKeyPressed(KEY_LEFT) && !head->direction.x) {
    head->direction = (Vector2){-1, 0};
    allowMove = true;
  }

  if (IsKeyPressed(KEY_UP) && !head->direction.y) {
    head->direction = (Vector2){0, -1};
    allowMove = true;
  }

  if (IsKeyPressed(KEY_DOWN) && !head->direction.y) {
    head->direction = (Vector2){0, 1};
    allowMove = true;
  }
}

void snake_move(Snake *snake[]) {
  if (allowMove) {
    Vector2 prevPos = snake[0]->position;
    for (int i = 0; snake[i] != NULL; i++) {
      if (i == 0) {
        snake_move_head(snake[i]);
      } else {
        Vector2 tempPos = snake[i]->position;
        snake[i]->position = prevPos;
        prevPos = tempPos;
      }
    }
  }
}

void snake_move_head(Snake *snake) {
  snake->position.x += snake->size.x * snake->direction.x;
  snake->position.y += snake->size.y * snake->direction.y;
}

void snake_border_collision(Snake *snake[]) {
  if (snake[0]->position.x >= (int)GAME_WIDTH) {
    snake[0]->position.x = (int)MARGIN_ESQ;
  }

  if (snake[0]->position.x < (int)MARGIN_ESQ) {
    snake[0]->position.x = (int)GAME_WIDTH - 32;
  }

  if (snake[0]->position.y >= (int)GAME_HEIGHT) {
    snake[0]->position.y = (int)MARGIN_SUP;
  }

  if (snake[0]->position.y < (int)MARGIN_SUP) {
    snake[0]->position.y = (int)GAME_HEIGHT - 32;
  }
}

void snake_draw(Snake *snake[], int len) {
  for (int i = 0; snake[i] != NULL; i++) {
    Snake *s = snake[i];
    DrawRectangle(s->position.x, s->position.y, s->size.x, s->size.y, s->color);
  }
}

int snake_can_eat(Snake *head, Collectable *c) {
  if (head->position.x == c->position.x && head->position.y == c->position.y)
    return 1;
  return 0;
}

// coleta e retorna os pontos colecados
int snake_eat(Snake *snake[], Collectable *c, int *canEat, int *snakeLen) {
  if (*canEat) {
    *canEat = false;
    // fazer a cobra aumentar de tamanho
    // a cauda nova fica com a mesma posição da cauda antiga
    // porque a posição da cauda vai atualizar corretamente na próxima vez que a
    // cauda se mover
    Snake *tail = snake[*snakeLen - 1];
    snake[*snakeLen] = snake_create(GRID_SIZE, tail->position, false);
    *snakeLen += 1;

    // TODO: fazer com que a maça suma e talvez resurja também por aqui?
    return c->points;
  }
  return 0;
}

void snake_die(Snake *snake) {
  // TODO: FAZER A COBRA MORRER
}
