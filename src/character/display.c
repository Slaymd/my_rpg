/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "rpg.h"

void display_character(rpg_t *rpg, character_t *c)
{
	c->time = sfClock_getElapsedTime(c->clock);
	c->seconds = c->time.microseconds / 1000000.0;
	move_character(c, rpg);
	character_regen(c);
	if (c->stat->hp > 0) {
		display_character_bar(rpg, c->stat->hp, c->stat->hp_max,
		c->hp_bar);
		display_character_bar(rpg, c->stat->mana, c->stat->mana_max,
		c->mana_bar);
	} else
		sfRenderWindow_close(rpg->wd);
	display_minimap(c->sprite, rpg);
	if (KeyPressed(sfKeyReturn))
		c->inter = 1;
}
