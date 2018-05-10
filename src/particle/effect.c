/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** effect
*/

#include "rpg.h"

effect_tab_t const effect_tab[] = {{NONE, no_effect},
	{RADIAL, radial_gradiant}};

void no_effect(particle_t *particle, sfVector2i pos, int refresh, sfColor color)
{
	if (refresh == 1)
		put_pixel(particle, pos.x, pos.y, color);
}

void radial_gradiant(particle_t *particle, sfVector2i pos, int refresh, sfColor color)
{
	sfVector2f og;
	float d;
	float a;

	if (refresh == 1) {
		if (rand() % 2 == 1)
			color.a = 0;
		if (color.a == 0) {
			put_pixel(particle, pos.x, pos.y, color);
			return;
		}
		og = (V2F){particle->x * 0.5, particle->y * 0.5};
		d = sqrt(pow((og.x - pos.x), 2) + pow((og.y - pos.y), 2));
		a = ((d / (particle->x / 2)) * 255 - 255) * -1;
		color.a = (a >= 0 && a <= 255) ? a : 0;
		put_pixel(particle, pos.x, pos.y, color);
	}
}

void select_effect(particle_t *particle, sfVector2i pos, int refresh, sfColor color)
{
	int i = 0;

	while (i < NB_EFFECT) {
		if (particle->effect == effect_tab[i].effect) {
			effect_tab[i].func(particle, pos, refresh, color);
			return;
		}
		i++;
	}
}
