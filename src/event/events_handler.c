/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** event_handler
*/

#include "../../include/rpg.h"

int	close_window(sfRenderWindow *wd, sfEvent event)
{
	if (event.type == sfEvtClosed) {
		sfRenderWindow_close(wd);
		return (1);
	}
	return (0);
}

int	map_move(sfEvent event, map_t *map)
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

int	map_event_handler(window_t *window, map_t *map)
{
	sfEvent event;
	int rtn = 0;

	while (sfRenderWindow_pollEvent(window->window, &event)) {
		rtn += close_window(window->window, event);
		rtn += map_move(event, map);
		window->event = event;
	}
	window->time = sfClock_getElapsedTime(window->clock);
	window->seconds = window->time.microseconds / 1000000.0;
	return (rtn >= 1 ? 1 : 0);
}
