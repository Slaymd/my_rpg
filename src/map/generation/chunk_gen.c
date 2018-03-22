/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** chunk gen
*/

#include "../../../include/my.h"
#include "../../../include/map.h"

float Get2DPerlinNoiseValue(float x, float y, float res);

chunk_t	*chunk_gen(map_t *map, pos_t pos)
{
	chunk_t	*chunk = init_chunk(pos);
	pos_t	tile_pos = {0, 0, 0};
	pos_t	absol_pos = {0, 0, 0};
	float	noise = 0;

	for (int y = 0; y < TILES_PER_CHUNKS; y++) {
		for (int x = 0; x < TILES_PER_CHUNKS; x++) {
			printf("%d, %d\n", x, y);
			tile_pos = (pos_t){(float)x, (float)y, 0.0};
			printf("getting absol...\n");
			absol_pos = get_absolute_pos(chunk, tile_pos);
			printf("$absol: %f, %f\n", absol_pos.x, absol_pos.y);
			printf("getting noise...\n");
			noise = Get2DPerlinNoiseValue(abs(absol_pos.x), abs(absol_pos.y), 21);
			printf("$noise: %f\n", noise);
			printf("init tile...\n");
			printf("(%f, %f) - $perlin: %f\n", absol_pos.x, absol_pos.y, noise);
			chunk->tiles[y][x] = init_tile(x, y, noise);
		}
	}
	return (chunk);
}
