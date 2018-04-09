/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** menu
*/

#include "rpg.h"

void create_options_buttons(int nbr, scene_t *scene)
{
	scene->button = malloc(sizeof(button_t) * (nbr + 1));
	scene->button[0] = create_menu_button("img/buttons/start.png",
	(sfVector2f){0.5, 0.5}, (sfVector2f){100, 50}, &start_button);
	scene->button[1] = create_menu_button("img/buttons/quit.png",
	(sfVector2f){0.2, 0.4}, (sfVector2f){100, 50}, &quit_button);
	scene->button[2] = NULL;
}

void create_options_texts(int nbr, scene_t *scene)
{
	scene->text = malloc(sizeof(text_t) * (nbr + 1));
	scene->text[0] = create_menu_text("OPTIONS img/police.ttf", 150,
	(sfVector2f){0.5, 0.2}, sfRed);
	scene->text[1] = create_menu_text("paypal.me/RDakiche img/police.ttf", 100,
	(sfVector2f){0.1, 0.4}, sfBlue);
	scene->text[2] = NULL;
}

scene_t *create_options_scene(void)
{
	scene_t *scene = create_menu_bg("img/start.jpg");

	create_options_buttons(2, scene);
	create_options_texts(2, scene);
	return (scene);
}
