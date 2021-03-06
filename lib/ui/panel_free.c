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
	if (panel->sprite != NULL) {
		sfTexture_destroy(panel->texture);
		sfSprite_destroy(panel->sprite);
	}
	free(panel);
}
