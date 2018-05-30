/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** character customization init
*/

#include "../../include/rpg.h"

void init_charactereditor_choicebutton(scene_t *scene, rpg_t *rpg)
{
	button_t *skinchoice = create_flat_button((IR){325, 285, 130, 45},\
	(sfColor){255, 107, 107, 255}, sfBlack, "red");

	skinchoice->states = init_bt_states(skinchoice, 3);
	skinchoice->states[1] = (bt_state_t){1, (sfColor){72, 219, 251, 255},\
	sfTransparent, "blue", NULL, NULL, NULL};
	skinchoice->states[2] = (bt_state_t){1, (sfColor){29, 209, 161, 255},\
	sfTransparent, "green", NULL, NULL, NULL};
	skinchoice->states[3] = (bt_state_t){1, (sfColor){255, 159, 243, 255},\
	sfTransparent, "pink", NULL, NULL, NULL};
	set_button_action(skinchoice, &click_character_swap_button, rpg);
	list_add_withtag(&scene->buttons, skinchoice, "skin");
}

void init_charactereditor_labels(scene_t *scene)
{
	text_t *title = create_text((sfVector2f){50,20}, "Character",\
	52, sfWhite);

	set_text_font(title, FONT_UBUMED);
	list_add(&scene->labels, title);
}

scene_t *init_charactereditor(rpg_t *rpg)
{
	scene_t *scene = create_scene();
	panel_t *bgpanel = create_flat_panel((sfVector2f){0,0},\
	(sfVector2f){WIDTH,HEIGHT}, sfBlack);
	panel_t *character_img = create_image_panel((V2F){100,175},\
	"assets/character/sacha-red.png");
	button_t *donebt = create_flat_button((IR){50,HEIGHT-100,87,45},\
	sfBlack, sfWhite, "Done");

	set_panel_opacity(bgpanel, 0.3);
	set_panel_image_rect(character_img, (IR){0,0,68,72});
	set_panel_image_scale(character_img, 3);
	set_button_action(donebt, &click_character_done_button, rpg);
	init_charactereditor_labels(scene);
	init_charactereditor_choicebutton(scene, rpg);
	list_add_withtag(&scene->panels, character_img, "img");
	list_add(&scene->panels, bgpanel);
	list_add(&scene->buttons, donebt);
	return (scene);
}
