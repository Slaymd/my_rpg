/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** disp scene
*/

#include "uilib.h"

int	disp_scene(sfRenderWindow *wd, scene_t *scene)
{
	disp_panels(wd, scene->panels);
	disp_texts(wd, scene->labels);
	disp_textboxes(wd, scene->textboxes);
	disp_buttons(wd, scene->buttons);
	disp_tooltips(wd, scene->buttons);
	return (0);
}
