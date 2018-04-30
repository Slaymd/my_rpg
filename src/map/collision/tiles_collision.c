/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** tiles collision
*/

#include "../../../include/rpg.h"

int	can_be_placed_here(map_t *map, sfSprite *sprite, pos_t pos)
{
	sfVector2f scale = sfSprite_getScale(sprite);
	sfIntRect rect = sfSprite_getTextureRect(sprite);
	pos_t bpos = pos;
	pos_t mpos = {pos.x+(rect.width*scale.x/TILE_SIZE),
	pos.y+(rect.height*scale.y/TILE_SIZE), 0};
	int	txt_id = get_texture_from_noise(
		get_perlin_value(map, pos, FREQ, DEPTH));

	for (; !(pos.x == mpos.x && pos.y == mpos.y); pos.x += 1) {
		if (get_texture_from_noise(
			get_perlin_value(map, pos, FREQ, DEPTH)) != txt_id)
			return (0);
		if (pos.x == mpos.x) {
			pos.x = bpos.x-1;
			pos.y += 1;
		}
	}
	return (1);
}

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
