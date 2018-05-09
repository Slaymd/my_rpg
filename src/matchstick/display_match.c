/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** tile
*/

#include "rpg.h"

void draw_match(rpg_t *rpg, match_t *match, stick_t *stick, sfVector2f pos)
{
	pos.x = (WIDTH / 2 - (36 * match->scale + 100 * match->scale) *
	stick->len / 2) - (match->x + 1) * ((100 + 36) * match->scale);
	pos.y = 55 + match->x * ((100 + 436) * match->scale);
	sfSprite_setPosition(match->sarrow, pos);
	sfRenderWindow_drawSprite(rpg->wd, match->sarrow, NULL);
}

void calcul_match(rpg_t *rpg, match_t *match, stick_t *stick)
{
	sfVector2f pos;

	for (int h = 0, i = 0; h < stick->lines; h++, i = 0) {
		for (int j = 0; j < stick->lines - (h + 1); j++, i++);
		for (int j = 0; j < stick->line[h]; j++, i++) {
			pos.x = (WIDTH / 2 - (36 * match->scale + 100 *
			match->scale) * stick->len / 2) + i * ((100 + 36)
			*match->scale);
			pos.y = 55 + h * ((100 + 436) * match->scale);
			sfSprite_setPosition(match->smatch, pos);
			sfSprite_setPosition(match->sred_match, pos);
			(match->x == h && match->y - 1 <= j) ?
			sfRenderWindow_drawSprite(rpg->wd,
			match->sred_match, NULL) :
			sfRenderWindow_drawSprite(rpg->wd,
			match->smatch, NULL);
		}
	}
	draw_match(rpg, match, stick, pos);
}
