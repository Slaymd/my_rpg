/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** __DESCRIPTION__
*/

#include "uilib.h"

void	set_button_color(button_t *button, sfColor fill, sfColor outl)
{
	if (button == NULL || button->type != FLAT || button->rect == NULL)
		return;
	if (!(fill.r == 0 && fill.g == 0 && fill.b == 0 && fill.a == 0))
		sfRectangleShape_setFillColor(button->rect, fill);
	if (!(outl.r == 0 && outl.g == 0 && outl.b == 0 && outl.a == 0))
		sfRectangleShape_setOutlineColor(button->rect, outl);
}

void	set_button_outline_thickness(button_t *button, int thickness)
{
	if (button == NULL || button->type != FLAT)
		return;
	sfRectangleShape_setOutlineThickness(button->rect, thickness);
}

sfColor get_button_fill_color(button_t *button)
{
	if (button == NULL || button->type != FLAT)
		return ((sfColor){0, 0, 0, 0});
	return (sfRectangleShape_getFillColor(button->rect));
}

sfColor get_button_outline_color(button_t *button)
{
	if (button == NULL || button->type != FLAT)
		return ((sfColor){0, 0, 0, 0});
	return (sfRectangleShape_getOutlineColor(button->rect));
}
