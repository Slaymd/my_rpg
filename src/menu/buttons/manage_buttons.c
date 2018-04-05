/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** button
*/

#include "rpg.h"

int button_is_clicked(button_t *button, sfVector2i click)
{
	if (click.x < sfRectangleShape_getPosition(button->rect).x +\
	sfRectangleShape_getSize(button->rect).x &&\
	click.x > sfRectangleShape_getPosition(button->rect).x &&\
	click.y < sfRectangleShape_getPosition(button->rect).y +\
	sfRectangleShape_getSize(button->rect).y &&\
	click.y > sfRectangleShape_getPosition(button->rect).y)
		return (1);
	return (0);
}

void manage_buttons(rpg_t *rpg)
{
	sfVector2i p = sfMouse_getPositionRenderWindow(rpg->window->window);

	for (int i = 0; rpg->menu->scene[rpg->menu->state]->button[i]; i++) {
		if (button_is_clicked(rpg->menu->scene[rpg->menu->state]->button[i], p) == 1) {
			(rpg->window->event.type == sfEvtMouseButtonPressed) ?
			rpg->menu->scene[rpg->menu->state]->button[i]->callback(rpg) : 0;
		}
	}
}
