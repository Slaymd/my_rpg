/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include "../../../include/rpg.h"

int		get_texture_from_noise(float noise)
{
	if (noise < 0.20)
		return (1);
	else if (noise < 0.40)
		return (2);
	else if (noise < 0.48)
		return (3);
	else if (noise < 0.75)
		return (4);
	else
		return (5);
	/*if (noise < 0.15)
		return (3);
	else if (noise < 0.25)
		return (2);
	else if (noise < 0.55)
		return (5);
	else if (noise < 0.75)
		return (1);
	else
		return (4);*/
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
