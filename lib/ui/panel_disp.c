/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** panel disp
*/

#include "uilib.h"

void	disp_panel(sfRenderWindow *wd, panel_t *panel)
{
	if (panel == NULL)
		return;
	if (panel->rect != NULL)
		sfRenderWindow_drawRectangleShape(wd, panel->rect, NULL);
}

void	disp_panels(sfRenderWindow *wd, list_t *panels)
{
	list_t *tmp = panels;

	for (; tmp != NULL; tmp = tmp->next)
		disp_panel(wd, (panel_t*)tmp->data);
}
