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

void kinetic_fairy_move(fairy_t *fairy)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp))
		fairy->kinetic.y += 1;
	if (sfKeyboard_isKeyPressed(sfKeyDown))
		fairy->kinetic.y -= 1;
	if (sfKeyboard_isKeyPressed(sfKeyRight))
		fairy->kinetic.x -= 1;
	if (sfKeyboard_isKeyPressed(sfKeyLeft))
		fairy->kinetic.x += 1;
	fairy->pos.x += fairy->kinetic.x;
	fairy->pos.y += fairy->kinetic.y;
	fairy->kinetic.x *= 0.9;
	fairy->kinetic.y *= 0.9;
}

void move_fairy(fairy_t *fairy, rpg_t *rpg)
{
	rpg = rpg;
	if (rpg->fairy->seconds >= 0.05) {
		random_fairy_move(fairy);
		sfClock_restart(rpg->fairy->clock);
	}
	kinetic_fairy_move(fairy);
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
