// /*
// ** EPITECH PROJECT, 2018
// ** my_rpg_2017
// ** File description:
// ** event_handler
// */
//
// #include "../../include/rpg.h"
//
// int	map_move(sfEvent event, map_t *map)
// {
// 	if (event.type == sfEvtKeyPressed) {
// 		switch (event.key.code) {
// 		case sfKeyLeft:
// 			map->topleft_to_disp.x -= MOVE_SPEED;
// 			return (1);
// 		case sfKeyRight:
// 			map->topleft_to_disp.x += MOVE_SPEED;
// 			return (1);
// 		case sfKeyUp:
// 			map->topleft_to_disp.y -= MOVE_SPEED;
// 			return (1);
// 		case sfKeyDown:
// 			map->topleft_to_disp.y += MOVE_SPEED;
// 			return (1);
// 		default:
// 			return (0);
// 		}
// 	}
// 	return (0);
// }
//
// int	map_event_handler(window_t *window, map_t *map)
// {
// 	int rtn = map_move(window->event, map);
//
// 	return (rtn >= 1 ? 1 : 0);
// }
