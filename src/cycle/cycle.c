/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** cycle
*/

#include "rpg.h"

void change_sprite_color(sfSprite *sprite)
{
	sfColor color = sfSprite_getColor(sprite);

	for (int i = 0; i < 50 && color.b <= 255; i++)
		color.b += 1;
	sfSprite_setColor(sprite, color);
}

void run_cycle(rpg_t *rpg)
{
	// while ("JE C PA") {
		// change_sprite_color();
	// }
}

void cycle_handler(rpg_t *rpg)
{
	refresh_time(rpg->cycle, rpg);
	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	display_time(rpg->cycle, rpg->wd);
}
