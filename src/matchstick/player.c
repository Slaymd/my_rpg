/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** tile
*/

#include "rpg.h"

void match_input(match_t *match, stick_t *stick)
{
	match->x -= (sfKeyboard_isKeyPressed(sfKeyUp)) ? 1 : 0;
	match->x += (sfKeyboard_isKeyPressed(sfKeyDown)) ? 1 : 0;
	match->x = (match->x < 0) ? 0 : match->x;
	match->x = (match->x > stick->lines - 1) ? stick->lines - 1: match->x;
	match->y = (sfKeyboard_isKeyPressed(sfKeyUp)) ?
	stick->line[match->x] + 1: match->y;
	match->y = (sfKeyboard_isKeyPressed(sfKeyDown)) ?
	stick->line[match->x] + 1 : match->y;
	match->y += (sfKeyboard_isKeyPressed(sfKeyRight)) ? 1 : 0;
	match->y -= (sfKeyboard_isKeyPressed(sfKeyLeft)) ? 1 : 0;
	match->y = (match->y > stick->line[match->x] + 1) ?
	stick->line[match->x] + 1 : match->y;
	match->y += (stick->line[match->x] - match->y + 1 > stick->max) ?
	1 : 0;
	match->y = (match->y < 1) ? 1 : match->y;
}

void player_play(match_t *match, stick_t *stick)
{
	match_input(match, stick);
	if (sfKeyboard_isKeyPressed(sfKeyReturn) &&
	match->y < stick->line[match->x] + 1) {
		stick->line[match->x] -=
		(stick->line[match->x] - match->y) + 1;
		stick->turn ++;
	}
	sfClock_restart(match->clock);
}
