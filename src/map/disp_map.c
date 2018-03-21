/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** disp map
*/

#include "../../include/my.h"
#include "../../include/map.h"
#include "../../include/linked_list.h"

int	disp_tile(sfRenderWindow *wd, map_t *map, pos_t cpos, tile_t *tile)
{
	int	wd_x = cpos.x*(64*16)+tile->pos.x*64;
	int	wd_y = cpos.y*(64*16)+tile->pos.y*64;
	sfSprite	*sprite = NULL;

	if (wd_x <= -64 || wd_x >= WIDTH || wd_y <= -64 || wd_y >= HEIGHT)
		return (84);
	sprite = get_tile_sprite(map, tile);
	sfSprite_setPosition(sprite, (sfVector2f){wd_x, wd_y});
	sfRenderWindow_drawSprite(wd, sprite, NULL);
	return (0);
}

int	disp_chunk(sfRenderWindow *wd, map_t *map, chunk_t *chunk)
{
	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {
			disp_tile(wd, map, chunk->pos, &chunk->tiles[y][x]);
		}
	}
	return (0);
}

int	disp_map(sfRenderWindow *wd, map_t *map)
{
	linked_list_t *_chunks = map->chunks;

	for (; _chunks != NULL; _chunks = _chunks->next) {
		disp_chunk(wd, map, (chunk_t*)_chunks->data);
	}
	return (0);
}
