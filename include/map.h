/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map header
*/

#ifndef __RPG_MAP_H__
#define __RPG_MAP_H__

#include "list.h"

#define TILE_SIZE 22
#define MOVE_SPEED 0.20

#define DEPTH 2
#define FREQ 0.06

#define TILES_PER_CHUNKS 16
#define DEFAULT_RENDER_DISTANCE 3

#define DEFAULT_POS_X 16000
#define DEFAULT_POS_Y 16000

#define SEED 213314

typedef struct pos_s pos_t;

typedef struct tile_s tile_t;
typedef struct object_s object_t;
typedef struct entity_s entity_t;

typedef struct window_s window_t;
typedef struct chunk_s chunk_t;
typedef struct map_s map_t;

typedef struct rpg_s rpg_t;

typedef struct entity_s entity_t;
typedef struct entity_infos_s entity_infos_t;
typedef struct object_stats_s object_stats_t;

typedef enum entity_type_e entity_type;
typedef enum collision_type_e collision_type;
typedef enum freq_type_e freq_type;
typedef enum tile_type_e tile_type;

enum entity_type_e { NO_AI, OSTRICH, STONE_OGRE, LYCANTHROPE, VILLAGER, UNKNOWN };

enum collision_type_e { WALKABLE=0, NON_WALKABLE=1 };

enum freq_type_e { MAP=0, CHUNK=1, TILE=2 };

struct pos_s {
	float		x;
	float		y;
	float		z;
};

struct object_stats_s {
	char		**txt_paths;
	float	freq;
	int		object_id;
	int		data;
	freq_type	spawn_type;
	collision_type	type;
};

struct object_s {
	pos_t		pos;
	collision_type	type;
	char			*txt_path;
	sfSprite		*sprite;
};

struct tile_s {
	pos_t		pos;
	collision_type	type;
	int			texture_id;
	sfSprite		*sprite;
};

struct chunk_s {
	pos_t		pos;
	tile_t		**tiles;
};

struct map_s {
	int	seed;
	char	*name;
	list_t	*chunks;
	list_t	*objects;
	list_t	*entities;
	list_t	*textures;
	list_t	*obj_stats;
	pos_t	topleft_to_disp;
	pos_t	center;
	sfVector2i render_distance;
};

struct entity_infos_s {
	entity_type type;
	sfIntRect rect;
	int	life;
	int	damages;
	float 	lvl;
	float	movement;
	char *tex_path;
	int num;
	pos_t pos;
	int mirror;
	int max;
	char *song;
	float hp;
};

struct entity_s {
	entity_type type;
	int num;
	int lvl;
	int movement;
	int mirror;
	int max;
	sfRectangleShape *rect;
	sfIntRect square;
	//void(*callback)();
	sfSprite *sprite;
	sfTexture *texture;
	pos_t pos;
	sfClock *clock;
	sfTime time;
	float seconds;
	sfMusic *song;
	float hp;
	sfRectangleShape *hp_bar;
};

typedef struct ptr_s {
	char balise;
	void(*callback)();
} ptr_t;


//INITS
map_t *init_map(char *name, int seed);
chunk_t *init_chunk(pos_t pos);

//OBJECTS
list_t *init_objects(void);
int	generate_tile_objects(map_t *map, pos_t pos, int txt_id);
int	free_object(object_t *obj);
//int	generate_object_of_type(map_t *map, freq_type spawn_type, pos_t pos);

//MAP GEN
map_t	*generate_map(int seed);
chunk_t	*chunk_gen(map_t *map, pos_t pos);
tile_t generate_tile_at(map_t *map, pos_t apos, pos_t pos);

//TILE SPRITES
sfSprite	*get_tile_sprite(map_t *map, tile_t *tile);

//TILE TEXTURES
int	get_texture_id(float adjtxt[9]);
int	get_texture_from_noise(float noise);
int	is_txt_var_table_match(float adjtxt[9], float txtvar[9]);
int	get_texture_variation(float adjtxt[9]);

//DISP
int	disp_map(rpg_t *rpg);
int	disp_sprite_at(sfRenderWindow *wd, map_t *mp, sfSprite *sp, pos_t p);
int	disp_objects(sfRenderWindow *wd, map_t *map);

//COORDS
pos_t	get_chunk_coords(pos_t pos);
list_t *get_nearest_chunks(map_t *map, pos_t pos);
int		is_coords_in_chunk(pos_t pos, chunk_t *chunk);
sfVector2f	get_relative_pixel_pos(pos_t ref, chunk_t *chk, pos_t pos);
pos_t	get_absolute_pos(chunk_t *chunk, pos_t pos);
chunk_t *get_chunk_at(map_t *map, pos_t pos);
tile_t *get_tile_at(map_t *map, pos_t pos);
float	distance_between(pos_t pos1, pos_t pos2);

//POS GEN
pos_t generate_pos_near(map_t *map, pos_t pos, int minradius);

//COLLISIONS
int	can_move_here(map_t *map, pos_t pos);
int	can_be_placed_here(map_t *map, sfSprite *sprite, pos_t pos);
int	is_occuped_by_object_here(map_t *map, pos_t pos);

//EVENTS
int	map_event_handler(window_t *window, map_t *map);
int map_move(sfEvent event, map_t *map);

//PERLIN
float get_perlin_value(map_t *map, pos_t pos, float freq, int depth);

#endif /* RPG_MAP_H_ */
