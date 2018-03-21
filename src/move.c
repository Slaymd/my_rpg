/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "rpg.h"

void move_map(window_t *ww, character_t *cr)
{
	if (cr->pos.y == SIZE_S_Y / 2 - SIZE_C_Y / 2) {
		sfKeyboard_isKeyPressed(sfKeyUp) ?
			ww->rect.top -= cr->speed : 0;
		sfKeyboard_isKeyPressed(sfKeyDown) ?
			ww->rect.top += cr->speed : 0;
	} if (cr->pos.x == SIZE_S_X / 2 - SIZE_C_X / 2) {
		sfKeyboard_isKeyPressed(sfKeyRight) ?
			ww->rect.left += cr->speed : 0;
		sfKeyboard_isKeyPressed(sfKeyLeft) ?
			ww->rect.left -= cr->speed : 0;
	}
	ww->rect.top < 0 ? ww->rect.top = 0 : 0;
	ww->rect.left < 0 ? ww->rect.left = 0 : 0;
 	if (ww->rect.left > SIZE_I_X - SIZE_S_X)
		ww->rect.left = SIZE_I_X - SIZE_S_X;
	if (ww->rect.top > SIZE_I_Y - SIZE_S_Y)
		ww->rect.top = SIZE_I_Y - SIZE_S_Y;
	sfSprite_setTextureRect(ww->sprite, ww->rect);
}

void move_character_y(character_t *character, window_t *window)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		if (window->rect.top == 0) {
			character->pos.y -= character->speed;
			character->pos.y < 0 ? character->pos.y = 0 : 0;
		} if (character->pos.y > SIZE_S_Y / 2 - SIZE_C_Y / 2) {
			character->pos.y -= character->speed;
			character->pos.y < SIZE_S_Y / 2 - SIZE_C_Y / 2
			? character->pos.y = SIZE_S_Y / 2 - SIZE_C_Y / 2 : 0;
		}
		character->rect.top = 216;
	} if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		if (character->pos.y < SIZE_S_Y / 2 - SIZE_C_Y / 2) {
			character->pos.y += character->speed;
			character->pos.y > SIZE_S_Y / 2 - SIZE_C_Y / 2
			? character->pos.y = SIZE_S_Y / 2 - SIZE_C_Y / 2 : 0;
		} if (window->rect.top == SIZE_I_Y - SIZE_S_Y) {
			character->pos.y += character->speed;
			character->pos.y > SIZE_S_Y - SIZE_C_Y
			? character->pos.y = SIZE_S_Y - SIZE_C_Y : 0;
		}
		character->rect.top = 0;
	}
}

void move_character_x(character_t *character, window_t *window)
{
	if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		if (character->pos.x < SIZE_S_X / 2 - SIZE_C_X / 2) {
			character->pos.x += character->speed;
			character->pos.x > SIZE_S_X / 	2 - SIZE_C_X / 2
			? character->pos.x = SIZE_S_X / 2 - SIZE_C_X / 2 : 0;
		} if (window->rect.left == SIZE_I_X - SIZE_S_X) {
			character->pos.x += character->speed;
			character->pos.x > SIZE_S_X - SIZE_C_X
			? character->pos.x = SIZE_S_X - SIZE_C_X : 0;
		}
		character->rect.top = 144;
	} if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		if (window->rect.left == 0) {
			character->pos.x -= character->speed;
			character->pos.x < 0 ? character->pos.x = 0 : 0;
		} if (character->pos.x > SIZE_S_X / 2 - SIZE_C_X / 2) {
			character->pos.x -= character->speed;
			character->pos.x < SIZE_S_X / 2 - SIZE_C_X / 2
			? character->pos.x = SIZE_S_X / 2 - SIZE_C_X / 2 : 0;
		}
		character->rect.top = 72;
	}
}

void move_character(character_t *character, window_t *window)
{
	move_character_y(character, window);
	move_character_x(character, window);
	if (window->seconds >= 0.10 && (sfKeyboard_isKeyPressed(sfKeyLeft) ||
	sfKeyboard_isKeyPressed(sfKeyRight) ||
	sfKeyboard_isKeyPressed(sfKeyDown) || sfKeyboard_isKeyPressed(sfKeyUp)))
		character->rect.left += 68;
	(character->rect.left >= 272) ? character->rect.left = 0 : 0;
	sfSprite_setPosition(character->sprite, character->pos);
	sfSprite_setTextureRect(character->sprite, character->rect);
}
