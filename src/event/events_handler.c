/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** event_handler
*/

#include "../../include/rpg.h"
#include "../../include/my.h"
#include "../../include/map.h"
#include "../../include/linked_list.h"

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

int	map_event_handler(sfRenderWindow *wd, map_t *map)
{
	sfEvent	event;
	int		rtn = 0;

	while (sfRenderWindow_pollEvent(wd, &event)) {
		rtn += close_window(wd, event);
		rtn += map_move(event, map);
	}
	return (rtn >= 1 ? 1 : 0);
}
