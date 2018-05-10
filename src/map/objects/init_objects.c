/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init objects
*/

#include "../../../include/rpg.h"

object_stats_t *create_obj(object_stats_t *alp, char *txts)
{
	object_stats_t *stat = (object_stats_t*)malloc(sizeof(object_stats_t));

	if (stat == NULL)
		return (NULL);
	stat->txt_paths = my_str_split(txts, ':');
	stat->freq = alp->freq;
	stat->spawn_type = alp->spawn_type;
	stat->data = alp->data;
	stat->type = alp->type;
	stat->object_id = alp->object_id;
	return (stat);
}

list_t *init_objects(void)
{
	list_t *objs = NULL;
	object_stats_t objst[] = {{NULL, 0.015, 1, TILE_GRASS_ID, 2, 0},{NULL,
	0.05, 2, TILE_GRASS_ID, 2, 0},{NULL, 0.02, 3, TILE_DARKGRASS_ID, 2, 1},
	{NULL, 0.01, 4, TILE_GRASS_ID, 2, 0},{NULL, 0.005, 5, TILE_GRASS_ID, 2,
	1},{NULL, 0.015, 6, TILE_WATER_ID, 2, 1},{NULL, 0.015, 7,
	TILE_WATER_ID, 2, 1},{NULL, 0.001, 8, TILE_GRASS_ID, 2, 1},{NULL,
	0.0005, 9, TILE_GRASS_ID, 2, 1},{NULL, -1, 0, 0, 2, 1}};
	char *txts[] = {LIST_LITTLE_STONE, LIST_FLOWERS, LIST_LOG,
		LIST_LITTLE_BUSH, LIST_BIG_BUSH, LIST_LILY_PAD, LIST_WATER_WAVE,
		LIST_WOODEN_HOUSE, LIST_VILLAGE, NULL};

	for (int i = 0; objst[i].freq > 0; i++)
		list_add(&objs, create_obj(&objst[i], txts[i]));
	return (objs);
}
