/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map gen
*/

#include "../../../include/my.h"
#include "../../../include/map.h"
#include "../../../include/linked_list.h"

map_t	*generate_map(int seed)
{
	map_t *map = init_map(NULL, seed);
	chunk_t *_chunk = NULL;

	for (float y = 0; y < 11; y++) {
		for (float x = 0; x < 11; x++) {
			_chunk = chunk_gen(map, (pos_t){x, y, 0.0});
			add_to_linked_list(&map->chunks, _chunk);
		}
	}
	return (map);
}
