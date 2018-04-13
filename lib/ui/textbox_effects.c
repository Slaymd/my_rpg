/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** button effets
*/

#include "my_uilib.h"

int	set_textbox_hover_design(textbox_t *textbox)
{
	sfColor fillhover = (sfColor){0, 0, 0, 0};
	sfColor outlhover = (sfColor){0, 0, 0, 0};

	if (textbox == NULL)
		return (0);
	fillhover = get_textbox_fill_color(textbox);
	outlhover = get_textbox_outline_color(textbox);
	outlhover.a = 180;
	set_textbox_color(textbox, fillhover, outlhover);
	return (1);
}

int	rem_textbox_hover_design(textbox_t *textbox)
{
	sfColor fill = (sfColor){0, 0, 0, 0};
	sfColor outl = (sfColor){0, 0, 0, 0};

	if (textbox == NULL)
		return (0);
	fill = get_textbox_fill_color(textbox);
	outl = get_textbox_outline_color(textbox);
	outl.a = 255;
	set_textbox_color(textbox, fill, outl);
	return (1);
}
