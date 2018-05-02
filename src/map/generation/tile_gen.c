/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include "../../../include/rpg.h"

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

int	get_texture_from_noise(float noise)
{
	if (noise < 0.40)
		return (TILE_WATER_ID);
	else if (noise < 0.50)
		return (TILE_SAND_ID);
	else if (noise < 0.80)
		return (TILE_GRASS_ID);
	else
		return (TILE_DARKGRASS_ID);
	return (1);
}

tile_t generate_tile_at(map_t *map, pos_t apos, pos_t pos)
{
	tile_t tile;
	float adjtxt[9];
	int	main_id = 0;

	get_tile_adjacent_texture_id(map, adjtxt, apos);
	for (int i = 0; i < 9; i++)
		adjtxt[i] = get_texture_from_noise(adjtxt[i]);
	main_id = (int)adjtxt[4];
	tile.pos = pos;
	tile.type = WALKABLE;
	tile.texture_id = get_texture_id(adjtxt);
	tile.sprite = NULL;
	generate_tile_objects(map, apos, main_id);
	return (tile);
}
