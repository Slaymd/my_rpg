/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** assets header
*/

#ifndef __RPG_ASSETS_H__
#define __RPG_ASSETS_H__

#include "rpg.h"

#define TXTRE_GRASS "assets/textures/mc_grass.png"
#define TXTRE_WATER "assets/textures/mc_water.png"
#define TXTRE_DEEP_WATER "assets/textures/mc_deep_water.png"
#define TXTRE_LIGHT_STONE "assets/textures/mc_stone.png"
#define TXTRE_SAND "assets/textures/mc_sand.png"

#define ENT_OSTRICH "assets/entities/ostrich.png"

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
