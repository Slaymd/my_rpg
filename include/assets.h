/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** assets header
*/

#ifndef __RPG_ASSETS_H__
#define __RPG_ASSETS_H__

#include "rpg.h"

#define TXTRE_GRASS "assets/textures/grass.jpg"
#define TXTRE_WATER "assets/textures/water.jpg"
#define TXTRE_DEEP_WATER "assets/textures/deep_water.jpg"
#define TXTRE_LIGHT_STONE "assets/textures/light_stone.jpg"

typedef struct texture_s texture_t;

struct texture_s {
	int				id;
	char				*texture_path;
	sfSprite			*sprite;
	sfRectangleShape	*shape;
};

//Init textures
linked_list_t	*init_textures(void);

#endif /* RPG_ASSETS_H_ */
