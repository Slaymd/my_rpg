/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** button
*/

#include "rpg.h"

void quit_button(rpg_t *rpg)
{
	sfRenderWindow_close(rpg->window->window);
}

void play_button(rpg_t *rpg)
{
	rpg->state = 1;
}
