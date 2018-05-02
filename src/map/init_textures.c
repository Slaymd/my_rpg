/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** textures
*/

#include "../../include/rpg.h"

texture_t *init_texture(int id, char *path, sfColor color)
{
	texture_t	*texture = (texture_t*)malloc(sizeof(texture_t));
	sfTexture	*txt = sfTexture_createFromFile(path, NULL);
	sfVector2f tilesize = (sfVector2f){TILE_SIZE, TILE_SIZE};
	sfVector2u txtsize = {0, 0};

	texture->id = id;
	texture->sprite = sfSprite_create();
	sfSprite_setTexture(texture->sprite, txt, sfTrue);
	texture->shape = sfRectangleShape_create();
	sfRectangleShape_setFillColor(texture->shape, color);
	sfRectangleShape_setSize(texture->shape, tilesize);
	txtsize = sfTexture_getSize(txt);
	sfSprite_setScale(texture->sprite, (sfVector2f){tilesize.x/txtsize.x,
	tilesize.y/txtsize.y});
	return (texture);
}

list_t	*init_textures(void)
{
	list_t	*txts = NULL;

	list_add(&txts, init_texture(TILE_WATER_ID, TXTRE_WATER, sfBlue));
	list_add(&txts, init_texture(TILE_SAND_ID, TXTRE_SAND, sfYellow));
	list_add(&txts, init_texture(TILE_GRASS_ID, TXTRE_GRASS, sfGreen));
	list_add(&txts, init_texture(TILE_DARKGRASS_ID,
		TXTRE_DARK_GRASS, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_W1_ID, TXTRE_GRASS_W1, sfGreen));

	list_add(&txts, init_texture(TILE_SAND_SE1_ID, TXTRE_SAND_SE1, sfYellow));
	list_add(&txts, init_texture(TILE_SAND_S1_ID, TXTRE_SAND_S1, sfYellow));
	list_add(&txts, init_texture(TILE_SAND_SW1_ID, TXTRE_SAND_SW1, sfYellow));
	list_add(&txts, init_texture(TILE_SAND_W1_ID, TXTRE_SAND_W1, sfYellow));
	list_add(&txts, init_texture(TILE_SAND_NW1_ID, TXTRE_SAND_NW1, sfYellow));
	list_add(&txts, init_texture(TILE_SAND_N1_ID, TXTRE_SAND_N1, sfYellow));
	list_add(&txts, init_texture(TILE_SAND_NE1_ID, TXTRE_SAND_NE1, sfYellow));
	list_add(&txts, init_texture(TILE_SAND_E1_ID, TXTRE_SAND_E1, sfYellow));
	list_add(&txts, init_texture(TILE_SAND_N1NE1E1_ID, TXTRE_SAND_N1NE1E1, sfYellow));
	list_add(&txts, init_texture(TILE_SAND_N1NW1W1_ID, TXTRE_SAND_N1NW1W1, sfYellow));
	list_add(&txts, init_texture(TILE_SAND_W1SW1S1_ID, TXTRE_SAND_W1SW1S1, sfYellow));
	list_add(&txts, init_texture(TILE_SAND_E1SE1S1_ID, TXTRE_SAND_E1SE1S1, sfYellow));

	list_add(&txts, init_texture(TILE_GRASS_SE1_ID, TXTRE_GRASS_SE1, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_S1_ID, TXTRE_GRASS_S1, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_SW1_ID, TXTRE_GRASS_SW1, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_W1_ID, TXTRE_GRASS_W1, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_NW1_ID, TXTRE_GRASS_NW1, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_N1_ID, TXTRE_GRASS_N1, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_NE1_ID, TXTRE_GRASS_NE1, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_E1_ID, TXTRE_GRASS_E1, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_N1NE1E1_ID, TXTRE_GRASS_N1NE1E1, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_N1NW1W1_ID, TXTRE_GRASS_N1NW1W1, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_W1SW1S1_ID, TXTRE_GRASS_W1SW1S1, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_E1SE1S1_ID, TXTRE_GRASS_E1SE1S1, sfGreen));

	list_add(&txts, init_texture(TILE_GRASS_SE2_ID, TXTRE_GRASS_SE2, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_S2_ID, TXTRE_GRASS_S2, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_SW2_ID, TXTRE_GRASS_SW2, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_W2_ID, TXTRE_GRASS_W2, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_NW2_ID, TXTRE_GRASS_NW2, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_N2_ID, TXTRE_GRASS_N2, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_NE2_ID, TXTRE_GRASS_NE2, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_E2_ID, TXTRE_GRASS_E2, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_N2NE2E2_ID, TXTRE_GRASS_N2NE2E2, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_N2NW2W2_ID, TXTRE_GRASS_N2NW2W2, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_W2SW2S2_ID, TXTRE_GRASS_W2SW2S2, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_E2SE2S2_ID, TXTRE_GRASS_E2SE2S2, sfGreen));

	list_add(&txts, init_texture(TILE_GRASS_SE4_ID, TXTRE_GRASS_SE4, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_S4_ID, TXTRE_GRASS_S4, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_SW4_ID, TXTRE_GRASS_SW4, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_W4_ID, TXTRE_GRASS_W4, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_NW4_ID, TXTRE_GRASS_NW4, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_N4_ID, TXTRE_GRASS_N4, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_NE4_ID, TXTRE_GRASS_NE4, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_E4_ID, TXTRE_GRASS_E4, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_N4NE4E4_ID, TXTRE_GRASS_N4NE4E4, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_N4NW4W4_ID, TXTRE_GRASS_N4NW4W4, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_W4SW4S4_ID, TXTRE_GRASS_W4SW4S4, sfGreen));
	list_add(&txts, init_texture(TILE_GRASS_E4SE4S4_ID, TXTRE_GRASS_E4SE4S4, sfGreen));
	return (txts);
}
