/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** button disp
*/

#include "my_uilib.h"
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

void	disp_buttons(sfRenderWindow *wd, button_t *buttons, int nb)
{
	for (int i = 0; buttons != NULL && i < nb; i++) {
		disp_button(wd, &buttons[i]);
	}
}
