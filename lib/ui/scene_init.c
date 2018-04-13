/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** scene init
*/

#include "my_uilib.h"

scene_t *create_scene(int nb_buttons, int nb_textboxes, int nb_texts)
{
	scene_t *scene = (scene_t*)malloc(sizeof(scene_t));

	if (scene == NULL)
		return (NULL);
	scene->nb_buttons = nb_buttons;
	scene->nb_textboxes = nb_textboxes;
	scene->nb_texts = nb_texts;
	if (nb_buttons > 0)
		scene->buttons = malloc(sizeof(button_t)*nb_buttons);
	if (nb_textboxes > 0)
		scene->textboxes = malloc(sizeof(textbox_t)*nb_textboxes);
	if (nb_texts > 0)
		scene->texts = malloc(sizeof(text_t)*nb_texts);
	return (scene);
}
