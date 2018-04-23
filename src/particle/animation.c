/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** create
*/

#include "rpg.h"

void radian_gradiant(particle_t *particle, sfVector2i pos)
{
	sfColor color = (sfColor){255, 255, 255, 0};

	if (pos.x > particle->x / 2)
		color.a += (float)(pos.x) / (float)particle->x * 2 * 127.5 * -1;
	else
		color.a += (float)(pos.x) / (float)particle->x * 2 * 127.5;
	if (pos.y > particle->y / 2)
		color.a += (float)(pos.y) / (float)particle->y * 2 * 127.5 * -1;
	else
		color.a += (float)(pos.y) / (float)particle->y * 2 * 127.5;
	put_pixel(particle, pos.x, pos.y, color);
}
