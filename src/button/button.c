#include "button.h"

Button* button_create(
	int fontsize,
	const char *text,
	ButtonType type,
	Color textColor,
	Color color
) {
	Button* b = (Button*)malloc(sizeof(Button));

	if(b != NULL) {
		int textWidth = MeasureText(text, fontsize);
		b->fontsize = fontsize;
		b->width = textWidth;
		b->height = fontsize;
		b->text = text;
		b->type = type;
		b->textColor = textColor;
		b->color = color;
		b->isSelected = false;
	}

	return b;
}

void button_destroy(Button* b) {
	free(b);
	fprintf(stderr, "Sucesso: botão limpado da memória\n");
}

void button_draw(Button *b, int x, int y) {
	if (b->isSelected) {
		button_draw_selected(b, x, y);
	} else {
		button_draw_unselect(b, x, y);
	}
}

void button_draw_unselect(Button* b, int x, int y) {
	int pX = 8;
	int pY = 6;
	DrawRectangleLines(x - pX, y - pY, b->width + pX*2, b->height + pY*2, b->color);
	DrawText(b->text, x, y, b->fontsize, b->textColor);
}

void button_draw_selected(Button* b, int x, int y) {
	int pX = 8;
	int pY = 6;
	DrawRectangle(x - pX, y - pY, b->width + pX*2, b->height + pY*2, b->color);
	DrawText(b->text, x, y, b->fontsize, BLACK);
}

void button_selected(Button *b, int isSelected) {
	b->isSelected = isSelected;
}

GameScreen button_change_screen(Button *b, GameScreen current) {

	if (b->isSelected) {
		switch(b->type) {
			case BTN_TITLE:
				return SCR_TITLE;
			case BTN_GAME:
				return SCR_GAME;
			case BTN_LEADER_BOARD:
				return SCR_LEADER_BOARD;
			case BTN_CREDITS:
				return SCR_CREDITS;
			case BTN_PAUSE:
				return SCR_PAUSE;
		}
	}

	return current;
}

