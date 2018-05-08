/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** tile
*/

#include "rpg.h"

void match_ai(stick_t *stick, match_t *match)
{
	int max = stick->max;

	srand(time(NULL));
	match->x = (rand() % stick->lines - 1) + 1;
	for (; stick->line[match->x] <= 0;)
		match->x = (rand() % stick->lines - 1) + 1;
	if (stick->line[match->x] < stick->max)
		max = stick->line[match->x];
	match->y = (rand() % max) + 1;
}

void ai_play(match_t *match, stick_t *stick)
{
	match_ai(stick, match);
	stick->line[match->x] -= match->y;
	match->y = stick->line[match->x] + 1;
	stick->turn ++;
	sfClock_restart(match->clock);
}
