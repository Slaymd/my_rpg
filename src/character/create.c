/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** create
*/

#include "rpg.h"

void set_character(character_t *character)
{
	sfSprite_setTexture(character->sprite, character->texture, sfTrue);
	sfSprite_setPosition(character->sprite, character->pos_screen);
	sfSprite_setTextureRect(character->sprite, character->rect);
}

character_t *init_character(void)
{
	character_t *character = malloc(sizeof(character_t));
	int x = WIDTH / 2 - SIZE_C_X / 2;
	int y = HEIGHT / 2 - SIZE_C_Y / 2;

	if (!character)
		return (NULL);
	character->texture = sfTexture_createFromFile("./img/sacha.png", NULL);
	character->sprite = sfSprite_create();
	character->clock = sfClock_create();
	character->time = sfClock_getElapsedTime(character->clock);
	character->seconds = 0;
	character->rect = (sfIntRect){0,0, SIZE_C_X, SIZE_C_Y};
	character->speed = 4;
	character->pos_screen = (V2F){x, y};
	character->pos = (pos_t){16000, 16000, 0};
	set_character(character);
	return (character);
}
