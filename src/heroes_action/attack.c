/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "rpg.h"

void verif_action(rpg_t *rpg)
{
	if (sfKeyboard_isKeyPressed(sfKeySpace)) {
		printf("%s\n", "attack");
	}
}
