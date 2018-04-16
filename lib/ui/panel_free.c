/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** panel free
*/

#include "uilib.h"

void free_panel(panel_t *panel)
{
	if (panel == NULL)
		return;
	if (panel->rect != NULL)
		sfRectangleShape_destroy(panel->rect);
	free(panel);
}
