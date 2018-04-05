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

void display_ennemy(window_t *window, entity_t *ent, map_t *map)
{
	if (window->seconds >= 0.10) {
		ent->square.left += 100;
		sfSprite_setTextureRect(ent->sprite, ent->square);
		ent->square.left = ent->square.left > 260 ? 0 :
		ent->square.left + 10;
	}
	disp_sprite_at(window->window, map, ent[0].sprite, ent[0].pos);
	sfRenderWindow_setView(window->window, window->v_screen);
	disp_sprite_at(window->window, map, ent[0].sprite, ent[0].pos);
}
