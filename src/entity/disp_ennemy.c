/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "rpg.h"

void display_ennemy(window_t *window, entity_t *ent, map_t *map, int count)
{

	if (count == 5 && ent->mirror == 0) {
		ent->square.left = ent->square.left + ent->movement > ent->lvl ?
		0 : ent->square.left + ent->movement;
		sfSprite_setTextureRect(ent->sprite, ent->square);
	} else if (count == 5 && ent->mirror == 1) {
		ent->square.left = ent->square.left + ent->movement > ent->lvl ?
		ent->max : ent->square.left + ent->movement;
		sfSprite_setTextureRect(ent->sprite, ent->square);
	}
	sfRenderWindow_setView(window->window, window->v_map);
	//disp_rect_at(window->window, map, ent->rect, ent->pos);
	disp_sprite_at(window->window, map, ent->sprite, ent->pos);
	sfRenderWindow_setView(window->window, window->v_screen);
	//disp_rect_at(window->window, map, ent->rect, ent->pos);
	disp_sprite_at(window->window, map, ent->sprite, ent->pos);
}
