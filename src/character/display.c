/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "rpg.h"

void display_character(window_t *window, character_t *character)
{
	move_character(character, window);
	sfRenderWindow_setView(window->window, window->v_screen);
	sfRenderWindow_drawSprite(window->window, character->sprite, NULL);
	sfRenderWindow_setView(window->window, window->v_map);
	sfRenderWindow_drawSprite(window->window, character->sprite, NULL);
}
