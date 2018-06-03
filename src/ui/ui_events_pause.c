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

	free_map(rpg->map);
	rpg->map = init_map(NULL, SEED, 0, rpg->gen_profile);
	free_scene(rpg->scene);
	rpg->scene = init_mainmenu(rpg);
	rpg->state = 0;
}

void click_pause_exit_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;

	free_scene(rpg->scene);
	rpg->scene = NULL;
	sfRenderWindow_close(rpg->wd);
}

int disp_pause_screen(rpg_t *rpg, int ignore_state)
{
	if (rpg->state != 4 && ignore_state != 1)
		return (0);
	sfRenderWindow_setView(rpg->wd, rpg->view->v_screen);
	disp_map(rpg);
	sfRenderWindow_setView(rpg->wd, sfRenderWindow_getDefaultView(rpg->wd));
	disp_scene(rpg->wd, rpg->scene);
	return (1);
}
