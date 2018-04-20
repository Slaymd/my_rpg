/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** chunk getter
*/

#include "../../include/rpg.h"

chunk_t *get_chunk_at(map_t *map, pos_t pos)
{
	list_t	*_chunks = map->chunks;
	chunk_t *chunk = NULL;

	for (; _chunks != NULL; _chunks = _chunks->next) {
		chunk = (chunk_t*)_chunks->data;
		if (chunk->pos.x != pos.x || chunk->pos.y != pos.y)
			continue;
		return (chunk);
	}
	chunk = chunk_gen(map, pos);
	list_add(&map->chunks, chunk);
	return (chunk);
}

list_t *get_nearest_chunks(map_t *map, pos_t pos)
{
	list_t	*nearest_chunks = NULL;
	pos_t		minpos = get_chunk_coords(pos);
	pos_t		maxpos = {minpos.x+DEFAULT_RENDER_DISTANCE,
		minpos.y+DEFAULT_RENDER_DISTANCE, 0};
	chunk_t		*chunk = NULL;

	for (float x = minpos.x, y = minpos.y; x <= maxpos.x; x++) {
		if (x == maxpos.x) {
			x = minpos.x;
			y++;
		}
		if (y == maxpos.y)
			break;
		chunk = get_chunk_at(map, (pos_t){x, y, 0});
		list_add(&nearest_chunks, chunk);
	}
	return (nearest_chunks);
}
