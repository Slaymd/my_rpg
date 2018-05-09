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

void free_ms(ms_t *ms)
{
	sfTexture_destroy(ms->match->tmatch);
	sfSprite_destroy(ms->match->smatch);
	sfSprite_destroy(ms->match->sred_match);
	sfTexture_destroy(ms->match->tarrow);
	sfSprite_destroy(ms->match->sarrow);
	sfClock_destroy(ms->match->clock);
	free(ms->match);
	free(ms->stick->line);
	free(ms->stick);
	free(ms);

}

int my_end(stick_t *stick)
{
	for (int i = 0; i < stick->lines; i++) {
		if (stick->line[i] > 0)
			return (0);
	}
	return (1);
}
