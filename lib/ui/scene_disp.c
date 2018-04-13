/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** disp scene
*/

#include "my_uilib.h"

int	disp_scene(sfRenderWindow *wd, scene_t *scene)
{
	if (scene->nb_texts > 0)
		disp_texts(wd, scene->texts, scene->nb_texts);
	if (scene->nb_textboxes > 0)
		disp_textboxes(wd, scene->textboxes, scene->nb_textboxes);
	if (scene->nb_buttons > 0) {
		disp_buttons(wd, scene->buttons, scene->nb_buttons);
		disp_tooltips(wd, scene->buttons, scene->nb_buttons);
	}
	return (0);
}
