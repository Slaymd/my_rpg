/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** image tools
*/

#include "uilib.h"

void set_panel_image_rect(panel_t *panel, sfIntRect rect)
{
	if (panel == NULL || panel->sprite == NULL)
		return;
	sfSprite_setTextureRect(panel->sprite, rect);
}

void set_panel_image(panel_t *panel, char *img_path)
{
	if (panel == NULL || panel->sprite == NULL)
		return;
	if (panel->texture != NULL)
		sfTexture_destroy(panel->texture);
	panel->texture = sfTexture_createFromFile(img_path, NULL);
	sfSprite_setTexture(panel->sprite, panel->texture, sfFalse);
}

void set_panel_image_scale(panel_t *panel, float multiplier)
{
	if (panel == NULL || panel->sprite == NULL)
		return;
	sfSprite_setScale(panel->sprite, (sfVector2f){multiplier,\
	multiplier});
}
