/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** button free
*/

#include "my_uilib.h"

void	free_button(button_t *button)
{
	if (button == NULL)
		return;
	if (button->text != NULL)
		free_text(button->text);
	if (button->rect != NULL)
		sfRectangleShape_destroy(button->rect);
	if (button->sprite != NULL)
		sfSprite_destroy(button->sprite);
	free(button);
}
