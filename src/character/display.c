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

void display_ennemy(window_t *window, ennemy_t *ennemy, map_t *map)
{
	if (window->seconds >= 0.10) {
		ennemy->square.left += 100;
		sfSprite_setTextureRect(ennemy->sprite, ennemy->square);
		ennemy->square.left = ennemy->square.left > 260 ? 0 :
		ennemy->square.left + 10;
	}
	disp_sprite_at(window->window, map, ennemy[0].sprite, ennemy[0].pos);
	sfRenderWindow_setView(window->window, window->v_screen);
	disp_sprite_at(window->window, map, ennemy[0].sprite, ennemy[0].pos);
}
