#ifndef MACROS_H
#define MACROS_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define TOTAL_SNAKE_LEN 32
#define GRID_SIZE 32
#define SNAKE_INITIAL_SIZE 3

#define GAME_SIZE (GRID_SIZE * 16) // 16 x 16 quadrados

// Calcula as margens para centralizar o quadrado
#define MARGIN_ESQ ((SCREEN_WIDTH - GAME_SIZE) / 2)
#define MARGIN_DIR MARGIN_ESQ
#define MARGIN_SUP ((SCREEN_HEIGHT - GAME_SIZE) / 2)
#define MARGIN_INF MARGIN_SUP

#define GAME_WIDTH (SCREEN_WIDTH - MARGIN_ESQ)
#define GAME_HEIGHT (SCREEN_HEIGHT - MARGIN_SUP)

#define DARKEST_GRAY (Color){80, 80, 80, 255}

#endif
