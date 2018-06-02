/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** ui events character page
*/

#include "../../include/rpg.h"

void set_panel_skin(character_t *character, panel_t *img)
{
	char *skinpath = my_strcpy(NULL, "assets/character/");

	skinpath = my_strcat(skinpath, character->skin_sex);
	skinpath = my_strcat(skinpath, "-");
	skinpath = my_strcat(skinpath, character->skin_color);
	skinpath = my_strcat(skinpath, ".png");
	set_panel_image(img, skinpath);
}

void click_character_swap_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;
	button_t *button = (button_t*)list_get_fromtag(rpg->scene->buttons,\
	"skin");
	panel_t *img = (panel_t*)list_get_fromtag(rpg->scene->panels, "img");

	switch (button->state) {
		case 1:
		rpg->character->skin_color = "blue";
		break;
		case 2:
		rpg->character->skin_color = "green";
		break;
		case 3:
		rpg->character->skin_color = "pink";
		break;
		default:
		rpg->character->skin_color = "red";
		break;
	}
	set_panel_skin(rpg->character, img);
}

void click_character_sex_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;
	button_t *button = (button_t*)list_get_fromtag(rpg->scene->buttons,\
	"sex");
	panel_t *img = (panel_t*)list_get_fromtag(rpg->scene->panels, "img");

	switch(button->state) {
		case 1:
			rpg->character->skin_sex = "jessie";
			break;
		default:
			rpg->character->skin_sex = "sacha";
			break;
	}
	set_panel_skin(rpg->character, img);
}

void click_character_done_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;
	panel_t *img = (panel_t*)list_get_fromtag(rpg->scene->panels, "img");

	rpg->character->texture = sfTexture_copy(img->texture);
	set_character(rpg->character, WIDTH/2, HEIGHT/2);
	free_scene(rpg->scene);
	rpg->scene = rpg->last_scene;
	rpg->last_scene = NULL;
}
