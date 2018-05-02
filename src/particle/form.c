/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** form
*/

#include "rpg.h"

form_tab_t const form_tab[] = {{CIRCLE, display_circle},
	{SQUARE, display_square}, {TRIANGLE, display_triangle}};

void display_square(particle_t *particle, int refresh)
{
	sfVector2i pos = {0, 0};

	while (pos.x != particle->x || pos.y!= particle->y) {
		select_effect(particle, pos, refresh, particle->color);
		pos.x += 1;
		if (pos.x > particle->x / 2 + particle->x / 2) {
			pos.x = 0;
			pos.y += 1;
		}
	}
}

void display_circle(particle_t *p, int refresh)
{
	sfVector2i pos = {0, 0};

	while (pos.x != p->x || pos.y != p->y) {
		if ((((pos.x - p->x / 2) * (pos.x - p->x / 2)) + ((pos.y - p->y
		/ 2) * (pos.y - p->y / 2))) <= (p->x / 2 * p->y / 2))
			select_effect(p, pos, refresh, p->color);
		pos.x += 1;
		if (pos.x > p->x / 2 + p->x / 2) {
			pos.x = 0;
			pos.y += 1;
		}
	}
}

void display_triangle(particle_t *particle, int refresh)
{
	V2I pos;
	sfColor color = (sfColor){0, 0, 0, 0};
	int x = particle->x / 2;
	int y = particle->y;

	display_square(particle, refresh);
	for (float i = 0; i < x; i++) {
		for (float j = 0; j < y - ((i / x) * y); j++) {
			pos = (V2I){(int)i, (int)j};
			select_effect(particle, pos, refresh, color);
		}
	}
	for (float i = x; i < particle->x; i++) {
		for (float j = 0; j < (i - x) * 2; j++) {
			pos = (V2I){(int)i, (int)j};
			select_effect(particle, pos, refresh, color);
		}
	}
}

void select_form(particle_t *particle, int refresh)
{
	int i = 0;

	while (i < NB_FORM) {
		if (particle->form == form_tab[i].form) {
			form_tab[i].func(particle, refresh);
			return;
		}
		i++;
	}
}
