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
	sfColor trans = (sfColor){255, 255, 255, 255};
	sfColor full = (sfColor){255, 255, 255, 170};
	int state = rpg->menu->state;

	for (int i = 0; rpg->menu->scene[state]->button[i]; i++) {
		sfSprite_setColor(rpg->menu->scene[state]->button[i]->sprite, full);
		if (button_is_clicked(rpg->menu->scene[state]->button[i], p) == 1) {
			sfSprite_setColor(rpg->menu->scene[state]->button[i]->sprite, trans);
			(rpg->window->event.type == sfEvtMouseButtonPressed) ?
			rpg->menu->scene[state]->button[i]->callback(rpg) : 0;
		}
	}
}
