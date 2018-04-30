/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** form
*/

#include "rpg.h"

form_tab_t const form_tab[] = {{CIRCLE, display_circle},
	{SQUARE, display_square}};

void display_circle(particle_t *p, int refresh)
{
	sfVector2i pos = {p->x / 2 - p->x / 2, p->y / 2 - p->y / 2};

	while (pos.x != p->x / 2 + p->x / 2 || pos.y != p->y / 2 + p->y / 2) {
		if ((((pos.x - p->x / 2) * (pos.x - p->x / 2)) + ((pos.y - p->y
		/ 2) * (pos.y - p->y / 2))) <= (p->x / 2 * p->y / 2))
			select_effect(p, pos, refresh);
		pos.x += 1;
		if (pos.x > p->x / 2 + p->x / 2) {
			pos.x = 0;
			pos.y += 1;
		}
	}
}

void display_square(particle_t *p, int refresh)
{
	sfVector2i pos = {p->x / 2 - p->x / 2, p->y / 2 - p->y / 2};

	while (pos.x != p->x / 2 + p->x / 2 || pos.y != p->y / 2 + p->y / 2) {
		select_effect(p, pos, refresh);
		pos.x += 1;
		if (pos.x > p->x / 2 + p->x / 2) {
			pos.x = 0;
			pos.y += 1;
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
