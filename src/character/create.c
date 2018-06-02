/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** create
*/

#include "../../include/rpg.h"

void set_character(character_t *character, int x, int y)
{
	sfSprite_setTexture(character->sprite, character->texture, sfTrue);
	sfSprite_setPosition(character->sprite, character->pos_screen);
	sfSprite_setTextureRect(character->sprite, character->rect);
	sfSprite_setScale(character->sprite, (V2F){ZOOM, ZOOM});
	sfSprite_setOrigin(character->sprite, (V2F){SIZE_C_X / 2, SIZE_C_Y});
	sfRectangleShape_setSize(character->hp_bar, (V2F){50, 5});
	sfRectangleShape_setFillColor(character->hp_bar, sfGreen);
	sfRectangleShape_setPosition(character->hp_bar,
	(V2F){x - (SIZE_C_X / 3.4), y - 63});
	sfRectangleShape_setSize(character->mana_bar, (V2F){50, 5});
	sfRectangleShape_setFillColor(character->mana_bar, sfBlue);
	sfRectangleShape_setPosition(character->mana_bar,
	(V2F){x - (SIZE_C_X / 3.4), y - 55});
}

main_stat_t *init_character_stat(character_t *character)
{
	main_stat_t *stat = malloc(sizeof(main_stat_t));

	stat->attack = 0;
	stat->defense = 0;
	stat->hp = 0;
	stat->mana = 0;
	stat->hp_r = 0;
	stat->mana_r = 0;
	stat->hp_max = 0;
	stat->mana_max = 0;
	stat->xp = 0;
	stat->level = 0;
	if (config_character_stat(stat) == 84)
		return (NULL);
	stat->clock = sfClock_create();
	stat->time = sfClock_getElapsedTime(stat->clock);
	stat->seconds = 0;
	character->skin_sex = "sacha";
	character->skin_color = "red";
	return (stat);
}

character_t *init_character(void)
{
	character_t *character = malloc(sizeof(character_t));

	if (!character)
		return (NULL);
	character->texture = sfTexture_createFromFile(CHAR_DEFAULT_SKIN, NULL);
	character->sprite = sfSprite_create();
	character->clock = sfClock_create();
	character->time = sfClock_getElapsedTime(character->clock);
	character->seconds = 0;
	character->inter = 0;
	character->rect = (sfIntRect){0,0, SIZE_C_X, SIZE_C_Y};
	character->speed = 4;
	character->pos_screen = (V2F){WIDTH / 2, HEIGHT / 2};
	character->stat = init_character_stat(character);
	if (!character->stat)
		return (NULL);
	character->hp_bar = sfRectangleShape_create();
	character->mana_bar = sfRectangleShape_create();
	set_character(character, WIDTH / 2, HEIGHT / 2);
	return (character);
}
