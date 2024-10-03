#ifndef COLLECTABLES_H
#define COLLECTABLES_H

#include "../macros.h"
#include <raylib.h>

typedef struct Collectable {
  int points;
  Vector2 position;
  Vector2 size;
  Color color;
} Collectable;

Collectable *collectables_create(Vector2 position);

void collectables_draw(Collectable *collectable);

// retorna a pontuação do objeto destruido
int collectables_destroy();

#endif
