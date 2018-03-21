/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** chunk gen
*/

#include "../../include/my.h"
#include "../../include/map.h"

chunk_t	*chunk_gen(map_t *map, pos_t pos)
{
	chunk_t	*chunk = init_chunk(pos);

	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {
			chunk->tiles[y][x] = init_tile(x, y, 15);
		}
	}
	return (chunk);
}
