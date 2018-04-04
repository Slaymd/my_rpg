/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** textures
*/

#include "../../include/rpg.h"

texture_t *init_texture(int id, char *path, sfColor color)
{
	texture_t	*texture = (texture_t*)malloc(sizeof(texture_t));
	sfTexture	*txt = sfTexture_createFromFile(path, NULL);
	sfVector2f tilesize = (sfVector2f){TILE_SIZE, TILE_SIZE};
	sfVector2u txtsize = {0, 0};

	texture->id = id;
	texture->sprite = sfSprite_create();
	sfSprite_setTexture(texture->sprite, txt, sfTrue);
	texture->shape = sfRectangleShape_create();
	sfRectangleShape_setFillColor(texture->shape, color);
	sfRectangleShape_setSize(texture->shape, tilesize);
	txtsize = sfTexture_getSize(txt);
	sfSprite_setScale(texture->sprite, (sfVector2f){tilesize.x/txtsize.x,
	tilesize.y/txtsize.y});
	return (texture);
}

list_t	*init_textures(void)
{
	list_t	*txts = NULL;

	list_add(&txts, init_texture(1, TXTRE_DEEP_WATER, sfBlue));
	list_add(&txts, init_texture(2, TXTRE_WATER, sfBlue));
	list_add(&txts, init_texture(3, TXTRE_SAND, sfYellow));
	list_add(&txts, init_texture(4, TXTRE_GRASS, sfGreen));
	list_add(&txts, init_texture(5, TXTRE_LIGHT_STONE, sfWhite));
	return (txts);
}
