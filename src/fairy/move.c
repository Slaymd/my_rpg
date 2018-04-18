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
	} else
		fairy->ec.x = 0;
	if (ep.y == 0) {
		fairy->pos.y += fairy->ep.y;
		fairy->ep.y *= 0.7;
	} else
		fairy->ec.y = 0;
	fairy->pos.x += fairy->ec.x;
	fairy->pos.y += fairy->ec.y;
}

void physic_fairy_move(fairy_t *fairy, sfEvent event)
{
	V2F ep = (V2F){0, 0};

	if (event.key.code == sfKeyUp && KeyPressed(sfKeyUp)) {
		if (fairy->pos.y < HEIGHT / 2 + MOVE_F_Y)
			fairy->ec.y += 1;
		else {
			fairy->ep.y -= (fairy->ep.y > -5) ? 1 : 0;
			ep.y = 1;
		}
	} else if (event.key.code == sfKeyDown && KeyPressed(sfKeyDown)) {
		if (fairy->pos.y > HEIGHT / 2 - MOVE_F_Y)
			fairy->ec.y -= 1;
		else {
			fairy->ep.y += (fairy->ep.y < 5) ? 1 : 0;
			ep.y = 1;
		}
	} else if (event.key.code == sfKeyRight && KeyPressed(sfKeyRight)) {
		if (fairy->pos.x > WIDTH / 2 - MOVE_F_X)
			fairy->ec.x -= 1;
		else {
			fairy->ep.x += (fairy->ep.x < 5) ? 1 : 0;
			ep.x = 1;
		}
	} else if (event.key.code == sfKeyLeft && KeyPressed(sfKeyLeft)) {
		if (fairy->pos.x < WIDTH / 2 + MOVE_F_X)
			fairy->ec.x += 1;
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
	if (rpg->fairy->seconds >= 0.05) {
		// random_fairy_move(fairy);
		sfClock_restart(rpg->fairy->clock);
	}
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
