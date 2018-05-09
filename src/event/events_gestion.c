/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** event
*/

#include "../../include/rpg.h"

int map_move_left(map_t *map)
{
	float player_x = map->center.x - 0.5;
	float player_y = map->center.y;
	pos_t player_pos = {player_x - MOVE_SPEED, player_y, 0};
	int canmove = can_move_here(map, player_pos);

	if (canmove)
		map->center.x -= MOVE_SPEED;
	return (0);
}

int map_move_right(map_t *map)
{
	float player_x = map->center.x + 0.5;
	float player_y = map->center.y;
	pos_t player_pos = {player_x + MOVE_SPEED, player_y, 0};
	int canmove = can_move_here(map, player_pos);

	if (canmove)
		map->center.x += MOVE_SPEED;
	return (0);
}

int map_move_up(map_t *map)
{
	float player_x = map->center.x;
	float player_y = map->center.y - 0.7;
	pos_t player_pos = {player_x, player_y - MOVE_SPEED, 0};
	int canmove = can_move_here(map, player_pos);

	if (canmove)
		map->center.y -= MOVE_SPEED;
	return (0);
}

int map_move_down(map_t *map)
{
	float player_x = map->center.x;
	float player_y = map->center.y + 0.3;
	pos_t player_pos = {player_x, player_y + MOVE_SPEED, 0};
	int canmove = can_move_here(map, player_pos);

	if (canmove)
		map->center.y += MOVE_SPEED;
	return (0);
}

int map_move(sfEvent event, map_t *map)
{
	(void)event;
	if (KeyPressed(sfKeyUp)) {
		map_move_up(map);
		return (1);
	} if (KeyPressed(sfKeyDown)) {
		map_move_down(map);
		return (1);
	} if (KeyPressed(sfKeyRight)) {
		map_move_right(map);
		return (1);
	} if (KeyPressed(sfKeyLeft)) {
		map_move_left(map);
		return (1);
	}
	return (0);
}
