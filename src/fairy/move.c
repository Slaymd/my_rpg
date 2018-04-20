/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "rpg.h"

void random_fairy_move(fairy_t *fairy)
{
	fairy->pos.x += (float)(rand() % 11 - 5) / 2;
	fairy->pos.y += (float)(rand() % 11 - 5) / 2;
}

void apply_physic_move(fairy_t *fairy, V2F ep)
{
	if (ep.x == 0) {
		fairy->pos.x += fairy->ep.x;
		fairy->ep.x *= 0.7;
	} if (ep.y == 0) {
		fairy->pos.y += fairy->ep.y;
		fairy->ep.y *= 0.7;
	}
	(ep.x != 0) ? fairy->ec.x = 0 : 0;
	(ep.y != 0) ? fairy->ec.y = 0 : 0;
	fairy->pos.x += fairy->ec.x;
	fairy->pos.y += fairy->ec.y;
}

void physic_fairy_move(fairy_t *fairy, sfEvent event)
{
	V2F ep = (V2F){0, 0};

	if (KeyPressed(sfKeyUp) && event.key.code == sfKeyUp) {
		if (fairy->pos.y < HEIGHT / 2 + MOVE_F_Y)
			fairy->ec.y += 3;
		else {
			fairy->ep.y -= (fairy->ep.y > -5) ? 1 : 0;
			ep.y = 1;
		}
	} else if (KeyPressed(sfKeyDown) && event.key.code == sfKeyDown) {
		if (fairy->pos.y > HEIGHT / 2 - MOVE_F_Y)
			fairy->ec.y -= 3;
		else {
			fairy->ep.y += (fairy->ep.y < 5) ? 1 : 0;
			ep.y = 1;
		}
	} else if (KeyPressed(sfKeyRight) && event.key.code == sfKeyRight) {
		if (fairy->pos.x > WIDTH / 2 - MOVE_F_X)
			fairy->ec.x -= 3;
		else {
			fairy->ep.x += (fairy->ep.x < 5) ? 1 : 0;
			ep.x = 1;
		}
	} else if (KeyPressed(sfKeyLeft) && event.key.code == sfKeyLeft) {
		if (fairy->pos.x < WIDTH / 2 + MOVE_F_X)
			fairy->ec.x += 3;
		else {
			fairy->ep.x -= (fairy->ep.x > -5) ? 1 : 0;
			ep.x = 1;
		}
	} else {
		fairy->ec.x *= 0.75;
		fairy->ec.y *= 0.75;
	}
	apply_physic_move(fairy, ep);
}

void move_fairy(fairy_t *fairy, rpg_t *rpg, sfEvent event)
{
	rpg = rpg;
	// random_fairy_move(fairy);
	physic_fairy_move(fairy, event);
	(fairy->pos.x > WIDTH / 2 + MOVE_F_X) ?
	fairy->pos.x = WIDTH / 2 + MOVE_F_X : 0;
	(fairy->pos.x < WIDTH / 2 - MOVE_F_X) ?
	fairy->pos.x = WIDTH / 2 - MOVE_F_X : 0;
	(fairy->pos.y > HEIGHT / 2 + MOVE_F_Y) ?
	fairy->pos.y = HEIGHT / 2 + MOVE_F_Y: 0;
	(fairy->pos.y < HEIGHT / 2 - MOVE_F_Y) ?
	fairy->pos.y = HEIGHT / 2 - MOVE_F_Y : 0;
	sfSprite_setPosition(fairy->sprite, fairy->pos);
}
