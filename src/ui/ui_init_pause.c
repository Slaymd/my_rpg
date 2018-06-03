/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** UI init pause screen
*/

#include "../../include/rpg.h"

int init_pause_settings_buttons(rpg_t *rpg, scene_t *scene)
{
	button_t *vsync = create_flat_button((IR){WIDTH-145,190,100,35},\
	sfBlack, sfWhite, "v-sync");
	button_t *music = create_flat_button((IR){WIDTH-130,245,85,35},\
	sfBlack, C_2ECC71, "music");

	vsync->states = init_bt_states(vsync, 2);
	vsync->states[1] = (bt_state_t){1, sfTransparent, C_E74C3C, NULL, NULL,\
	NULL, NULL};
	vsync->states[2] = (bt_state_t){1, sfTransparent, C_2ECC71, NULL, NULL,\
	NULL, NULL};
	music->states = init_bt_states(music, 1);
	music->states[1] = (bt_state_t){1, sfTransparent, C_E74C3C, NULL, NULL,\
	NULL, NULL};
	if (sfMusic_getVolume(rpg->music) == 0)
		set_button_state(music, 1);
	set_button_action(vsync, &click_vsync_button, rpg);
	set_button_action(music, &click_music_button, rpg);
	sfText_setColor(music->text->text, sfWhite);
	list_add_withtag(&scene->buttons, vsync, "vsync");
	list_add_withtag(&scene->buttons, music, "music");
}

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
	set_button_action(resume, &click_pause_resume_button, rpg);
	set_button_action(menu, &click_pause_menu_button, rpg);
	set_button_action(quit, &click_pause_exit_button, rpg);
	list_add_all(&scene->buttons, 3, resume, menu, quit);
	return (0);
}

int init_pausescreen_labels(scene_t *scene)
{
	text_t *logo = create_text((V2F){50,50}, T_LOGO, 32, sfWhite);
	text_t *paused = create_text((V2F){50,70}, "PAUSED", 100, sfWhite);
	text_t *stgs = create_text((V2F){WIDTH-150, 130},\
	"settings", 28, sfWhite);

	set_text_font(logo, FONT_UBUREG);
	list_add(&scene->labels, logo);
	list_add(&scene->labels, paused);
	list_add(&scene->labels, stgs);
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
	init_pause_settings_buttons(rpg, scene);
	list_add(&scene->panels, bgpanel);
	return (scene);
}
