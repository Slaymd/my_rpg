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
	pos_t mpos = {pos.x+(int)(rect.width*scale.x/TILE_SIZE),
	pos.y+(int)(rect.height*scale.y/TILE_SIZE), 0};
	int	txt_id = get_texture_from_noise(
		get_perlin_value(map, pos, FREQ, DEPTH));

	for (; !(pos.x == mpos.x && pos.y == mpos.y); pos.x += 1) {
		if (get_texture_from_noise(get_perlin_value(map, pos,FREQ, DEPTH))
		!= txt_id || is_occuped_by_object_here(map, pos)) {
			return (0);
		}
		if (pos.x == mpos.x) {
			pos.x = bpos.x-1;
			pos.y += 1;
		}
	}
	return (1);
}

int	is_occuped_by_object_here(map_t *map, pos_t pos)
{
	list_t *objs = map->objects;
	object_t *obj = NULL;
	sfVector2f scale;
	sfIntRect rect;
	pos_t mpos;

	for (; objs != NULL; objs = objs->next) {
		obj = (object_t*)objs->data;
		if (distance_between(pos, obj->pos) > WIDTH/TILE_SIZE*2 ||
		obj->type == WALKABLE)
			continue;
		scale = sfSprite_getScale(obj->sprite);
		rect = sfSprite_getTextureRect(obj->sprite);
		mpos = (pos_t){obj->pos.x+(int)(rect.width*scale.x/TILE_SIZE),
		obj->pos.y+(int)(rect.height*scale.y/TILE_SIZE), 0};
		if (pos.x >= obj->pos.x && pos.x <= mpos.x &&
			pos.y >= obj->pos.y && pos.y <= mpos.y)
			return (1);
	}
	return (0);
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
	return (is_occuped_by_object_here(map, pos) ? 0 : 1);
}
