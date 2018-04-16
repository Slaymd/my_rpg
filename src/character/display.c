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
	display_minimap(character->sprite, window);
}
