/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** UI init pause screen
*/

#include "../../include/rpg.h"

int init_pausescreen_buttons(rpg_t *rpg, scene_t *scene)
{
	button_t *resume = create_flat_button((IR){60, HEIGHT-150, 130, 50},\
	sfBlack, sfWhite, "resume");
	button_t *menu = create_flat_button((IR){60, HEIGHT-80, 130, 30},\
	sfBlack, sfWhite, "main menu");
	button_t *quit = create_flat_button((IR){WIDTH-190, HEIGHT-80, 130,\
	30}, sfBlack, (sfColor){162, 155, 254, 255}, "quit game");

	set_text_position(quit->text, (V2F){WIDTH-175, HEIGHT-80});
	set_text_position(menu->text, (V2F){75, HEIGHT-80});
	resume->action = &click_pause_resume_button;
	resume->params = rpg;
	menu->action = &click_pause_menu_button;
	menu->params = rpg;
	quit->action = &click_pause_exit_button;
	quit->params = rpg;
	list_add(&scene->buttons, resume);
	list_add(&scene->buttons, menu);
	list_add(&scene->buttons, quit);
	return (0);
}

int init_pausescreen_labels(scene_t *scene)
{
	text_t *logo = create_text((V2F){50,50}, T_LOGO, 32, sfWhite);
	text_t *paused = create_text((V2F){50,70}, "PAUSED", 100, sfWhite);

	set_text_font(logo, FONT_UBUREG);
	list_add(&scene->labels, logo);
	list_add(&scene->labels, paused);
	return (0);
}

scene_t *init_pausescreen(rpg_t *rpg)
{
	scene_t *scene = create_scene();
	panel_t *bgpanel = create_flat_panel((V2F){0,0}, (V2F){WIDTH,HEIGHT},\
	sfBlack);

	(void)rpg;
	set_panel_opacity(bgpanel, 0.4);
	init_pausescreen_labels(scene);
	init_pausescreen_buttons(rpg, scene);
	list_add(&scene->panels, bgpanel);
	return (scene);
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
