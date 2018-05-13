/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main menu scene
*/

#include "../../include/rpg.h"

int	init_mainmenu_buttons(rpg_t *rpg, scene_t *scene)
{
	button_t *play = create_flat_button((sfIntRect){100,325,160,75},\
	sfBlack, sfWhite, "PLAY");
	button_t *stgs = create_flat_button((sfIntRect){100,485,160,35},\
	sfBlack, sfWhite, " settings");
	button_t *exi = create_flat_button((sfIntRect){810,485,33,35},\
	C_8C7AE6, C_F5F6FA, "x");

	set_text_position(stgs->text, (sfVector2f){115,485});
	set_text_position(play->text, (sfVector2f){126,325});
	play->action = &click_play_button;
	play->params = rpg;
	stgs->action = &click_map_settings_button;
	stgs->params = rpg;
	stgs->tooltip = create_tooltip("Edit map options", 22);
	exi->action = &click_exit_button;
	exi->params = rpg;
	list_add(&scene->buttons, play);
	list_add(&scene->buttons, stgs);
	list_add(&scene->buttons, exi);
	return (0);
}

scene_t *init_mainmenu(rpg_t *rpg)
{
	scene_t *scene = create_scene();
	panel_t *bgpanel = create_flat_panel((sfVector2f){0,0},\
	(sfVector2f){WIDTH,HEIGHT}, sfBlack);
	button_t *hplay = create_flat_button((sfIntRect){100,425,160,35},\
	sfBlack, sfWhite, "how to play");

	hplay->action = &click_how_to_play_button;
	hplay->params = rpg;
	set_panel_opacity(bgpanel, 0.3);
	init_mainmenu_buttons(rpg, scene);
	list_add(&scene->panels, bgpanel);
	list_add(&scene->buttons, hplay);
	return (scene);
}

void disp_mainmenu(rpg_t *rpg)
{
	rpg->map->center.x += rpg->state <= 1 ? MOVE_SPEED/5 : -(MOVE_SPEED/5);
	swap_state_maptravelling(rpg);
	disp_map(rpg);
	disp_scene(rpg->wd, rpg->scene);
}
