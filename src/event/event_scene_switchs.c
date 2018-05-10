/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** functionnal events
*/

#include "../../include/rpg.h"

int pause_screen_events(rpg_t *rpg, sfEvent event)
{
	if (event.type != sfEvtKeyPressed)
		return (0);
	switch (event.key.code) {
		case sfKeyEscape:
			if (rpg->state == 3) {
				rpg->state = 4;
				rpg->scene = init_pausescreen(rpg);
				return (1);
			} else if (rpg->state == 4) {
				rpg->state = 3;
				free_scene(rpg->scene);
				rpg->scene = NULL;
				return (1);
			}
			break;
		default:
			break;
	}
	return (0);
}
