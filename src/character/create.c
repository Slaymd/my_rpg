/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** create
*/

#include "rpg.h"

void set_character(character_t *character, int x, int y)
{
	sfSprite_setTexture(character->sprite, character->texture, sfTrue);
	sfSprite_setPosition(character->sprite, character->pos_screen);
	sfSprite_setTextureRect(character->sprite, character->rect);
	sfSprite_setScale(character->sprite, (V2F){ZOOM, ZOOM});
	sfSprite_setOrigin(character->sprite,
	(V2F){SIZE_C_X / 2, SIZE_C_Y / 1});
	sfRectangleShape_setSize(character->hp_bar, (V2F){50, 5});
	sfRectangleShape_setFillColor(character->hp_bar, sfGreen);
	sfRectangleShape_setPosition(character->hp_bar,
	(V2F){x - (SIZE_C_X / 3.4), y - 63});
	sfRectangleShape_setSize(character->mana_bar, (V2F){50, 5});
	sfRectangleShape_setFillColor(character->mana_bar, sfBlue);
	sfRectangleShape_setPosition(character->mana_bar,
	(V2F){x - (SIZE_C_X / 3.4), y - 55});
}

main_stat_t *init_character_stat(void)
{
	main_stat_t *stat = malloc(sizeof(main_stat_t));

	stat->hp = 100;
	stat->mana = 100;
	stat->hp_r = 2;
	stat->mana_r = 2;
	stat->hp_max = 100;
	stat->mana_max = 100;
	stat->xp = 0;
	stat->crit = 0;
	stat->clock = sfClock_create();
	stat->time = sfClock_getElapsedTime(stat->clock);
	stat->seconds = 0;
	return (stat);
}

character_t *init_character(void)
{
	character_t *character = malloc(sizeof(character_t));
	int x = WIDTH / 2;
	int y = HEIGHT / 2;

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
	character->stat = init_character_stat();
	character->hp_bar = sfRectangleShape_create();
	character->mana_bar = sfRectangleShape_create();
	set_character(character, x, y);
	return (character);
}
