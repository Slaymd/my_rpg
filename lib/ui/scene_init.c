/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** scene init
*/

#include "uilib.h"

scene_t *create_scene(void)
{
	scene_t *scene = (scene_t*)malloc(sizeof(scene_t));

	if (scene == NULL)
		return (NULL);
	scene->buttons = NULL;
	scene->labels = NULL;
	scene->textboxes = NULL;
	return (scene);
}
