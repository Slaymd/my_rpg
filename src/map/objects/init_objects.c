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
	object_stats_t objst[] = {{(char*[])TXTRE_LIST_LITTLE_STONE, 0.015, 1,
	TILE_GRASS_ID, TILE},{(char*[])TXTRE_LIST_FLOWERS, 0.05, 2, TILE_GRASS_ID
	, TILE},{(char*[])TXTRE_LIST_LOG, 0.02, 3, TILE_DARKGRASS_ID, TILE},
	{(char*[])TXTRE_LIST_LITTLE_BUSH, 0.01, 4, TILE_GRASS_ID, TILE},
	{(char*[])TXTRE_LIST_BIG_BUSH, 0.005, 5, TILE_GRASS_ID, TILE},
	{(char*[])TXTRE_LIST_LILY_PAD, 0.015, 6, TILE_WATER_ID, TILE},
	{(char*[])TXTRE_LIST_WATER_WAVE, 0.015, 7, TILE_WATER_ID, TILE},
	{(char*[])TXTRE_LIST_WOODEN_HOUSE, 0.001, 8, TILE_GRASS_ID, TILE},
	{(char*[])TXTRE_LIST_VILLAGE, 0.0005, 9, TILE_GRASS_ID, TILE},
	{NULL, 0, 0, 0, TILE}};

	for (int i = 0; objst[i].txt_paths != NULL; i++) {
		list_add(&objs, create_obj(objst[i].txt_paths, objst[i].freq,
		objst[i].spawn_type, objst[i].data));
	}
	return (objs);
}
