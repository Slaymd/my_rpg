/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** button position tools
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_uilib.h"

void set_textbox_position(textbox_t *textbox, sfVector2f pos)
{
	if (textbox == NULL)
		return;
	sfRectangleShape_setPosition(textbox->rect, pos);
}

void set_textbox_size(textbox_t *textbox, sfVector2f size)
{
	sfVector2f pos = (sfVector2f){0, 0};

	if (textbox == NULL)
		return;
	sfRectangleShape_setSize(textbox->rect, size);
}

sfVector2f get_textbox_position(textbox_t *textbox)
{
	sfVector2f pos = (sfVector2f){0, 0};

	if (textbox == NULL)
		return (pos);
	pos = sfRectangleShape_getPosition(textbox->rect);
	return (pos);
}

sfVector2f get_textbox_size(textbox_t *textbox)
{
	sfVector2f size = (sfVector2f){0, 0};

	if (textbox == NULL)
		return (size);
	size = sfRectangleShape_getSize(textbox->rect);
	return (size);
}
