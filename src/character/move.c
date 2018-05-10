/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "rpg.h"

void move_character_y(character_t *character)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp))
		character->rect.top = 216;
	if (sfKeyboard_isKeyPressed(sfKeyDown))
		character->rect.top = 0;
}

void move_character_x(character_t *character)
{
	if (sfKeyboard_isKeyPressed(sfKeyRight))
		character->rect.top = 144;
	if (sfKeyboard_isKeyPressed(sfKeyLeft))
		character->rect.top = 72;
}

void move_character(character_t *character, rpg_t *rpg)
{
	move_character_y(character);
	move_character_x(character);
	(void)rpg;
	if (character->seconds >= 0.10 && (sfKeyboard_isKeyPressed(sfKeyLeft) ||
	sfKeyboard_isKeyPressed(sfKeyRight) ||
	sfKeyboard_isKeyPressed(sfKeyDown) || sfKeyboard_isKeyPressed(sfKeyUp)))
		character->rect.left += 68;
	(character->rect.left >= 272) ? character->rect.left = 0 : 0;
	sfSprite_setPosition(character->sprite, character->pos_screen);
	sfSprite_setTextureRect(character->sprite, character->rect);
	if (character->seconds >= 0.10)
		sfClock_restart(character->clock);
}
