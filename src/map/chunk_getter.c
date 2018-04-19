/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** chunk getter
*/

#include "../../include/rpg.h"

tile_t *get_tile_at(map_t *map, pos_t pos)
{
	pos_t cpos = get_chunk_coords(pos);
	pos_t cpos_absol = {cpos.x*TILES_PER_CHUNKS, cpos.y*TILES_PER_CHUNKS};
	chunk_t *chk = NULL;
	list_t *tmp = map->chunks;

	printf("CHUNKPOS       (%f, %f)\n", cpos.x, cpos.y);
	printf("CHUNKPOS ABSOL (%f, %f)\n", cpos_absol.x, cpos_absol.y);
	printf(" TILEPOS       (%f, %f)\n", pos.x-cpos.x, pos.y-cpos.y);
	for (; tmp != NULL; tmp = tmp->next) {
		chk = (chunk_t*)tmp->data;
		if (chk->pos.x != cpos.x || chk->pos.y != cpos.y)
			continue;
		return (&chk->tiles[(int)(pos.y-cpos_absol.y)][(int)(pos.x-cpos_absol.x)]);
	}
	return (NULL);
}

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
