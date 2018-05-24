/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "rpg.h"

void move_character_rect(character_t *character)
{
	if (sfKeyboard_isKeyPressed(sfKeyZ))
		character->rect.top = 216;
	else if (sfKeyboard_isKeyPressed(sfKeyS))
		character->rect.top = 0;
	else {
		if (sfKeyboard_isKeyPressed(sfKeyD))
			character->rect.top = 144;
		else if (sfKeyboard_isKeyPressed(sfKeyQ))
			character->rect.top = 72;
	}
}

void move_character(character_t *character, rpg_t *rpg)
{
	move_character_rect(character);
	(void)rpg;
	if (character->seconds >= 0.10 && (sfKeyboard_isKeyPressed(sfKeyQ) ||
	sfKeyboard_isKeyPressed(sfKeyD) ||
	sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyZ)))
		character->rect.left += 68;
	(character->rect.left >= 272) ? character->rect.left = 0 : 0;
	sfSprite_setPosition(character->sprite, character->pos_screen);
	sfSprite_setTextureRect(character->sprite, character->rect);
	if (character->seconds >= 0.10)
		sfClock_restart(character->clock);
}
