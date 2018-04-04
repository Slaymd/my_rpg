/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** sprite getter
*/

#include "../../include/rpg.h"

sfSprite	*get_tile_sprite(map_t *map, tile_t *tile)
{
	list_t	*_textures = map->textures;
	texture_t		*txtre = NULL;
	sfSprite		*sprite = NULL;
	int			tex_id = tile->texture_id;

	while (_textures != NULL) {
		txtre = (texture_t*)_textures->data;
		//my_printf("TXT GET: %d\n", txtre->id);
		if (txtre->id == tex_id && tile->sprite == NULL) {
			sprite = sfSprite_copy(txtre->sprite);
			tile->sprite = sprite;
		} else if (txtre->id == tex_id && tile->sprite != NULL)
			break;
		_textures = _textures->next;
	}
	return (tile->sprite);
}
