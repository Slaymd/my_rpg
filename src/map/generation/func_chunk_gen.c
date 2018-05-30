/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** chunk gen
*/

#include "../../../include/rpg.h"

int	chunk_entities_gen_villager2(map_t *map, pos_t apos)
{
	entity_t *ent = NULL;

	if (rand_time(0, 8) != 1)
		return (0);
	ent = create_entity(map, VILLAGER2);
	ent->pos = generate_pos_near(map, apos, 5);
	while(!can_be_placed_here(map, ent->sprite, ent->pos))
		ent->pos = generate_pos_near(map, ent->pos, 5);
	list_append(&map->entities, ent);
	return (0);
}

int	chunk_entities_gen_villager3(map_t *map, pos_t apos)
{
	entity_t *ent = NULL;

	if (rand_time(0, 8) != 1)
		return (0);
	ent = create_entity(map, VILLAGER3);
	ent->pos = generate_pos_near(map, apos, 5);
	while(!can_be_placed_here(map, ent->sprite, ent->pos))
		ent->pos = generate_pos_near(map, ent->pos, 5);
	list_append(&map->entities, ent);
	return (0);
}
