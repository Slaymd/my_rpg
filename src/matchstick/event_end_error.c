/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** tile
*/

#include "rpg.h"

void matchstick_gestion(rpg_t *rpg, match_t *match)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(rpg->wd, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(rpg->wd);
	}
	match->time = sfClock_getElapsedTime(match->clock);
	match->seconds = match->time.microseconds / 1000000.0;
	sfRenderWindow_clear(rpg->wd, sfWhite);
}

void free_match(match_t *match, stick_t *stick)
{
	sfTexture_destroy(match->tmatch);
	sfSprite_destroy(match->smatch);
	sfTexture_destroy(match->tarrow);
	sfSprite_destroy(match->sarrow);
	sfClock_destroy(match->clock);
	free(match);
	free(stick->line);
	free(stick);
}

int my_end(stick_t *stick)
{
	for (int i = 0; i < stick->lines; i++) {
		if (stick->line[i] > 0)
			return (0);
	}
	return (1);
}
