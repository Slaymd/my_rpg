/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map editor settings events
*/

#include "../../include/rpg.h"

void click_vsync_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;
	button_t *vsync = (button_t*)list_get_fromtag(rpg->scene->buttons,\
	"vsync");

	if (vsync->state == 0)
		return;
	set_v_sync(rpg);
}

void click_music_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;
	float vol = sfMusic_getVolume(rpg->music);

	if (vol > 0)
		sfMusic_setVolume(rpg->music, 0);
	else
		sfMusic_setVolume(rpg->music, 100);
}

void click_character_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;

	free_scene(rpg->scene);
	rpg->scene = init_charactereditor(rpg);
	rpg->state = 1;
}
