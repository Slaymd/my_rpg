/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map gen
*/

#include "../../include/my.h"
#include "../../include/map.h"
#include "../../include/linked_list.h"

map_t	*generate_map(int seed)
{
	map_t *map = init_map("test map", seed);
	chunk_t *_chunk = NULL;

	for (int y = -5; y < 6; y++) {
		for (int x = -5; x < 6; x++) {
			_chunk = chunk_gen(map, (pos_t){x, y, 0});
			add_to_linked_list(&map->chunks, _chunk);
		}
	}
	return (map);
}
