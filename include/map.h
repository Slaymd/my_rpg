/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map header
*/

#ifndef __RPG_MAP_H__
#define __RPG_MAP_H__

#include "list.h"

#define TILE_SIZE 32
#define MOVE_SPEED 0.33

#define TILES_PER_CHUNKS 32
#define DEFAULT_RENDER_DISTANCE 2

#define SEED 213314

typedef struct pos_s pos_t;

typedef struct tile_s tile_t;
typedef struct object_s object_t;
typedef struct entity_s entity_t;

typedef struct window_s window_t;
typedef struct chunk_s chunk_t;
typedef struct map_s map_t;

typedef enum entity_type_e entity_type;
typedef enum object_type_e object_type;
typedef enum tile_type_e tile_type;

enum entity_type_e { NO_AI, ANIMAL, MONSTER };

enum object_type_e { ENVIRONNEMENT, BUILDING, DECORATION };

enum tile_type_e { WALKABLE, NON_WALKABLE };

struct pos_s {
	float		x;
	float		y;
	float		z;
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
	pos_t		topleft_to_disp;
	list_t	*chunks;
	list_t	*objects;
	list_t	*entities;
	list_t	*textures;
};

//INITS
map_t *init_map(char *name, int seed);
chunk_t *init_chunk(pos_t pos);
tile_t init_tile(float x, float y, float noisevalue);

//MAP GEN
map_t	*generate_map(int seed);
chunk_t	*chunk_gen(map_t *map, pos_t pos);

//TILE SPRITES
sfSprite	*get_tile_sprite(map_t *map, tile_t *tile);

//DISP
int	disp_map(sfRenderWindow *wd, map_t *map, pos_t pos);
int	disp_sprite_at(sfRenderWindow *wd, map_t *mp, sfSprite *sp, pos_t p);

//COORDS
pos_t	get_chunk_coords(pos_t pos);
list_t *get_nearest_chunks(map_t *map, pos_t pos);
int		is_coords_in_chunk(pos_t pos, chunk_t *chunk);
sfVector2f	get_relative_pixel_pos(pos_t ref, chunk_t *chk, pos_t pos);
pos_t	get_absolute_pos(chunk_t *chunk, pos_t pos);
chunk_t *get_chunk_at(map_t *map, pos_t pos);

//EVENTS
int	map_event_handler(window_t *window, map_t *map);

//PERLIN
float get_perlin_value(map_t *map, pos_t pos, float freq, int depth);

#endif /* RPG_MAP_H_ */
