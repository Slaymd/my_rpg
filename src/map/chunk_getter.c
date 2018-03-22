/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** chunk getter
*/

#include "../../include/my.h"
#include "../../include/map.h"
#include "../../include/linked_list.h"

linked_list_t *get_nearest_chunks(map_t *map, pos_t pos)
{
	linked_list_t	*_chunks = map->chunks;
	linked_list_t	*nearest_chunks = NULL;
	pos_t		min_cpos = get_chunk_coords(pos);
	pos_t		max_cpos = {min_cpos.x+1, min_cpos.y+1, 0};
	chunk_t		*chunk = NULL;

	for (; _chunks != NULL; _chunks = _chunks->next) {
		chunk = (chunk_t*)_chunks->data;
		if (chunk->pos.x < min_cpos.x || chunk->pos.x > max_cpos.x)
			continue;
		if (chunk->pos.y < min_cpos.y || chunk->pos.y > max_cpos.y)
			continue;
		add_to_linked_list(&nearest_chunks, chunk);
	}
	return (nearest_chunks);
}
