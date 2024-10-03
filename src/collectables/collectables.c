#include "collectables.h"
#include <raylib.h>
#include <stdlib.h>

/* typedef struct Collectable { */
/*   int points; */
/* } Collactable; */

Collectable *collectables_create(Vector2 position) {
  Collectable *apple = (Collectable *)malloc(sizeof(Collectable));

  if (apple != NULL) {
    apple->points = 1;
    apple->position = position;
    apple->size = (Vector2){GRID_SIZE, GRID_SIZE};
    apple->color = RED;
  }

  return apple;
}

void collectables_draw(Collectable *c) {
  DrawRectangle(c->position.x, c->position.y, c->size.x, c->size.y, c->color);
}

// retorna a pontuação do objeto destruido
int collectables_destroy() { return 0; }
