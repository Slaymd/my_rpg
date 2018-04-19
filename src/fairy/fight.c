/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** fight
*/

#include "rpg.h"

void fairy_fight(fairy_t *fairy, rpg_t *rpg)
{
	if (rpg->fairy->seconds >= 0.10) {
		if (sfKeyboard_isKeyPressed(sfKeySpace))
			sfMusic_play(fairy->shhh);
		sfClock_restart(rpg->fairy->clock);
	}
}
