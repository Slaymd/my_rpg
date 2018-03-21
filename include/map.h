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

enum entity_type_e { NO_AI, ANIMAL, MONSTER };

enum object_type_e { ENVIRONNEMENT, BUILDING, DECORATION };

enum tile_type_e { WALKABLE, NON_WALKABLE };

struct pos_s {
	int		x;
	int		y;
	int		z;
};

struct entity_s {
	pos_t		pos;
	entity_type	type;
	sfSprite		*sprite;
};

struct object_s {
	pos_t		pos;
	object_type	type;
	sfSprite		*sprite;
};

struct tile_s {
	pos_t		pos;
	tile_type		type;
	int			texture_id;
	sfSprite		*sprite;
};

struct chunk_s {
	pos_t		pos;
	tile_t		**tiles;
};

struct map_s {
	char			*name;
	int			seed;
	linked_list_t	*chunks;
	linked_list_t	*objects;
	linked_list_t	*entities;
	linked_list_t	*textures;
};

//INITS
map_t *init_map(char *name, int seed);
chunk_t *init_chunk(pos_t pos);
tile_t init_tile(int x, int y, int noisevalue);

//MAP GEN
map_t	*generate_map(int seed);
chunk_t	*chunk_gen(map_t *map, pos_t pos);

//TILE SPRITES
sfSprite	*get_tile_sprite(map_t *map, tile_t *tile);

//DISP
int	disp_map(sfRenderWindow *wd, map_t *map);

#endif /* RPG_MAP_H_ */
