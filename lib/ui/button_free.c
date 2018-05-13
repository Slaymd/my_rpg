/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** button free
*/

#include "uilib.h"

void	free_button(button_t *button)
{
	if (button == NULL)
		return;
	(button->text != NULL) ? free_text(button->text) : 0;
	(button->rect != NULL) ? sfRectangleShape_destroy(button->rect) : 0;
	(button->sprite != NULL) ? sfSprite_destroy(button->sprite) : 0;
	free(button);
}
