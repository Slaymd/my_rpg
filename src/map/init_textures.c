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

texture_t *init_texture(int id, char *path, sfColor color)
{
	texture_t	*texture = (texture_t*)malloc(sizeof(texture_t));
	sfTexture	*txt = sfTexture_createFromFile(path, NULL);
	sfVector2f tilesize = (sfVector2f){TILE_SIZE, TILE_SIZE};

	texture->id = id;
	texture->sprite = sfSprite_create();
	sfSprite_setTexture(texture->sprite, txt, sfTrue);
	texture->shape = sfRectangleShape_create();
	sfRectangleShape_setFillColor(texture->shape, color);
	sfRectangleShape_setSize(texture->shape, tilesize);
	return (texture);
}

linked_list_t	*init_textures(void)
{
	linked_list_t	*txts = NULL;

	add_to_linked_list(&txts, init_texture(1, TXTRE_DEEP_WATER, sfBlue));
	add_to_linked_list(&txts, init_texture(2, TXTRE_WATER, sfBlue));
	add_to_linked_list(&txts, init_texture(3, TXTRE_SAND, sfYellow));
	add_to_linked_list(&txts, init_texture(4, TXTRE_GRASS, sfGreen));
	add_to_linked_list(&txts, init_texture(5, TXTRE_LIGHT_STONE, sfWhite));
	return (txts);
}
