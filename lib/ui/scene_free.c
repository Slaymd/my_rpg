/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** scene free
*/

#include "my_uilib.h"

void free_array_of_texts(text_t *texts, int nb)
{
	for (int i = 0; i < nb; i++) {
		free_text(&texts[i]);
	}
}

void free_array_of_buttons(button_t *buttons, int nb)
{
	for (int i = 0; i < nb; i++) {
		free_button(&buttons[i]);
	}
}

void free_array_of_textboxes(textbox_t *textboxes, int nb)
{
	for (int i = 0; i < nb; i++) {
		free_textbox(&textboxes[i]);
	}
}

void	free_scene(scene_t *scene)
{
	if (scene == NULL)
		return;
	if (scene->texts != NULL)
		free_array_of_texts(scene->texts, scene->nb_texts);
	if (scene->buttons != NULL)
		free_array_of_buttons(scene->buttons, scene->nb_buttons);
	if (scene->textboxes != NULL)
		free_array_of_textboxes(scene->textboxes, scene->nb_textboxes);
	free(scene);
}
