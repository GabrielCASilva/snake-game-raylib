#include "snake.h"
#include "stdio.h"
#include <raylib.h>

Snake *snake_create(int grid, Vector2 position, int head) {
  Snake *snake = (Snake *)malloc(sizeof(Snake));

  if (snake != NULL) {
    snake->position = position;
    snake->direction = (Vector2){0, 0};
    snake->size = (Vector2){grid, grid};
    snake->speed = 5;
    snake->len = 3;
    if (head) {
      snake->color = LIME;
    } else {
      snake->color = GREEN;
    }
  }

  return snake;
}

void snake_move(Snake *snake[]) {
  // TODO: MOVIMENTO DA COBRA
  Snake *head = snake[0];
  if (IsKeyPressed(KEY_RIGHT)) {
    head->direction.x = 1;
  }
  head->position.x = head->position.x + head->size.x * head->direction.x;
}

void snake_draw(Snake *snake[], int len) {
  for (int i = 0; i < len; i++) {
    if (snake[i] == NULL)
      break;
    Snake *s = snake[i];
    DrawRectangle(s->position.x, s->position.y, s->size.x, s->size.y, s->color);
  }
}

void snake_eat(Snake *snake) {
  // TODO: FAZER A COBRA COMER A MAÇÃ OU ALGUMA OUTRA COISA
}

void snake_die(Snake *snake) {
  // TODO: FAZER A COBRA MORRER
}
