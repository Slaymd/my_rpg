/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** tile getter
*/

#include "../../include/rpg.h"

tile_t *get_tile_at(map_t *map, pos_t pos)
{
	pos_t cpos = get_chunk_coords(pos);
	pos_t cpos_absol = {cpos.x*TILES_PER_CHUNKS,cpos.y*TILES_PER_CHUNKS,0};
	chunk_t *chk = NULL;
	list_t *tmp = map->chunks;

	for (; tmp != NULL; tmp = tmp->next) {
		chk = (chunk_t*)tmp->data;
		if (chk->pos.x != cpos.x || chk->pos.y != cpos.y)
			continue;
		return (&chk->tiles[(int)(pos.y-cpos_absol.y)]
		[(int)(pos.x-cpos_absol.x)]);
	}
	return (NULL);
}
