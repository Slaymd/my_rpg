/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "proto.h"

void move_map(window_t *window)
{
	int move = 5;

	sfKeyboard_isKeyPressed(sfKeyUp) ? window->rect.top -= move : 0;
	sfKeyboard_isKeyPressed(sfKeyDown) ? window->rect.top += move : 0;
	sfKeyboard_isKeyPressed(sfKeyRight) ? window->rect.left += move : 0;
	sfKeyboard_isKeyPressed(sfKeyLeft) ? window->rect.left -= move : 0;
	window->rect.top < 0 ? window->rect.top = 0 : 0;
	window->rect.left < 0 ? window->rect.left = 0 : 0;
 	window->rect.left -= window->rect.left > SIZE_IMG_X - SIZE_Y? move : 0;
	window->rect.top -= window->rect.top > SIZE_IMG_Y - SIZE_Y? move : 0;
	sfSprite_setTextureRect(window->sprite, window->rect);
}

void move_character(character_t *character)
{
	sfKeyboard_isKeyPressed(sfKeyUp) ?
		character->rect.top = 216 : 0;
	sfKeyboard_isKeyPressed(sfKeyDown) ?
		character->rect.top = 0 : 0;
	sfKeyboard_isKeyPressed(sfKeyRight) ?
		character->rect.top = 144 : 0;
	sfKeyboard_isKeyPressed(sfKeyLeft) ?
		character->rect.top = 72 : 0;
	character->rect.left += 68;
	(character->rect.left >= 272) ? character->rect.left = 0 : 0;
	sfSprite_setTextureRect(character->sprite, character->rect);
}
