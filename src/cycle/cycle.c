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
	float alpha = 0;

	if (cycle->h >= 20 || cycle->h <= 4) {
		alpha = 75;
	} else if (cycle->h >= 18) {
		alpha = (cycle->h + (float)cycle->m / 60) - 18;
		alpha = alpha / 2 * 75;
	} else {
		if (cycle->h <= 6) {
			alpha = (cycle->h - 5 + (float)cycle->m / 60) * -1 + 2;
			alpha = alpha / 2 * 75;
		}
	}
	color.a = (int)alpha;
	sfSprite_setColor(cycle->cycle->sprite, color);
}

void cycle_handler(rpg_t *rpg)
{
	refresh_time(rpg->cycle);
	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	display_time(rpg->cycle, rpg->wd);
	display_particle(rpg->cycle->cycle, rpg->wd,
	(V2F){WIDTH / 2, HEIGHT / 2}, 1);
}
