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
	panel->sprite = NULL;
	panel->texture = NULL;
	panel->rect = sfRectangleShape_create();
	sfRectangleShape_setSize(panel->rect, size);
	sfRectangleShape_setPosition(panel->rect, pos);
	sfRectangleShape_setFillColor(panel->rect, fill);
	return (panel);
}

panel_t *create_image_panel(sfVector2f pos, char *img_path)
{
	panel_t *panel = NULL;
	sfTexture *txt = sfTexture_createFromFile(img_path, NULL);

	if (txt == NULL)
		return (NULL);
	panel = (panel_t*)malloc(sizeof(panel_t));
	if (panel == NULL) {
		sfTexture_destroy(txt);
		return (NULL);
	}
	panel->texture = txt;
	panel->sprite = sfSprite_create();
	sfSprite_setTexture(panel->sprite, txt, sfTrue);
	sfSprite_setPosition(panel->sprite, pos);
	panel->rect = NULL;
	return (panel);
}
