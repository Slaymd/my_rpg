/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** panel color tools
*/

#include "uilib.h"

void set_panel_opacity(panel_t *panel, float opacity)
{
	sfColor color = {0, 0, 0, 0};

	if (panel == NULL)
		return;
	color = sfRectangleShape_getFillColor(panel->rect);
	color.a = opacity*255;
	sfRectangleShape_setFillColor(panel->rect, color);
}
