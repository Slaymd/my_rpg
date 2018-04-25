/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map init
*/

#include "../../include/rpg.h"

map_t *init_map(char *name, int seed)
{
	map_t	*map = (map_t*)malloc(sizeof(map_t));

	map->chunks = NULL;
	map->entities = NULL;
	map->objects = NULL;
	map->textures = init_textures();
	map->obj_stats = init_objects();
	map->seed = seed;
	map->name = name;
	map->topleft_to_disp = (pos_t){500*TILES_PER_CHUNKS,
		500*TILES_PER_CHUNKS, 0.0};
	map->render_distance = (sfVector2i){DEFAULT_RENDER_DISTANCE,
		DEFAULT_RENDER_DISTANCE};
	map->center = (pos_t){DEFAULT_POS_X, DEFAULT_POS_Y, 0};
	return (map);
}

chunk_t *init_chunk(pos_t pos)
{
	chunk_t *chunk = (chunk_t*)malloc(sizeof(chunk_t));

	chunk->pos = pos;
	chunk->tiles = (tile_t**)malloc(sizeof(tile_t*)*TILES_PER_CHUNKS);
	for (int i = 0; i < TILES_PER_CHUNKS; i++)
		chunk->tiles[i] = (tile_t*)malloc(sizeof(tile_t)*TILES_PER_CHUNKS);
	return (chunk);
}
