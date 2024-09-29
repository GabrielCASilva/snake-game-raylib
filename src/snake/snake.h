#ifndef SNAKE_H
#define SNAKE_H

#include "raylib.h"
#include <stdlib.h>

typedef struct Snake {
  Vector2 position;
  Vector2 direction;
  Vector2 size;
  int speed;
  int len;
  int canMove;
  Color color;
} Snake;

Snake *snake_create(int grid, Vector2 position, int head);

void snake_control(Snake *snake[]);

void snake_move_head(Snake *snake);

void snake_move(Snake *snake[]);

void snake_draw(Snake *snake[], int len);

void snake_eat(Snake *snake);

void snake_die(Snake *snake);

#endif
