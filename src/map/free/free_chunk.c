/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** free chunks
*/

#include "../../../include/rpg.h"

void free_chunk(chunk_t *chunk)
{
	for (int y = 0; chunk->tiles != NULL && y < TILES_PER_CHUNKS; y++) {
		free(chunk->tiles[y]);
	}
	free(chunk->tiles);
	free(chunk);
}

void free_chunks(map_t *map)
{
	list_t *tmp = NULL;
	chunk_t *chunk = NULL;

	for (; map->chunks != NULL; map->chunks = tmp) {
		tmp = map->chunks->next;
		chunk = (chunk_t*)map->chunks->data;
		free_chunk(chunk);
		free(map->chunks);
	}
}
