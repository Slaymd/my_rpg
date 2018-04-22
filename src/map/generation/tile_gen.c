/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include "../../../include/rpg.h"

/*tile_t init_tile(float x, float y, float noisevalue)
{
	tile_t tile;

	tile.pos = (pos_t){x, y, 0};
	tile.type = WALKABLE;
	tile.texture_id = get_texture_from_noise(noisevalue);
	tile.sprite = NULL;
	return (tile);
}*/

int get_tile_adjacent_texture_id(map_t *map, float adjtxt[9], pos_t apos)
{
	adjtxt[0] = get_perlin_value(map, (pos_t){apos.x-1, apos.y-1, 0},
	FREQ, DEPTH);
	adjtxt[1] = get_perlin_value(map, (pos_t){apos.x, apos.y-1, 0},
	FREQ, DEPTH);
	adjtxt[2] = get_perlin_value(map, (pos_t){apos.x+1, apos.y-1, 0},
	FREQ, DEPTH);
	adjtxt[3] = get_perlin_value(map, (pos_t){apos.x-1, apos.y, 0},
	FREQ, DEPTH);
	adjtxt[4] = get_perlin_value(map, (pos_t){apos.x, apos.y, 0},
	FREQ, DEPTH);
	adjtxt[5] = get_perlin_value(map, (pos_t){apos.x+1, apos.y, 0},
	FREQ, DEPTH);
	adjtxt[6] = get_perlin_value(map, (pos_t){apos.x-1, apos.y+1, 0},
	FREQ, DEPTH);
	adjtxt[7] = get_perlin_value(map, (pos_t){apos.x, apos.y+1, 0},
	FREQ, DEPTH);
	adjtxt[8] = get_perlin_value(map, (pos_t){apos.x+1, apos.y+1, 0},
	FREQ, DEPTH);
	return (0);
}

tile_t generate_tile_at(map_t *map, pos_t apos, pos_t pos)
{
	tile_t tile;
	float adjtxt[9];

	get_tile_adjacent_texture_id(map, adjtxt, apos);
	tile.pos = pos;
	tile.type = WALKABLE;
	tile.texture_id = get_texture_id(adjtxt);
	tile.sprite = NULL;
	return (tile);
}
