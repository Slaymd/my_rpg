/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** event
*/

#include "rpg.h"

int map_move(sfEvent event, map_t *map)
{
	if (event.type == sfEvtKeyPressed) {
		switch (event.key.code) {
		case sfKeyLeft:
			map->topleft_to_disp.x -= MOVE_SPEED;
			return (1);
		case sfKeyRight:
			map->topleft_to_disp.x += MOVE_SPEED;
			return (1);
		case sfKeyUp:
			map->topleft_to_disp.y -= MOVE_SPEED;
			return (1);
		case sfKeyDown:
			map->topleft_to_disp.y += MOVE_SPEED;
			return (1);
		default:
			return (0);
		}
	}
	return (0);
}

void event_gestion(window_t *window, map_t *map)
{
	// sfEvent event;
        //
	// while (sfRenderWindow_pollEvent(window->window, &event)) {
	// 	if (event.type == sfEvtClosed)
	// 		sfRenderWindow_close(window->window);
	// 	window->event = event;
	// }
	// map_move(window->event, map);
	// window->time = sfClock_getElapsedTime(window->clock);
	// window->seconds = window->time.microseconds / 1000000.0;
}
