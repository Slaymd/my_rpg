/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** free objects
*/

#include "../../../include/rpg.h"

void free_object(object_t *object)
{
	if (object->sprite != NULL)
		sfSprite_destroy(object->sprite);
	free(object);
}

void free_object_stat(object_stats_t *stat)
{
	free_strdarray(stat->txt_paths);
	free(stat);
}

void free_objects(map_t *map)
{
	list_t *tmp = NULL;
	object_t *object = NULL;

	for (; map->objects != NULL; map->objects = tmp) {
		tmp = map->objects->next;
		object = (object_t*)map->objects->data;
		free_object(object);
		free(map->objects);
	}
}

void free_objects_stat(map_t *map)
{
	list_t *tmp = NULL;
	object_stats_t *stat = NULL;

	for (; map->obj_stats != NULL; map->obj_stats = tmp) {
		tmp = map->obj_stats->next;
		stat = (object_stats_t*)map->obj_stats->data;
		free_object_stat(stat);
		free(map->obj_stats);
	}
}
