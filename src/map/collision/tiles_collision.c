/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** tiles collision
*/

#include "../../../include/rpg.h"

int	can_move_here(map_t *map, pos_t pos)
{
	int	wrong_tiles[] = {TILE_WATER_ID, -1};
	tile_t *tile = get_tile_at(map, pos);

	if (tile == NULL)
		return (-1);
	for (int i = 0; wrong_tiles[i] != -1; i++) {
		if (tile->texture_id == wrong_tiles[i])
			return (0);
	}
	return (1);
}
