/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** pos tools
*/

#include "../../include/my.h"
#include "../../include/map.h"
#include "../../include/assets.h"

pos_t	get_chunk_coords(pos_t pos)
{
	int x = (int)pos.x/16;
	int y = (int)pos.y/16;
	pos_t	cpos = {x, y, 0};

	cpos.x = pos.x < 0 ? cpos.x-1 : cpos.x;
	cpos.y = pos.y < 0 ? cpos.y-1 : cpos.y;
	return (cpos);
}

int		is_coords_in_chunk(pos_t pos, chunk_t *chunk)
{
	pos_t	cpos = get_chunk_coords(pos);

	if (cpos.x == chunk->pos.x && cpos.y == chunk->pos.y)
		return (1);
	return (0);
}

pos_t	get_absolute_pos(chunk_t *chunk, pos_t pos)
{
	pos_t	absol = {0, 0, 0};

	absol.x = chunk->pos.x*16+pos.x;
	absol.y = chunk->pos.y*16+pos.y;
	return (absol);
}

sfVector2f	get_relative_pixel_pos(pos_t ref, chunk_t *chk, pos_t pos)
{
	pos_t		absol_pos = get_absolute_pos(chk, pos);
	sfVector2f	relat_pos = {0, 0};

	relat_pos.x = (absol_pos.x-ref.x)*TILE_SIZE;
	relat_pos.y = (absol_pos.y-ref.y)*TILE_SIZE;
	return (relat_pos);
}
