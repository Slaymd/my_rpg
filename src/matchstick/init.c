/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** tile
*/

#include "rpg.h"

stick_t *fill_stick(void)
{
	stick_t *stick = malloc(sizeof(stick_t));
	int len = 0;

	if (!stick)
		return (NULL);
	stick->lines = 4;
	stick->len = stick->lines * 2 - 1;
	stick->max = 3;
	stick->turn = 0;
	for (; len < stick->lines; len++);
	stick->line = malloc(sizeof(int) * len);
	for (int i = 0; i < stick->lines; i++)
		stick->line[i] = 1 + i * 2;
	return (stick);
}

void second_init_match(match_t *match)
{
	sfSprite_setScale(match->smatch,
	(sfVector2f){match->scale, match->scale});
	sfSprite_setTexture(match->smatch, match->tmatch, sfTrue);
	match->sred_match = sfSprite_create();
	sfSprite_setScale(match->sred_match,
	(sfVector2f){match->scale, match->scale});
	sfSprite_setTexture(match->sred_match, match->tmatch, sfTrue);
	sfSprite_setColor(match->sred_match, sfRed);
	sfSprite_setScale(match->sarrow,
	(sfVector2f){match->scale, match->scale});
	sfSprite_setTexture(match->sarrow, match->tarrow, sfTrue);
}

match_t *init_match(void)
{
	match_t *match = malloc(sizeof(match_t));

	match->scale = 0.24;
	match->tmatch = sfTexture_createFromFile("./img/match.png", NULL);
	match->smatch = sfSprite_create();
	match->mode = 1;
	match->x = 0;
	match->y = 2;
	match->tarrow = sfTexture_createFromFile("./img/marrow.png", NULL);
	match->sarrow = sfSprite_create();
	match->clock = sfClock_create();
	match->time = sfClock_getElapsedTime(match->clock);
	match->seconds = 0;
	second_init_match(match);
	return (match);
}
