/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** create
*/

#include "rpg.h"

void radial_gradiant(particle_t *particle, sfVector2i pos, int refresh)
{
	static sfColor color;
	sfVector2f og;
	float d;
	float a;

	if (refresh == 1) {
		color = sfWhite;
		if (rand() % 2 == 1)
			color = sfBlack;
		og = (V2F){particle->x * 0.5, particle->y * 0.5};
		d = sqrt(pow((og.x - pos.x), 2) + pow((og.y - pos.y), 2));
		a = ((d / (particle->x / 2)) * 255 - 255) / 2 * -1;
		color.a = (a >= 0 && a <= 255) ? a : 0;
		put_pixel(particle, pos.x, pos.y, color);
	}
}
