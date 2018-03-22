/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** disp map
*/

#include "../../include/my.h"
#include "../../include/map.h"
#include "../../include/linked_list.h"

int	disp_tile(sfRenderWindow *wd, map_t *map, tile_t *tile, sfVector2f px)
{
	sfSprite	*sprite = NULL;

	if (px.x <= -TILE_SIZE || px.x >= WIDTH)
		return (-1);
	if (px.y <= -TILE_SIZE || px.y >= HEIGHT)
		return (-1);
	sprite = get_tile_sprite(map, tile);
	sfSprite_setPosition(sprite, px);
	sfRenderWindow_drawSprite(wd, sprite, NULL);
	return (0);
}

int	disp_chunk(sfRenderWindow *wd, map_t *map, chunk_t *chk, pos_t ref)
{
	sfVector2f px_pos = {0.0, 0.0};

	for (int x = 0, y = 0; x <= TILES_PER_CHUNKS; x++) {
		if (x == TILES_PER_CHUNKS) {
			x = 0;
			y++;
		}
		if (y == TILES_PER_CHUNKS)
			break;
		px_pos = get_relative_pixel_pos(ref, chk, chk->tiles[y][x].pos);
		disp_tile(wd, map, &chk->tiles[y][x], px_pos);
	}
	return (0);
}

int	disp_map(sfRenderWindow *wd, map_t *map, pos_t ref)
{
	linked_list_t	*_chunks = get_nearest_chunks(map, ref);
	chunk_t		*chunk = NULL;

	for (; _chunks != NULL; _chunks = _chunks->next) {
		chunk = (chunk_t*)_chunks->data;
		disp_chunk(wd, map, (chunk_t*)_chunks->data, ref);
	}
	return (0);
}
