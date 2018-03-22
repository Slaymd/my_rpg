/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include "../../../include/my.h"
#include "../../../include/map.h"
#include "../../../include/assets.h"

int		get_texture_from_noise(float noise)
{
	if (noise <= -0.25)
		return (3);
	else if (noise < 0.0)
		return (2);
	else if (noise < 0.3)
		return (1);
	else
		return (4);
	return (1);
}

tile_t init_tile(float x, float y, float noisevalue)
{
	tile_t tile;

	tile.pos = (pos_t){x, y, 0};
	tile.type = WALKABLE;
	tile.texture_id = get_texture_from_noise(noisevalue);
	tile.sprite = NULL;
	return (tile);
}
