/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** textures
*/

#include "../../include/my.h"
#include "../../include/map.h"
#include "../../include/linked_list.h"
#include "../../include/assets.h"

linked_list_t	*init_textures(void)
{
	linked_list_t	*textures = NULL;
	texture_t		*grass = (texture_t*)malloc(sizeof(texture_t));
	sfTexture *txt = sfTexture_createFromFile(TXTRE_GRASS, NULL);

	grass->id = 1;
	grass->shape = sfRectangleShape_create();
	sfRectangleShape_setFillColor(grass->shape, sfGreen);
	sfRectangleShape_setSize(grass->shape, (sfVector2f){64, 64});
	grass->sprite = sfSprite_create();
	sfSprite_setTexture(grass->sprite, txt, sfTrue);
	add_to_linked_list(&textures, grass);
	return (textures);
}
