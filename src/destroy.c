/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** free
*/

#include "rpg.h"

void free_fairy(fairy_t *fairy)
{
	sfSprite_destroy(fairy->sprite);
	sfTexture_destroy(fairy->texture);
	sfClock_destroy(fairy->clock);
	sfMusic_destroy(fairy->shhh);
}

void free_character(character_t *character)
{
	sfSprite_destroy(character->sprite);
	sfTexture_destroy(character->texture);
	sfClock_destroy(character->clock);
}

void free_rpg(rpg_t *rpg)
{
	sfRenderWindow_destroy(rpg->wd);
	free_fairy(rpg->fairy);
	free_character(rpg->character);
}
