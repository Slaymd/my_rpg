/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "proto.h"

void display_map(window_t *window)
{
	move_map(window);
	sfRenderWindow_drawSprite(window->window, window->sprite, NULL);
}

void display_character(window_t *window, character_t *character)
{
	if (window->seconds >= 0.10)
		move_character(character);
	sfRenderWindow_drawSprite(window->window, character->sprite, NULL);
}
