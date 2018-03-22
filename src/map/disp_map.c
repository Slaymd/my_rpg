/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** disp map
*/

#include "../../include/my.h"
#include "../../include/map.h"
#include "../../include/linked_list.h"

/*int	disp_tile(sfRenderWindow *wd, map_t *map, pos_t cpos, tile_t *tile)
{
	int	wd_x = cpos.x*(TILE_SIZE*16)+tile->pos.x*TILE_SIZE;
	int	wd_y = cpos.y*(TILE_SIZE*16)+tile->pos.y*TILE_SIZE;
	sfSprite	*sprite = NULL;

	if (wd_x <= -TILE_SIZE || wd_x >= WIDTH)
		return (84);
	if (wd_y <= -TILE_SIZE || wd_y >= HEIGHT)
		return (84);
	sprite = get_tile_sprite(map, tile);
	sfSprite_setPosition(sprite, (sfVector2f){wd_x, wd_y});
	sfRenderWindow_drawSprite(wd, sprite, NULL);
	return (0);
}*/

int	disp_tile(sfRenderWindow *wd, map_t *map, tile_t *tile, sfVector2f px)
{
	sfSprite	*sprite = NULL;

	if (px.x <= -TILE_SIZE || px.x >= WIDTH)
		return (-1);
	if (px.y <= -TILE_SIZE || px.y >= HEIGHT)
		return (-1);
	sprite = get_tile_sprite(map, tile);
	sfSprite_setPosition(sprite, px);
	sfRenderWindow_drawSprite(wd, sprite, NULL);
	return (0);
}

int	disp_chunk(sfRenderWindow *wd, map_t *map, chunk_t *chk, pos_t ref)
{
	sfVector2f px_pos = {0, 0};

	for (int x = 0, y = 0; x <= 16; x++) {
		if (x == 16) {
			x = 0;
			y++;
		}
		if (y == 16)
			break;
		px_pos = get_relative_pixel_pos(ref, chk, chk->tiles[y][x].pos);
		disp_tile(wd, map, &chk->tiles[y][x], px_pos);
	}
	return (0);
}

int	disp_map(sfRenderWindow *wd, map_t *map, pos_t ref)
{
	linked_list_t	*_chunks = get_nearest_chunks(map, ref);
	chunk_t		*chunk = NULL;

	for (; _chunks != NULL; _chunks = _chunks->next) {
		chunk = (chunk_t*)_chunks->data;
		disp_chunk(wd, map, (chunk_t*)_chunks->data, ref);
	}
	return (0);
}
