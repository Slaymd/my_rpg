/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map header
*/

#ifndef __RPG_MAP_H__
#define __RPG_MAP_H__

#include "rpg.h"

typedef struct pos_s pos_t;

typedef struct tile_s tile_t;
typedef struct object_s object_t;
typedef struct entity_s entity_t;

typedef struct chunk_s chunk_t;

typedef struct map_s map_t;

typedef enum entity_type_e entity_type;
typedef enum object_type_e object_type;
typedef enum tile_type_e tile_type;

enum entity_type_e { NO_AI, ANIMAL, MONSTER, };

enum object_type_e { ENVIRONNEMENT, BUILDING, DECORATION };

enum tile_type_e { WALKABLE, NON_WALKABLE };

struct linked_list_s {
	void *data;
	linked_list_s;
}

struct pos_s {
	int		x;
	int		y;
	int		z;
}

struct entity_s {
	pos_t		pos;
	entity_type	type;
	sfSprite		*sprite;
}

struct object_s {
	pos_t		pos;
	object_type	type;
	sfSprite		*sprite;
}

struct tile_s {
	pos_t		pos;
	tile_type		type;
	sfSprite		*sprite;
}

struct chunk_s {
	pos_t		pos;
	tile_t		**tiles;
}

struct map_s {
	char			*name;
	int			seed;
	linked_list_t	*chunks;
	linked_list_t	*objects;
	linked_list_t	*entities;
}

#endif /* RPG_MAP_H_ */
