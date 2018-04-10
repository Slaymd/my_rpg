/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** menu
*/

#include "rpg.h"

void create_start_buttons(int nbr, scene_t *scene)
{
	scene->button = malloc(sizeof(button_t) * (nbr + 1));
	scene->button[0] = create_menu_button("img/buttons/start.png",
	(sfVector2f){0.2, 0.5}, (sfVector2f){150, 39}, &play_button);
	scene->button[1] = create_menu_button("img/buttons/quit.png",
	(sfVector2f){0.6, 0.5}, (sfVector2f){100, 50}, &quit_button);
	scene->button[2] = create_menu_button("img/buttons/options.png",
	(sfVector2f){0.8, 0.5}, (sfVector2f){100, 50}, &options_button);
	scene->button[3] = NULL;
}

void create_start_texts(int nbr, scene_t *scene)
{
	scene->text = malloc(sizeof(text_t) * (nbr + 1));
	scene->text[0] = create_menu_text("RPG img/police.ttf", 150,
	(sfVector2f){0.3, 0.1}, sfRed);
	scene->text[1] = NULL;
}

scene_t *create_start_scene(void)
{
	scene_t *scene = create_menu_bg("img/start.jpg");

	create_start_buttons(3, scene);
	create_start_texts(1, scene);
	return (scene);
}
