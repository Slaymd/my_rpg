/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** chunk gen
*/

#include "../../../include/rpg.h"

int	chunk_entities_gen_ostrich(map_t *map, pos_t apos)
{
	entity_t *ent = NULL;

	if (rand_time(0, 7) != 1)
		return (0);
	ent = create_entity(map, OSTRICH);
	ent->pos = generate_pos_near(map, apos, 5);
	list_append(&map->entities, ent);
	return (0);
}

int	chunk_entities_gen_ogre(map_t *map, pos_t apos)
{
	entity_t *ent = NULL;

	if (rand_time(0, 7) != 1)
		return (0);
	ent = create_entity(map, STONE_OGRE);
	ent->pos = generate_pos_near(map, apos, 5);
	list_append(&map->entities, ent);
	return (0);
}

int	chunk_entities_gen_villager(map_t *map, pos_t apos)
{
	entity_t *ent = NULL;

	if (rand_time(0, 8) != 1)
		return (0);
	ent = create_entity(map, VILLAGER);
	ent->pos = generate_pos_near(map, apos, 5);
	list_append(&map->entities, ent);
	return (0);
}

int	chunk_entities_gen_lycan(map_t *map, pos_t apos)
{
	entity_t *ent = NULL;

	if (rand_time(0, 50) != 1)
		return (0);
	ent = create_entity(map, LYCANTHROPE);
	ent->pos = generate_pos_near(map, apos, 5);
	list_append(&map->entities, ent);
	return (0);
}

chunk_t	*chunk_gen(map_t *map, pos_t pos)
{
	chunk_t	*chunk = init_chunk(pos);
	pos_t	tpos = {0, 0, 0};
	pos_t	apos = {0, 0, 0};

	for (int y = 0; y < TILES_PER_CHUNKS; y++) {
		for (int x = 0; x < TILES_PER_CHUNKS; x++) {
			tpos = (pos_t){(float)x, (float)y, 0.0};
			apos = get_absolute_pos(chunk, tpos);
			chunk->tiles[y][x] = generate_tile_at(map, apos, tpos);
		}
	}
	chunk_entities_gen_ostrich(map, apos);
	chunk_entities_gen_ogre(map, apos);
	chunk_entities_gen_villager(map, apos);
	chunk_entities_gen_villager2(map, apos);
	chunk_entities_gen_villager3(map, apos);
	chunk_entities_gen_lycan(map, apos);
	return (chunk);
}
