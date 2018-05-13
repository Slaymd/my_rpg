/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map editor UI
*/

#include "../../include/rpg.h"

void init_mapeditor_labels(scene_t *scene)
{
	text_t *title = create_text((sfVector2f){50,20}, "Map informations",
	52, sfWhite);
	text_t *seedtitle = create_text((sfVector2f){46,155},
	"seed (only numbers)", 32, (sfColor){245, 246, 250, 255});
	text_t *nametitle = create_text((sfVector2f){46,305},
	"map name (optional)", 32, (sfColor){245, 246, 250, 255});
	text_t *otherstgs = create_text((sfVector2f){WIDTH-269,155},
	"other settings", 32, (sfColor){245, 246, 250, 255});

	set_text_font(title, FONT_UBUMED);
	list_add(&scene->labels, title);
	list_add(&scene->labels, seedtitle);
	list_add(&scene->labels, nametitle);
	list_add(&scene->labels, otherstgs);
}

void init_mapeditor_buttons(rpg_t *rpg, scene_t *scene)
{
	button_t *donebt = create_flat_button((sfIntRect){304,200,80,42},
	(sfColor){72, 126, 176, 255}, (sfColor){251, 197, 49, 255}, "#see");
	button_t *playbt = create_flat_button((sfIntRect){0, HEIGHT-100,WIDTH,
	100}, sfBlack, sfWhite, "Save and play");

	set_button_outline_thickness(playbt, 0);
	set_text_size(playbt->text, 42);
	playbt->action = &click_save_button;
	playbt->params = rpg;
	donebt->tooltip = create_tooltip("Show this seed.", 22);
	donebt->action = &regen_map_from_ui;
	donebt->params = rpg;
	list_add(&scene->buttons, playbt);
	list_add(&scene->buttons, donebt);
}

void init_settings_buttons(rpg_t *rpg, scene_t *scene)
{
	button_t *vsync = create_flat_button((IR){WIDTH-150,220,100,35},\
	sfBlack, sfWhite, "v-sync");

	vsync->states = init_bt_states(vsync, 2);
	vsync->states[1] = (bt_state_t){1, sfTransparent, C_E74C3C, NULL, NULL,\
	NULL, NULL};
	vsync->states[2] = (bt_state_t){1, sfTransparent, C_2ECC71, NULL, NULL,\
	NULL, NULL};
	vsync->action = &click_vsync_button;
	vsync->params = rpg;
	list_add_withtag(&scene->buttons, vsync, "vsync");
}

scene_t *init_mapeditor(rpg_t *rpg)
{
	scene_t *scene = create_scene();
	panel_t *bgpanel = create_flat_panel((sfVector2f){0,0},\
	(sfVector2f){WIDTH,HEIGHT}, sfBlack);
	textbox_t *seedtb = create_textbox((sfIntRect){50,200,250,42},
	sfBlack, sfWhite);
	textbox_t *nametb = create_textbox((sfIntRect){50,350,250,42},
	sfBlack, sfWhite);

	set_panel_opacity(bgpanel, 0.3);
	seedtb->type = ONLY_NUM;
	list_add(&scene->panels, bgpanel);
	list_add_withtag(&scene->textboxes, seedtb, "seed");
	list_add_withtag(&scene->textboxes, nametb, "name");
	init_mapeditor_labels(scene);
	init_mapeditor_buttons(rpg, scene);
	init_settings_buttons(rpg, scene);
	return (scene);
}
