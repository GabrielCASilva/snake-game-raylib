#include "titleScreen.h"

static Button* buttons[3];
static int selected_index = 0;

void title_screen_loop_init() {
	char *texts[] = {"START", "SCORE", "CREDITS"};
	ButtonType types[] = { BTN_GAME, BTN_LEADER_BOARD, BTN_CREDITS };

	for (int i = 0; i < 3; i++) {
		buttons[i] = button_create(
			22, 
			texts[i],
			types[i],
			GREEN,
			GREEN
		);
	}
}

void title_screen_loop() {
	button_selected(buttons[selected_index], 1);

	if (IsKeyPressed(KEY_DOWN) && selected_index < 2) {
		button_selected(buttons[selected_index], 0);
		selected_index += 1;

	}

	if (IsKeyPressed(KEY_UP) && selected_index > 0) {
		button_selected(buttons[selected_index], 0);
		selected_index -= 1;
	}
}

void title_screen_destroy() {
	for (int i = 0; i < 3; i++) {
		if (buttons[i] != NULL) {
			button_destroy(buttons[i]);
			buttons[i] = NULL;
		}
	}
}

void title_screen_draw() {
	title_screen_draw_title();
	
	for (int i = 0; i < 3; i++) {
		int posX = GetScreenWidth()/2 - buttons[i]->width/2;
		int posY = GetScreenHeight()/2 + 42 - 42 + (54 * i);
		button_draw(buttons[i], posX, posY);
	}
}

void title_screen_draw_title() {
	const char *title = "SNAKE GAME";
	int fontsize = 30;
	int titleWidth = MeasureText(title, fontsize);
	
	int titlePosX = GetScreenWidth()/2 - titleWidth/2;
	int titlePosY = GetScreenHeight()/2 - fontsize/2 - 42;

	DrawText(title, titlePosX, titlePosY, fontsize, GREEN);
}

GameScreen title_screen_change(GameScreen current) {
	return button_change_screen(buttons[selected_index], current);
}
