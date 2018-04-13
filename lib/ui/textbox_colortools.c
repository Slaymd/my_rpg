/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** __DESCRIPTION__
*/

#include "uilib.h"

void	set_textbox_color(textbox_t *textbox, sfColor fill, sfColor outl)
{
	if (textbox == NULL)
		return;
	sfRectangleShape_setFillColor(textbox->rect, fill);
	sfRectangleShape_setOutlineColor(textbox->rect, outl);
}

void	set_textbox_outline_thickness(textbox_t *textbox, int thick)
{
	if (textbox == NULL)
		return;
	sfRectangleShape_setOutlineThickness(textbox->rect, thick);
}

sfColor get_textbox_fill_color(textbox_t *textbox)
{
	if (textbox == NULL)
		return ((sfColor){0, 0, 0, 0});
	return (sfRectangleShape_getFillColor(textbox->rect));
}

sfColor get_textbox_outline_color(textbox_t *textbox)
{
	if (textbox == NULL)
		return ((sfColor){0, 0, 0, 0});
	return (sfRectangleShape_getOutlineColor(textbox->rect));
}
