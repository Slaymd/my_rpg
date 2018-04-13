/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** scene free
*/

#include "uilib.h"

void free_panels(list_t *panels)
{
	list_t *next = NULL;

	for (; panels != NULL; panels = next) {
		next = panels->next;
		free_panel((panel_t*)panels->data);
	}
}

void free_labels(list_t *labels)
{
	list_t *next = NULL;

	for (; labels != NULL; labels = next) {
		next = labels->next;
		free_text((text_t*)labels->data);
	}
}

void free_textboxes(list_t *textboxes)
{
	list_t *next = NULL;

	for (; textboxes != NULL; textboxes = next) {
		next = textboxes->next;
		free_textbox((textbox_t*)textboxes->data);
	}
}

void free_buttons(list_t *buttons)
{
	list_t *next = NULL;

	for (; buttons != NULL; buttons = next) {
		next = buttons->next;
		free_button((button_t*)buttons->data);
	}
}

void	free_scene(scene_t *scene)
{
	if (scene == NULL)
		return;
	free_labels(scene->labels);
	free_buttons(scene->buttons);
	free_textboxes(scene->textboxes);
	free_panels(scene->panels);
	free(scene);
}
