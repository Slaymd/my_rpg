/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "rpg.h"

void display_character(window_t *window, character_t *character, map_t *map)
{
	//disp_sprite_at(window->window, map, character->sprite, character->pos);
	move_character(character, window);
	sfRenderWindow_setView(window->window, window->v_screen);
	sfRenderWindow_drawSprite(window->window, character->sprite, NULL);
	sfRenderWindow_setView(window->window, window->v_map);
	sfRenderWindow_drawSprite(window->window, character->sprite, NULL);
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
}
