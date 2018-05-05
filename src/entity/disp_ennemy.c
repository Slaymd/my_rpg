/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "rpg.h"

void reinit_var(rpg_t *rpg, entity_t *ent, map_t *map)
{
	float hp = 50 * (ent->hp / 100.0);

	sfRenderWindow_setView(rpg->wd, rpg->view->v_map);
	disp_rect_at(rpg->wd, map, ent->rect, ent->pos);
	disp_sprite_at(rpg->wd, map, ent->sprite, ent->pos);
	sfRenderWindow_setView(rpg->wd, rpg->view->v_screen);
	disp_rect_at(rpg->wd, map, ent->rect, ent->pos);
	disp_sprite_at(rpg->wd, map, ent->sprite, ent->pos);
	sfRectangleShape_setSize(ent->hp_bar, (V2F){hp, 5});
	sfRenderWindow_setView(rpg->wd, rpg->view->v_screen);
	sfRectangleShape_setOrigin(ent->hp_bar, (V2F){ent->movement / 4, 2.5});
	disp_rect_at(rpg->wd, map, ent->hp_bar, ent->pos);
}

void display_ennemy(rpg_t *rpg, entity_t *ent, map_t *map, int count)
{
	if (count == 5 && ent->mirror == 0) {
		ent->square.left = ent->square.left + ent->movement >= ent->lvl
		? 0 : ent->square.left + ent->movement;
		sfSprite_setTextureRect(ent->sprite, ent->square);
	} else if (count == 5 && ent->mirror == 1) {
		ent->square.left = ent->square.left + ent->movement >= ent->lvl
		? ent->max : ent->square.left + ent->movement;
		sfSprite_setTextureRect(ent->sprite, ent->square);
	} else if (ent->mirror == 2 && count == 5) {
		ent->square.left = ent->square.left + ent->movement >= 2500 ?
		2500 : ent->square.left + 177;
		sfSprite_setTextureRect(ent->sprite, ent->square);
	}
	reinit_var(rpg, ent, map);
}
