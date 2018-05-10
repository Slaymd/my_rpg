/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** free textures
*/

#include "../../../include/rpg.h"

void free_texture(texture_t *txt)
{
	if (txt->shape != NULL)
		sfRectangleShape_destroy(txt->shape);
	if (txt->sprite != NULL)
		sfSprite_destroy(txt->sprite);
	free(txt->texture_path);
	free(txt);
}

void free_textures(map_t *map)
{
	list_t *tmp = NULL;
	texture_t *txt = NULL;

	for (; map->textures != NULL; map->textures = tmp) {
		tmp = map->textures->next;
		txt = (texture_t*)map->textures->data;
		free_texture(txt);
		free(map->textures);
	}
}
