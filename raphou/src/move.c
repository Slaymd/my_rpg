/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "proto.h"

void move_map(window_t *window)
{
	sfKeyboard_isKeyPressed(sfKeyUp) ? window->rect.top -= 20 : 0;
	sfKeyboard_isKeyPressed(sfKeyUp) ? window->rect.height -= 20 : 0;
	sfKeyboard_isKeyPressed(sfKeyDown) ? window->rect.top += 20 : 0;
	sfKeyboard_isKeyPressed(sfKeyUp) ? window->rect.height += 20 : 0;
	sfKeyboard_isKeyPressed(sfKeyRight) ? window->rect.left += 20 : 0;
	sfKeyboard_isKeyPressed(sfKeyUp) ? window->rect.width += 20 : 0;
	sfKeyboard_isKeyPressed(sfKeyLeft) ? window->rect.left -= 20 : 0;
	sfKeyboard_isKeyPressed(sfKeyUp) ? window->rect.width -= 20 : 0;
	window->rect.top < 0 ? window->rect.top = 0 : 0;
 	window->rect.left < 0 ? window->rect.left = 0 : 0;
	window->rect.width > SIZE_IMG_X ? window->rect.width = SIZE_IMG_X : 0;
	window->rect.height > SIZE_IMG_Y ? window->rect.height = SIZE_IMG_Y : 0;
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
