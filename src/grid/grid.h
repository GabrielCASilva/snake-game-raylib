#include "../macros.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

void grid_mark_position(Vector2 pos);

void grid_unmark_position(Vector2 pos);

int grid_is_position_occupied(Vector2 pos);

Vector2 grid_generate_collectable_position();

Vector2 grid_get_position_without_offset(Vector2 pos);

void grid_helper_mark(Vector2 pos);

void grid_helper_unmark(Vector2 pos);

void grid_debug();

void grid_reset();
