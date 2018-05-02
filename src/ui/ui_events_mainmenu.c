/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** UI events main menu
*/

#include "../../include/rpg.h"

void click_play_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;

	rpg->scene = NULL;
	rpg->state = 3;
	rpg->map = init_map(NULL, SEED);
	rpg->map = generate_map(SEED);
}

void click_map_settings_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;

	rpg->scene = init_mapeditor(rpg);
	rpg->state = 1;
}

void click_exit_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;

	sfRenderWindow_close(rpg->wd);
}
