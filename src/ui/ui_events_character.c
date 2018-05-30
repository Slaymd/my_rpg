/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** ui events character page
*/

#include "../../include/rpg.h"

void click_character_swap_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;
	button_t *button = (button_t*)list_get_fromtag(rpg->scene->buttons,\
	"skin");
	panel_t *img = (panel_t*)list_get_fromtag(rpg->scene->panels, "img");

	switch (button->state) {
		case 1:
		set_panel_image(img, "assets/character/sacha-blue.png");
		break;
		case 2:
		set_panel_image(img, "assets/character/sacha-green.png");
		break;
		case 3:
		set_panel_image(img, "assets/character/sacha-pink.png");
		break;
		default:
		set_panel_image(img, "assets/character/sacha-red.png");
		break;
	}
}

void click_character_done_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;
	panel_t *img = (panel_t*)list_get_fromtag(rpg->scene->panels, "img");

	rpg->character->texture = sfTexture_copy(img->texture);
	set_character(rpg->character, WIDTH/2, HEIGHT/2);
	/*sfSprite_setTexture(rpg->character->sprite,\
	sfTexture_copy(img->texture), sfFalse);*/
	free_scene(rpg->scene);
	rpg->scene = rpg->last_scene;
	rpg->last_scene = NULL;
}
