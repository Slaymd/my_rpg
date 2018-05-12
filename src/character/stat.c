/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** stat
*/

#include "rpg.h"

void display_character_bar(rpg_t *rpg, float stat, float max, sfRectangleShape *bar)
{
	float nbr = 50 * (stat / max) * ZOOM;

	sfRectangleShape_setSize(bar, (V2F){nbr, 5});
	sfRenderWindow_setView(rpg->wd, rpg->view->v_screen);
	sfRenderWindow_drawRectangleShape(rpg->wd, bar, NULL);
}

void character_regen(character_t *c)
{
	c->stat->time = sfClock_getElapsedTime(c->stat->clock);
	c->stat->seconds = c->stat->time.microseconds / 1000000.0;
	if (c->stat->seconds >= 1) {
		if (c->stat->hp < c->stat->hp_max)
			c->stat->hp += c->stat->hp_r;
		if (c->stat->mana < c->stat->mana_max)
			c->stat->mana += c->stat->mana_r;
		c->stat->hp > c->stat->hp_max ?
		c->stat->hp = c->stat->hp_max : 0;
		c->stat->mana > c->stat->mana_max ?
		c->stat->mana = c->stat->mana_max : 0;
		sfClock_restart(c->stat->clock);
	}
}

void level_up(character_t *character, float increase)
{
	character->attack *= increase;
	character->hp *= increase;
	character->mana *= increase;
	character->defense *= increase;
	character->hp_r *= increase;
	character->mana_r *= increase;
	character->hp_max *= increase;
	character->mana_max *= increase;
}

void character_regen(character_t *character)
{
	character_regen(character);
	if (character->xp >= 100 + character->level * 5) {
		level_up(character, 1.2);
		character->level++;
		character->xp = 0;
	}
}
