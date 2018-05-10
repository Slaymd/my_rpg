/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** free map
*/

#include "../../../include/rpg.h"

void free_map(map_t *map)
{
	free_chunks(map);
	free_objects(map);
	free_objects_stat(map);
	free_textures(map);
	free(map);
}
