/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include "../../include/my.h"
#include "../../include/map.h"
#include "../../include/assets.h"

sfSprite *get_sprite_from_noise_value(int noisevalue)
{
	sfTexture	*txt = NULL;
	sfSprite	*sprite = sfSprite_create();

	if (noisevalue >= 1 && noisevalue <= 75) {
		txt = sfTexture_createFromFile(TXTRE_GRASS, NULL);
		sfSprite_setTexture(sprite, txt, sfTrue);
	}
	return (sprite);
}

tile_t init_tile(int x, int y, int noisevalue)
{
	tile_t tile;

	tile.pos = (pos_t){x, y, 0};
	tile.type = WALKABLE;
	tile.texture_id = noisevalue >= 1 ? 1 : 0;
	tile.sprite = NULL;
	return (tile);
}
