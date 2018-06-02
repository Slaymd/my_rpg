/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map settings events
*/

#include "../../include/rpg.h"

void click_waterplu_setting(void *data)
{
	rpg_t *rpg = (rpg_t*)data;
	int seed = rpg->map->seed;
	pos_t oldpos = rpg->map->center;

	if (rpg->gen_profile[1] < 0.95)
		rpg->gen_profile[1] += 0.01;
	free_map(rpg->map);
	rpg->map = init_map(NULL, seed, 1, rpg->gen_profile);
	rpg->map->center = oldpos;
}

void click_watermin_setting(void *data)
{
	rpg_t *rpg = (rpg_t*)data;
	int seed = rpg->map->seed;
	pos_t oldpos = rpg->map->center;

	if (rpg->gen_profile[1] > 0)
		rpg->gen_profile[1] -= 0.01;
	free_map(rpg->map);
	rpg->map = init_map(NULL, seed, 1, rpg->gen_profile);
	rpg->map->center = oldpos;
}

void click_sandplu_setting(void *data)
{
	rpg_t *rpg = (rpg_t*)data;
	int seed = rpg->map->seed;
	pos_t oldpos = rpg->map->center;

	if (rpg->gen_profile[3] < rpg->gen_profile[1])
		rpg->gen_profile[3] = rpg->gen_profile[1];
	rpg->gen_profile[3] += 0.01;
	free_map(rpg->map);
	rpg->map = init_map(NULL, seed, 1, rpg->gen_profile);
	rpg->map->center = oldpos;
}

void click_sandmin_setting(void *data)
{
	rpg_t *rpg = (rpg_t*)data;
	int seed = rpg->map->seed;
	pos_t oldpos = rpg->map->center;

	if (rpg->gen_profile[3] > rpg->gen_profile[1])
		rpg->gen_profile[3] -= 0.01;
	free_map(rpg->map);
	rpg->map = init_map(NULL, seed, 1, rpg->gen_profile);
	rpg->map->center = oldpos;
}
