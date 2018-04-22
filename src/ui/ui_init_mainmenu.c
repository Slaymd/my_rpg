/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main menu scene
*/

#include "../../include/rpg.h"

scene_t *init_mainmenu(rpg_t *rpg)
{
	scene_t *scene = create_scene();
	button_t *play = create_flat_button((sfIntRect){100,400,130,75},\
	sfBlack, sfWhite, my_strcpy(NULL, "PLAY"));
	panel_t *bgpanel = create_flat_panel((sfVector2f){0,0},\
	(sfVector2f){WIDTH,HEIGHT}, sfBlack);

	set_panel_opacity(bgpanel, 0.3);
	play->action = &click_play_button;
	play->params = rpg;
	list_add_withtag(&scene->buttons, play, "play_button");
	list_add(&scene->panels, bgpanel);
	return (scene);
}

void disp_mainmenu(rpg_t *rpg)
{
	rpg->map->center.x += rpg->state <= 1 ? MOVE_SPEED/5 : -(MOVE_SPEED/5);
	swap_state_maptravelling(rpg);
	disp_map(rpg);
	disp_scene(rpg->wd, rpg->scene);
}
