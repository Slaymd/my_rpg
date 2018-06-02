/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** ui map settings
*/

#include "../../include/rpg.h"

void click_grassplu_setting(void *data)
{
	rpg_t *rpg = (rpg_t*)data;
	int seed = rpg->map->seed;
	pos_t oldpos = rpg->map->center;

	if (rpg->gen_profile[5] < rpg->gen_profile[3])
		rpg->gen_profile[5] = rpg->gen_profile[3];
	rpg->gen_profile[5] += 0.01;
	free_map(rpg->map);
	rpg->map = init_map(NULL, seed, 1, rpg->gen_profile);
	rpg->map->center = oldpos;
}

void click_grassmin_setting(void *data)
{
	rpg_t *rpg = (rpg_t*)data;
	int seed = rpg->map->seed;
	pos_t oldpos = rpg->map->center;

	if (rpg->gen_profile[5] > rpg->gen_profile[3])
		rpg->gen_profile[5] -= 0.01;
	free_map(rpg->map);
	rpg->map = init_map(NULL, seed, 1, rpg->gen_profile);
	rpg->map->center = oldpos;
}

void init_mapsettings_buttons(rpg_t *rpg, scene_t *scene)
{
	button_t *waterplu = create_flat_button((IR){WIDTH-90, 155, 33, 35},\
	(sfColor){9, 132, 227, 255}, sfBlack, "+");
	button_t *watermin = create_flat_button((IR){WIDTH-140, 155, 33, 35},\
	(sfColor){116, 185, 255, 255}, sfBlack, "-");
	button_t *sandplu = create_flat_button((IR){WIDTH-90, 210, 33, 35},\
	(sfColor){253, 203, 110, 255}, sfBlack, "+");
	button_t *sandmin = create_flat_button((IR){WIDTH-140, 210, 33, 35},\
	(sfColor){255, 234, 167, 255}, sfBlack, "-");
	button_t *grassplu = create_flat_button((IR){WIDTH-90, 265, 33, 35},\
	(sfColor){186, 220, 88, 255}, sfBlack, "+");
	button_t *grassmin = create_flat_button((IR){WIDTH-140, 265, 33, 35},\
	(sfColor){85, 239, 196, 255}, sfBlack, "-");

	set_button_action(waterplu, &click_waterplu_setting, rpg);
	set_button_action(watermin, &click_watermin_setting, rpg);
	set_button_action(sandplu, &click_sandplu_setting, rpg);
	set_button_action(sandmin, &click_sandmin_setting, rpg);
	set_button_action(grassplu, &click_grassplu_setting, rpg);
	set_button_action(grassmin, &click_grassmin_setting, rpg);
	list_add_all(&scene->buttons, 6, MAP_SETTINGS_BUTTONS);
}
