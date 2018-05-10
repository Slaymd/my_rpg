/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** pause events
*/

#include "../../include/rpg.h"

void click_pause_resume_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;

	free_scene(rpg->scene);
	rpg->scene = NULL;
	rpg->state = 3;
}

void click_pause_menu_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;

	rpg->map = init_map(NULL, SEED);
	rpg->state = 0;
}

void click_pause_exit_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;

	sfRenderWindow_close(rpg->wd);
}
