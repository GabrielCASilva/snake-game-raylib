#ifndef BUTTON_H 
#define BUTTON_H

#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include "../enums/enums.h"

typedef struct {
	int fontsize;
	int width;
	int height;
	const char *text;
	ButtonType type;
	Color textColor;
	Color color;
	int isSelected;
} Button;

Button* button_create(
	int fontsize,
	const char *text,
	ButtonType type,
	Color textColor,
	Color color );

void button_destroy(Button *b);

void button_draw(Button *b, int x, int y);

void button_draw_unselect(Button *b, int x, int y);

void button_draw_selected(Button *b, int x, int y);

void button_selected(Button *b, int isSelected);

GameScreen button_change_screen(Button *b, GameScreen current);

#endif
