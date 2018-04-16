/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** UI events main menu
*/

#include "../../include/rpg.h"

void click_play_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;

	rpg->state = 1;
}
