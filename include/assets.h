/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** assets header
*/

#ifndef __RPG_ASSETS_H__
#define __RPG_ASSETS_H__

#include "rpg.h"

#define C_F5F6FA	(sfColor){245, 246, 250, 255}
#define C_8C7AE6	(sfColor){140, 122, 230, 255}

#define FONT_UBUMED "assets/fonts/Ubuntu-M.ttf"
#define FONT_UBUREG "assets/fonts/Ubuntu-R.ttf"

#define NPC_GAME "assets/textures/objects/little_stone_2.png"
#define NPC_KID "assets/textures/objects/little_stone_2.png"
#define TXTR_ARROW "img/arrow.png"

#define TXTRE_GRASS "assets/textures/tiles/grass.png"
#define TXTRE_WATER "assets/textures/tiles/water.png"
#define TXTRE_SAND "assets/textures/tiles/sand.png"
#define TXTRE_DARK_GRASS "assets/textures/tiles/darkgrass.png"

#define TXTRE_LITTLE_STONE1 "assets/textures/objects/little_stone_1.png"
#define TXTRE_LITTLE_STONE2 "assets/textures/objects/little_stone_2.png"

#define TXTRE_LITTLE_BUSH "assets/textures/objects/little_bush.png"
#define TXTRE_BIG_BUSH1 "assets/textures/objects/big_bush_1.png"
#define TXTRE_BIG_BUSH2 "assets/textures/objects/big_bush_2.png"

#define TXTRE_FLOWERS1 "assets/textures/objects/flowers_1.png"
#define TXTRE_FLOWERS2 "assets/textures/objects/flowers_2.png"
#define TXTRE_FLOWERS3 "assets/textures/objects/flowers_3.png"

#define TXTRE_LILY_PAD1 "assets/textures/objects/lily_pad_1.png"

#define TXTRE_WATER_WAVE "assets/textures/objects/water_wave.png"

#define TXTRE_LOG "assets/textures/objects/log.png"

#define TXTRE_WOODEN_HOUSE "assets/textures/objects/wooden_house.png"
#define TXTRE_VILLAGE1 "assets/textures/objects/village_1.png"


#define LIST_LITTLE_STONE "assets/textures/objects/little_stone_1.png:\
assets/textures/objects/little_stone_2.png"
#define LIST_FLOWERS "assets/textures/objects/flowers_1.png:\
assets/textures/objects/flowers_2.png:\
assets/textures/objects/flowers_3.png"
#define LIST_VILLAGE "assets/textures/objects/village_1.png"
#define LIST_LILY_PAD "assets/textures/objects/lily_pad_1.png"
#define LIST_WOODEN_HOUSE "assets/textures/objects/wooden_house.png"
#define LIST_WATER_WAVE "assets/textures/objects/water_wave.png"
#define LIST_LITTLE_BUSH "assets/textures/objects/little_bush.png"
#define LIST_BIG_BUSH "assets/textures/objects/big_bush_1.png:\
assets/textures/objects/big_bush_2.png"
#define LIST_LOG "assets/textures/objects/log.png"

#define TXTRE_LIST_LITTLE_STONE {TXTRE_LITTLE_STONE1,\
	TXTRE_LITTLE_STONE2, NULL}
#define TXTRE_LIST_FLOWERS {TXTRE_FLOWERS1, TXTRE_FLOWERS2, TXTRE_FLOWERS3,\
	NULL}
#define TXTRE_LIST_VILLAGE {TXTRE_VILLAGE1, NULL}
#define TXTRE_LIST_LILY_PAD {TXTRE_LILY_PAD1, NULL}
#define TXTRE_LIST_WOODEN_HOUSE {TXTRE_WOODEN_HOUSE, NULL}
#define TXTRE_LIST_WATER_WAVE {TXTRE_WATER_WAVE, NULL}
#define TXTRE_LIST_LITTLE_BUSH {TXTRE_LITTLE_BUSH, NULL}
#define TXTRE_LIST_BIG_BUSH {TXTRE_BIG_BUSH1, TXTRE_BIG_BUSH2, NULL}
#define TXTRE_LIST_LOG {TXTRE_LOG, NULL}

//Textures variations

#define TXTRE_GRASS_SE1 "assets/textures/tiles/grass_varSE1.png"
#define TXTRE_GRASS_S1 "assets/textures/tiles/grass_varS1.png"
#define TXTRE_GRASS_SW1 "assets/textures/tiles/grass_varSW1.png"
#define TXTRE_GRASS_W1 "assets/textures/tiles/grass_varW1.png"
#define TXTRE_GRASS_NW1 "assets/textures/tiles/grass_varNW1.png"
#define TXTRE_GRASS_N1 "assets/textures/tiles/grass_varN1.png"
#define TXTRE_GRASS_NE1 "assets/textures/tiles/grass_varNE1.png"
#define TXTRE_GRASS_E1 "assets/textures/tiles/grass_varE1.png"

#define TXTRE_GRASS_N1NE1E1 "assets/textures/tiles/grass_varN1NE1E1.png"
#define TXTRE_GRASS_E1SE1S1 "assets/textures/tiles/grass_varE1SE1S1.png"
#define TXTRE_GRASS_W1SW1S1 "assets/textures/tiles/grass_varW1SW1S1.png"
#define TXTRE_GRASS_N1NW1W1 "assets/textures/tiles/grass_varN1NW1W1.png"

#define TXTRE_SAND_SE1 "assets/textures/tiles/sand_varSE1.png"
#define TXTRE_SAND_S1 "assets/textures/tiles/sand_varS1.png"
#define TXTRE_SAND_SW1 "assets/textures/tiles/sand_varSW1.png"
#define TXTRE_SAND_W1 "assets/textures/tiles/sand_varW1.png"
#define TXTRE_SAND_NW1 "assets/textures/tiles/sand_varNW1.png"
#define TXTRE_SAND_N1 "assets/textures/tiles/sand_varN1.png"
#define TXTRE_SAND_NE1 "assets/textures/tiles/sand_varNE1.png"
#define TXTRE_SAND_E1 "assets/textures/tiles/sand_varE1.png"

#define TXTRE_SAND_N1NE1E1 "assets/textures/tiles/sand_varN1NE1E1.png"
#define TXTRE_SAND_E1SE1S1 "assets/textures/tiles/sand_varE1SE1S1.png"
#define TXTRE_SAND_W1SW1S1 "assets/textures/tiles/sand_varW1SW1S1.png"
#define TXTRE_SAND_N1NW1W1 "assets/textures/tiles/sand_varN1NW1W1.png"

#define TXTRE_GRASS_SE2 "assets/textures/tiles/grass_varSE2.png"
#define TXTRE_GRASS_S2 "assets/textures/tiles/grass_varS2.png"
#define TXTRE_GRASS_SW2 "assets/textures/tiles/grass_varSW2.png"
#define TXTRE_GRASS_W2 "assets/textures/tiles/grass_varW2.png"
#define TXTRE_GRASS_NW2 "assets/textures/tiles/grass_varNW2.png"
#define TXTRE_GRASS_N2 "assets/textures/tiles/grass_varN2.png"
#define TXTRE_GRASS_NE2 "assets/textures/tiles/grass_varNE2.png"
#define TXTRE_GRASS_E2 "assets/textures/tiles/grass_varE2.png"

#define TXTRE_GRASS_N2NE2E2 "assets/textures/tiles/grass_varN2NE2E2.png"
#define TXTRE_GRASS_E2SE2S2 "assets/textures/tiles/grass_varE2SE2S2.png"
#define TXTRE_GRASS_W2SW2S2 "assets/textures/tiles/grass_varW2SW2S2.png"
#define TXTRE_GRASS_N2NW2W2 "assets/textures/tiles/grass_varN2NW2W2.png"

#define TXTRE_GRASS_SE4 "assets/textures/tiles/grass_varSE4.png"
#define TXTRE_GRASS_S4 "assets/textures/tiles/grass_varS4.png"
#define TXTRE_GRASS_SW4 "assets/textures/tiles/grass_varSW4.png"
#define TXTRE_GRASS_W4 "assets/textures/tiles/grass_varW4.png"
#define TXTRE_GRASS_NW4 "assets/textures/tiles/grass_varNW4.png"
#define TXTRE_GRASS_N4 "assets/textures/tiles/grass_varN4.png"
#define TXTRE_GRASS_NE4 "assets/textures/tiles/grass_varNE4.png"
#define TXTRE_GRASS_E4 "assets/textures/tiles/grass_varE4.png"

#define TXTRE_GRASS_N4NE4E4 "assets/textures/tiles/grass_varN4NE4E4.png"
#define TXTRE_GRASS_E4SE4S4 "assets/textures/tiles/grass_varE4SE4S4.png"
#define TXTRE_GRASS_W4SW4S4 "assets/textures/tiles/grass_varW4SW4S4.png"
#define TXTRE_GRASS_N4NW4W4 "assets/textures/tiles/grass_varN4NW4W4.png"

#define TXTRE_OSTRICH "assets/entities/ostrich.png"
#define TXTRE_STONE_OGRE "assets/entities/stone_ogre.png"
#define TXTRE_LYCANTHROPE "assets/entities/lycanthrope.png"
#define TXTRE_VILLAGER "assets/entities/npc_game.png"

//Textures ID

#define TILE_WATER_ID 1
#define TILE_SAND_ID 2
#define TILE_GRASS_ID 3
#define TILE_DARKGRASS_ID 4

//Textures variations ID

#define TILE_GRASS_SE1_ID 301
#define TILE_GRASS_S1_ID 302
#define TILE_GRASS_SW1_ID 303
#define TILE_GRASS_W1_ID 304
#define TILE_GRASS_NW1_ID 305
#define TILE_GRASS_N1_ID 306
#define TILE_GRASS_NE1_ID 307
#define TILE_GRASS_E1_ID 308
#define TILE_GRASS_N1NE1E1_ID 309
#define TILE_GRASS_E1SE1S1_ID 310
#define TILE_GRASS_W1SW1S1_ID 311
#define TILE_GRASS_N1NW1W1_ID 312

#define TILE_GRASS_SE2_ID 313
#define TILE_GRASS_S2_ID 314
#define TILE_GRASS_SW2_ID 315
#define TILE_GRASS_W2_ID 316
#define TILE_GRASS_NW2_ID 317
#define TILE_GRASS_N2_ID 318
#define TILE_GRASS_NE2_ID 319
#define TILE_GRASS_E2_ID 320
#define TILE_GRASS_N2NE2E2_ID 321
#define TILE_GRASS_E2SE2S2_ID 322
#define TILE_GRASS_W2SW2S2_ID 323
#define TILE_GRASS_N2NW2W2_ID 324

#define TILE_GRASS_SE4_ID 325
#define TILE_GRASS_S4_ID 326
#define TILE_GRASS_SW4_ID 327
#define TILE_GRASS_W4_ID 328
#define TILE_GRASS_NW4_ID 329
#define TILE_GRASS_N4_ID 330
#define TILE_GRASS_NE4_ID 331
#define TILE_GRASS_E4_ID 332
#define TILE_GRASS_N4NE4E4_ID 333
#define TILE_GRASS_E4SE4S4_ID 334
#define TILE_GRASS_W4SW4S4_ID 335
#define TILE_GRASS_N4NW4W4_ID 336

#define TILE_SAND_SE1_ID 201
#define TILE_SAND_S1_ID 202
#define TILE_SAND_SW1_ID 203
#define TILE_SAND_W1_ID 204
#define TILE_SAND_NW1_ID 205
#define TILE_SAND_N1_ID 206
#define TILE_SAND_NE1_ID 207
#define TILE_SAND_E1_ID 208
#define TILE_SAND_N1NE1E1_ID 209
#define TILE_SAND_E1SE1S1_ID 210
#define TILE_SAND_W1SW1S1_ID 211
#define TILE_SAND_N1NW1W1_ID 212

#define S_SE1 {-1.0, -1.0, -1.0, -1.0, 2.0, 2.0, -1.0, 2.0, 1.0}
#define S_S1 {-1.0, -1.0, -1.0, -1.0, 2.0, -1.0, -1.0, 1.0, -1.0}
#define S_SW1 {-1.0, -1.0, -1.0, 2.0, 2.0, -1.0, 1.0, 2.0, -1.0}
#define S_W1 {-1.0, -1.0, -1.0, 1.0, 2.0, -1.0, -1.0, -1.0, -1.0}
#define S_NW1 {1.0, 2.0, -1.0, 2.0, 2.0, -1.0, -1.0, -1.0, -1.0}
#define S_N1 {-1.0, 1.0, -1.0, -1.0, 2.0, -1.0, -1.0, -1.0, -1.0}
#define S_NE1 {-1.0, 2.0, 1.0, -1.0, 2.0, 2.0, -1.0, -1.0, -1.0}
#define S_E1 {-1.0, -1.0, -1.0, -1.0, 2.0, 1.0, -1.0, -1.0, -1.0}

#define S_N1NE1E1 {-1.0, 1.0, 1.0, -1.0, 2.0, 1.0, -1.0, -1.0, -1.0}
#define S_E1SE1S1 {-1.0, -1.0, -1.0, -1.0, 2.0, 1.0, -1.0, 1.0, 1.0}
#define S_W1SW1S1 {-1.0, -1.0, -1.0, 1.0, 2.0, -1.0, 1.0, 1.0, -1.0}
#define S_N1NW1W1 {1.0, 1.0, -1.0, 1.0, 2.0, -1.0, -1.0, -1.0, -1.0}

#define G_SE1 {-1.0, -1.0, -1.0, -1.0, 3.0, 3.0, -1.0, 3.0, 1.0}
#define G_S1 {-1.0, -1.0, -1.0, -1.0, 3.0, -1.0, -1.0, 1.0, -1.0}
#define G_SW1 {-1.0, -1.0, -1.0, 3.0, 3.0, -1.0, 1.0, 3.0, -1.0}
#define G_W1 {-1.0, -1.0, -1.0, 1.0, 3.0, -1.0, -1.0, -1.0, -1.0}
#define G_NW1 {1.0, 3.0, -1.0, 3.0, 3.0, -1.0, -1.0, -1.0, -1.0}
#define G_N1 {-1.0, 1.0, -1.0, -1.0, 3.0, -1.0, -1.0, -1.0, -1.0}
#define G_NE1 {-1.0, 3.0, 1.0, -1.0, 3.0, 3.0, -1.0, -1.0, -1.0}
#define G_E1 {-1.0, -1.0, -1.0, -1.0, 3.0, 1.0, -1.0, -1.0, -1.0}

#define G_N1NE1E1 {-1.0, 1.0, 1.0, -1.0, 3.0, 1.0, -1.0, -1.0, -1.0}
#define G_E1SE1S1 {-1.0, -1.0, -1.0, -1.0, 3.0, 1.0, -1.0, 1.0, 1.0}
#define G_W1SW1S1 {-1.0, -1.0, -1.0, 1.0, 3.0, -1.0, 1.0, 1.0, -1.0}
#define G_N1NW1W1 {1.0, 1.0, -1.0, 1.0, 3.0, -1.0, -1.0, -1.0, -1.0}

#define G_SE2 {-1.0, -1.0, -1.0, -1.0, 3.0, 3.0, -1.0, 3.0, 2.0}
#define G_S2 {-1.0, -1.0, -1.0, -1.0, 3.0, -1.0, -1.0, 2.0, -1.0}
#define G_SW2 {-1.0, -1.0, -1.0, 3.0, 3.0, -1.0, 2.0, 3.0, -1.0}
#define G_W2 {-1.0, -1.0, -1.0, 2.0, 3.0, -1.0, -1.0, -1.0, -1.0}
#define G_NW2 {2.0, 3.0, -1.0, 3.0, 3.0, -1.0, -1.0, -1.0, -1.0}
#define G_N2 {-1.0, 2.0, -1.0, -1.0, 3.0, -1.0, -1.0, -1.0, -1.0}
#define G_NE2 {-1.0, 3.0, 2.0, -1.0, 3.0, 3.0, -1.0, -1.0, -1.0}
#define G_E2 {-1.0, -1.0, -1.0, -1.0, 3.0, 2.0, -1.0, -1.0, -1.0}

#define G_N2NE2E2 {-1.0, 2.0, 2.0, -1.0, 3.0, 2.0, -1.0, -1.0, -1.0}
#define G_E2SE2S2 {-1.0, -1.0, -1.0, -1.0, 3.0, 2.0, -1.0, 2.0, 2.0}
#define G_W2SW2S2 {-1.0, -1.0, -1.0, 2.0, 3.0, -1.0, 2.0, 2.0, -1.0}
#define G_N2NW2W2 {2.0, 2.0, -1.0, 2.0, 3.0, -1.0, -1.0, -1.0, -1.0}

#define G_SE4 {-1.0, -1.0, -1.0, -1.0, 3.0, 3.0, -1.0, 3.0, 4.0}
#define G_S4 {-1.0, -1.0, -1.0, -1.0, 3.0, -1.0, -1.0, 4.0, -1.0}
#define G_SW4 {-1.0, -1.0, -1.0, 3.0, 3.0, -1.0, 4.0, 3.0, -1.0}
#define G_W4 {-1.0, -1.0, -1.0, 4.0, 3.0, -1.0, -1.0, -1.0, -1.0}
#define G_NW4 {4.0, 3.0, -1.0, 3.0, 3.0, -1.0, -1.0, -1.0, -1.0}
#define G_N4 {-1.0, 4.0, -1.0, -1.0, 3.0, -1.0, -1.0, -1.0, -1.0}
#define G_NE4 {-1.0, 3.0, 4.0, -1.0, 3.0, 3.0, -1.0, -1.0, -1.0}
#define G_E4 {-1.0, -1.0, -1.0, -1.0, 3.0, 4.0, -1.0, -1.0, -1.0}

#define G_N4NE4E4 {-1.0, 4.0, 4.0, -1.0, 3.0, 4.0, -1.0, -1.0, -1.0}
#define G_E4SE4S4 {-1.0, -1.0, -1.0, -1.0, 3.0, 4.0, -1.0, 4.0, 4.0}
#define G_W4SW4S4 {-1.0, -1.0, -1.0, 4.0, 3.0, -1.0, 4.0, 4.0, -1.0}
#define G_N4NW4W4 {4.0, 4.0, -1.0, 4.0, 3.0, -1.0, -1.0, -1.0, -1.0}

#define DSTP {-2.0, -2.0, -2.0, -2.0, -2.0, -2.0, -2.0, -2.0, -2.0}

typedef struct texture_s texture_t;

struct texture_s {
	int				id;
	char				*texture_path;
	sfSprite			*sprite;
	sfRectangleShape	*shape;
};

//Init textures
list_t	*init_textures(void);

#endif /* RPG_ASSETS_H_ */
