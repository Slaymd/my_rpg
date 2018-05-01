/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** create
*/

#include "rpg.h"

particle_t *create_particle(sfVector2i size, sfColor color, form_type_t form, effect_type_t effect)
{
	particle_t *particle = malloc(sizeof(particle_t));
	sfUint8 *pixels = malloc(sizeof(sfUint8) * size.x * size.y * 4);

	for (int i = 0; i < size.x * size.y * 4; i++)
		pixels[i] = 0;
	particle->texture = sfTexture_create(size.x, size.y);
	particle->sprite = sfSprite_create();
	particle->x = size.x;
	particle->y = size.y;
	particle->pixels = pixels;
	particle->color = color;
	particle->form = form;
	particle->effect = effect;
	sfSprite_setTexture(particle->sprite, particle->texture, sfTrue);
	sfSprite_setOrigin(particle->sprite, (V2F){size.x / 2, size.y / 2});
	return (particle);
}

void put_pixel(particle_t *particle, int x, int y, sfColor color)
{
	int position = (y * particle->x + x) * 4;

	if (position >= 0 && position + 3 <= particle->x * particle->y * 4 &&
	x <= particle->x && y <= particle->y) {
		particle->pixels[position + 0] = color.r;
		particle->pixels[position + 1] = color.g;
		particle->pixels[position + 2] = color.b;
		particle->pixels[position + 3] = color.a;
	}
}

void display_particle(particle_t *particle, sfRenderWindow *window, V2F pos, int refresh)
{
	select_form(particle, refresh);
	sfTexture_updateFromPixels(particle->texture, particle->pixels,
	particle->x, particle->y, 0, 0);
	sfSprite_setPosition(particle->sprite, pos);
	sfRenderWindow_drawSprite(window, particle->sprite, NULL);
}

void destroy_particle(particle_t *particle)
{
	sfSprite_destroy(particle->sprite);
	sfTexture_destroy(particle->texture);
	free(particle->pixels);
	free(particle);
}
