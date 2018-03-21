/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** free
*/

#include "rpg.h"

void free_rpg(rpg_t *rpg)
{
	sfRenderWindow_destroy(rpg->window->window);
	sfTexture_destroy(rpg->window->texture);
	sfSprite_destroy(rpg->window->sprite);
	sfClock_destroy(rpg->window->clock);
	free(rpg->window);
	sfTexture_destroy(rpg->character->texture);
	sfSprite_destroy(rpg->character->sprite);
	free(rpg->character);
	free(rpg);
}
