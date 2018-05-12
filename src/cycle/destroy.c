/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** free
*/

#include "rpg.h"

void free_cycle(cycle_t *cycle)
{
	sfSprite_destroy(cycle->s_clock);
	sfTexture_destroy(cycle->t_clock);
	sfText_destroy(cycle->text);
	sfFont_destroy(cycle->font);
	sfSprite_destroy(cycle->s_rain);
	sfTexture_destroy(cycle->t_rain);
	sfClock_destroy(cycle->clock);
	destroy_particle(cycle->cycle);
	free(cycle);
}
