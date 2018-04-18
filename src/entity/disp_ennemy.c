/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "rpg.h"

void display_ennemy(rpg_t *rpg, entity_t *ent, map_t *map, int count)
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
	sfRenderWindow_setView(rpg->wd, rpg->view->v_map);
	disp_rect_at(rpg->wd, map, ent->rect, ent->pos);
	disp_sprite_at(rpg->wd, map, ent->sprite, ent->pos);
	sfRenderWindow_setView(rpg->wd, rpg->view->v_screen);
	disp_rect_at(rpg->wd, map, ent->rect, ent->pos);
	disp_sprite_at(rpg->wd, map, ent->sprite, ent->pos);
}
