/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** button effets
*/

#include "uilib.h"

int	set_button_hover_design(button_t *button)
{
	sfColor fillhover = (sfColor){0, 0, 0, 0};
	sfColor outlhover = (sfColor){0, 0, 0, 0};

	if (button == NULL || button->type != FLAT)
		return (0);
	fillhover = get_button_fill_color(button);
	fillhover.a = 180;
	outlhover = get_button_outline_color(button);
	outlhover.a = 180;
	set_button_color(button, fillhover, outlhover);
	if (button->tooltip != NULL)
		button->tooltip->state = 1;
	return (1);
}

int	rem_button_hover_design(button_t *button)
{
	sfColor fill = (sfColor){0, 0, 0, 0};
	sfColor outl = (sfColor){0, 0, 0, 0};

	if (button == NULL || button->type != FLAT)
		return (0);
	fill = get_button_fill_color(button);
	fill.a = 255;
	outl = get_button_outline_color(button);
	outl.a = 255;
	set_button_color(button, fill, outl);
	if (button->tooltip != NULL && button->tooltip->state == 1)
		button->tooltip->state = 2;
	return (1);
}
