/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** fight
*/

#include "rpg.h"

void fairy_fight(fairy_t *fairy)
{
	if (sfKeyboard_isKeyPressed(sfKeySpace))
		sfMusic_play(fairy->shhh);
}
