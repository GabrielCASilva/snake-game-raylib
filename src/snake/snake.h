#ifndef SNAKE_H
#define SNAKE_H

#include "../collectables/collectables.h"
#include "../macros.h"
#include <raylib.h>
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

void snake_border_collision(Snake *snake[]);

void snake_draw(Snake *snake[], int len);

int snake_eat(Snake *snake[], Collectable *c, int *canEat, int *snakeLen);

int snake_can_eat(Snake *head, Collectable *c);

void snake_die(Snake *snake);

#endif
