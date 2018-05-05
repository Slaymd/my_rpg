/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** cycle
*/

#include "rpg.h"

void run_cycle(cycle_t *cycle)
{
	sfColor color = sfSprite_getColor(cycle->cycle->sprite);

	if (cycle->h >= 18 || cycle->h <= 6)
		color.a = 75;
	else
		color.a = 0;
	sfSprite_setColor(cycle->cycle->sprite, color);
}

void cycle_handler(rpg_t *rpg)
{
	refresh_time(rpg->cycle, rpg);
	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	display_time(rpg->cycle, rpg->wd);
	display_particle(rpg->cycle->cycle, rpg->wd,
	(V2F){WIDTH / 2, HEIGHT / 2}, 1);
}
