/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** UI init pause screen
*/

#include "../../include/rpg.h"

scene_t *init_pausescreen(rpg_t *rpg)
{
	scene_t *scene = create_scene();
	panel_t *bgpanel = create_flat_panel((sfVector2f){0,0},\
	(sfVector2f){WIDTH,HEIGHT}, sfBlack);

	(void)rpg;
	set_panel_opacity(bgpanel, 0.3);
	list_add(&scene->panels, scene);
	return (scene);
}
