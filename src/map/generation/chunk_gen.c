/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** chunk gen
*/

#include "../../../include/rpg.h"

chunk_t	*chunk_gen(map_t *map, pos_t pos)
{
	chunk_t	*chunk = init_chunk(pos);
	pos_t	tpos = {0, 0, 0};
	pos_t	apos = {0, 0, 0};
	float	noise = 0;

	for (int y = 0; y < TILES_PER_CHUNKS; y++) {
		for (int x = 0; x < TILES_PER_CHUNKS; x++) {
			tpos = (pos_t){(float)x, (float)y, 0.0};
			apos = get_absolute_pos(chunk, tpos);
			noise = get_perlin_value(map, apos, FREQ, DEPTH);
			chunk->tiles[y][x] = generate_tile_at(map,apos,tpos);
		}
	}
	return (chunk);
}
