/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** panel init
*/

#include "uilib.h"

panel_t *create_flat_panel(sfVector2f pos, sfVector2f size, sfColor fill)
{
	panel_t *panel = (panel_t*)malloc(sizeof(panel_t));

	if (panel == NULL)
		return (NULL);
	panel->rect = sfRectangleShape_create();
	sfRectangleShape_setSize(panel->rect, size);
	sfRectangleShape_setPosition(panel->rect, pos);
	sfRectangleShape_setFillColor(panel->rect, fill);
	return (panel);
}
