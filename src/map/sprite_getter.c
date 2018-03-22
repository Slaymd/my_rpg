/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** sprite getter
*/

#include "../../include/my.h"
#include "../../include/map.h"
#include "../../include/linked_list.h"
#include "../../include/assets.h"

sfSprite	*get_tile_sprite(map_t *map, tile_t *tile)
{
	linked_list_t	*_textures = map->textures;
	texture_t		*txtre = NULL;
	sfSprite		*sprite = NULL;
	int			tex_id = tile->texture_id;

	while (_textures != NULL) {
		txtre = (texture_t*)_textures->data;
		if (txtre->id == tex_id && tile->sprite == NULL) {
			sprite = sfSprite_copy(txtre->sprite);
			tile->sprite = sprite;
		} else if (txtre->id == tex_id && tile->sprite != NULL)
			break;
		_textures = _textures->next;
	}
	return (tile->sprite);
}
