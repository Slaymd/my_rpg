/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** create
*/

#include "rpg.h"

particle_t *create_particle(int x, int y)
{
	particle_t *particle = malloc(sizeof(particle_t));
	sfUint8 *pixels = malloc(sizeof(sfUint8) * x * y * 4);

	for (int i = 0; i < x * y * 4; i++)
		pixels[i] = (i + 1 % 4 == 0) ? 255 : 0;
	particle->texture = sfTexture_create(x, y);
	particle->sprite = sfSprite_create();
	particle->x = x;
	particle->y = y;
	particle->color = sfWhite;
	particle->pixels = pixels;
	sfSprite_setTexture(particle->sprite, particle->texture, sfTrue);
	sfSprite_setOrigin(particle->sprite, (V2F){x / 2, y / 2});
	return (particle);
}

void put_pixel(particle_t *particle, int x, int y, sfColor color)
{
	int position = (y * particle->x + x) * 4;

	if (position >= 0 && position <= particle->x * particle->y * 4 &&
	x <= particle->x && y <= particle->y) {
		particle->pixels[position + 0] = color.r;
		particle->pixels[position + 1] = color.g;
		particle->pixels[position + 2] = color.b;
		particle->pixels[position + 3] = color.a;
	}
}

void display_circle(particle_t *p, int refresh)
{
	sfVector2i pos = {p->x / 2 - p->x / 2, p->y / 2 - p->y / 2};

	while (pos.x != p->x / 2 + p->x / 2 || pos.y != p->y / 2 + p->y / 2) {
		if ((((pos.x - p->x / 2) * (pos.x - p->x / 2)) + ((pos.y - p->y
		/ 2) * (pos.y - p->y / 2))) <= (p->x / 2 * p->y / 2))
			radian_gradiant(p, pos, refresh);
		pos.x += 1;
		if (pos.x > p->x / 2 + p->x / 2) {
			pos.x = 0;
			pos.y += 1;
		}
	}
}

void display_particle(particle_t *particle, sfRenderWindow *window, V2F pos, int refresh)
{
	display_circle(particle, refresh);
	sfTexture_updateFromPixels(particle->texture, particle->pixels,
	particle->x, particle->y, 0, 0);
	sfSprite_setPosition(particle->sprite, pos);
	sfRenderWindow_drawSprite(window, particle->sprite, NULL);
}

void destroy_particle(particle_t *particle)
{
	free(particle->pixels);
	free(particle);
}
