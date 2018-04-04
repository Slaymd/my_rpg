/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map gen
*/

#include "../../../include/rpg.h"

map_t	*generate_map(int seed)
{
	map_t *map = init_map(NULL, seed);
	chunk_t *_chunk = NULL;

	for (float y = 0; y < 11; y++) {
		for (float x = 0; x < 11; x++) {
			_chunk = chunk_gen(map, (pos_t){x, y, 0.0});
			list_add(&map->chunks, _chunk);
		}
	}
	return (map);
}
