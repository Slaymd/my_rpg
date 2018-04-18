/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "rpg.h"

void display_character(rpg_t *rpg)
{
	rpg->character->time = sfClock_getElapsedTime(rpg->character->clock);
	rpg->character->seconds = rpg->character->time.microseconds / 1000000.0;
	move_character(rpg->character, rpg);
	display_minimap(rpg->character->sprite, rpg);
}
