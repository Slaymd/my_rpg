/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** tiles collision
*/

#include "../../../include/rpg.h"

int	can_move_here(map_t *map, pos_t pos)
{
	tile_t *tile = get_tile_at(map, pos);

	printf("(%f, %f)\n", pos.x, pos.y);
	if (tile == NULL)
		return (-1);
	printf("TXTRE ID : %d\n", tile->texture_id);
	if (tile->texture_id <= 2 || tile->texture_id > 4)
		return (1);
	return (0);
}
