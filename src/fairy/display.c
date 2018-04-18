/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** display
*/

#include "rpg.h"

void display_fairy(rpg_t *rpg, sfEvent event)
{
	rpg->fairy->time = sfClock_getElapsedTime(rpg->fairy->clock);
	rpg->fairy->seconds = rpg->fairy->time.microseconds / 1000000.0;
	move_fairy(rpg->fairy, rpg, event);
	fairy_fight(rpg->fairy);
	display_minimap(rpg->fairy->sprite, rpg);
}
