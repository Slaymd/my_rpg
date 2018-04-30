/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init objects
*/

#include "../../../include/rpg.h"

int	free_object(object_t *obj)
{
	//if (obj->sprite != NULL)
	//	sfSprite_destroy(obj->sprite);
	free(obj);
	return (0);
}

char **malloc_txtre_list(char *txts[])
{
	int nb = 0;
	char **array = NULL;

	for (; txts[nb] != NULL; nb++);
	if (nb == 0)
		return (NULL);
	array = (char**)malloc(sizeof(char*)*nb+1);
	for (int i = 0; i < nb; i++) {
		array[i] = my_strcpy(NULL, txts[i]);
		array[i+1] = NULL;
	}
	return (array);
}

object_stats_t *create_obj(char *txts[], float freq, freq_type type, int data)
{
	object_stats_t *stat = (object_stats_t*)malloc(sizeof(object_stats_t));

	stat->txt_paths = malloc_txtre_list(txts);
	stat->freq = freq;
	stat->spawn_type = type;
	stat->data = data;
	return (stat);
}

list_t *init_objects(void)
{
	list_t *objs = NULL;

	list_add(&objs, create_obj((char*[])TXTRE_LIST_LITTLE_STONE, 0.015,
	TILE, TILE_GRASS_ID));
	list_add(&objs, create_obj((char*[])TXTRE_LIST_FLOWERS, 0.05, TILE,
	TILE_GRASS_ID));
	list_add(&objs, create_obj((char*[])TXTRE_LIST_LOG, 0.02,
	TILE, TILE_DARKGRASS_ID));
	list_add(&objs, create_obj((char*[])TXTRE_LIST_LITTLE_BUSH, 0.01, TILE,
	TILE_GRASS_ID));
	list_add(&objs, create_obj((char*[])TXTRE_LIST_BIG_BUSH, 0.005, TILE,
	TILE_GRASS_ID));
	list_add(&objs, create_obj((char*[])TXTRE_LIST_LILY_PAD, 0.015, TILE,
	TILE_WATER_ID));
	list_add(&objs, create_obj((char*[])TXTRE_LIST_WATER_WAVE, 0.015, TILE,
	TILE_WATER_ID));
	list_add(&objs, create_obj((char*[])TXTRE_LIST_WOODEN_HOUSE, 0.001, TILE,
	TILE_GRASS_ID));
	return (objs);
}
