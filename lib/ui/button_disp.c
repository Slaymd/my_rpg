/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** button disp
*/

#include "uilib.h"
#include <SFML/Graphics.h>

void	disp_button(sfRenderWindow *wd, button_t *button)
{
	if (button == NULL)
		return;
	switch(button->type) {
	case FLAT:
		sfRenderWindow_drawRectangleShape(wd,button->rect,NULL);
		if (button->text != NULL)
			disp_text(wd, button->text);
		break;
	default:
		sfRenderWindow_drawSprite(wd, button->sprite, NULL);
		break;
	}
}

void	disp_buttons(sfRenderWindow *wd, list_t *buttons)
{
	list_t *tmp = buttons;

	for (; tmp != NULL; tmp = tmp->next)
		disp_button(wd, (button_t*)tmp->data);
}
