/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** button
*/

#include "rpg.h"

void start_button(rpg_t *rpg)
{
	rpg->menu->state = 0;
}

void options_button(rpg_t *rpg)
{
	rpg->menu->state = 1;
}
