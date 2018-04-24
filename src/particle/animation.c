/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** create
*/

#include "rpg.h"

void radian_gradiant(particle_t *particle, sfVector2i pos, int refresh)
{
	static sfColor color = (sfColor){255, 255, 255, 0};

	if (refresh == 1) {
		if (pos.x > particle->x / 2)
			color.a += (float)(pos.x) / (float)particle->x * 2 * 127.5 * -1;
		else
			color.a += (float)(pos.x) / (float)particle->x * 2 * 127.5;
		if (pos.y > particle->y / 2)
			color.a += (float)(pos.y) / (float)particle->y * 2 * 127.5 * -1;
		else
			color.a += (float)(pos.y) / (float)particle->y * 2 * 127.5;
		if (rand() % 2 == 0)
			color.a = 0;
		put_pixel(particle, pos.x, pos.y, color);
	}
}
