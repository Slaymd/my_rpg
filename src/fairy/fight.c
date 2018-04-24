/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** fight
*/

#include "rpg.h"

void move_shoot(list_shoot_t *shoot)
{
	shoot_t *tmp = shoot->first;

	while (tmp) {
		if (tmp->rect.left < 4800)
			tmp->rect.left += 192;
		tmp = tmp->next;
	}
}

int disp_shoot_at(sfRenderWindow *wd, map_t *mp, sfSprite *sp, pos_t p)
{
	pos_t relat_ref_pos = {p.x-mp->topleft_to_disp.x,
	p.y-mp->topleft_to_disp.y, 0};
	sfVector2f px = {relat_ref_pos.x, relat_ref_pos.y};
	sfSprite *sprite = NULL;
	if (px.x <= -TILE_SIZE || px.x >= WIDTH || sp == NULL)
		return (-1);
	if (px.y <= -TILE_SIZE || px.y >= HEIGHT)
		return (-1);
	sprite = sfSprite_copy(sp);
	sfSprite_setPosition(sprite, px);
	sfRenderWindow_drawSprite(wd, sprite, NULL);
	return (0);
}

void display_shoot(list_shoot_t *shoot, fairy_t *fairy, rpg_t *rpg)
{
	shoot_t *tmp = shoot->first;

	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	while (tmp) {
		sfSprite_setTextureRect(fairy->s_explo, tmp->rect);
		disp_shoot_at(rpg->wd, rpg->map, fairy->s_explo, tmp->pos);
		tmp = tmp->next;
	}
	sfRenderWindow_setView(rpg->wd, rpg->view->v_screen);
}

void is_it_hit(rpg_t *rpg, pos_t pos)
{
	list_t *tmp = rpg->entities;

	float x = pos.x;
	float y = pos.y;

	for (; tmp != NULL; tmp = tmp->next) {
		if (x >= ((entity_t *)tmp->data)->pos.x - 3 && x <=
		((entity_t *)tmp->data)->pos.x + 3 && y >=
		((entity_t *)tmp->data)->pos.y - 3 && y <=
		((entity_t *)tmp->data)->pos.y + 3) {
		}
	}
}

void fairy_fight(fairy_t *fairy, rpg_t *rpg)
{
	float x = (float)sfMouse_getPositionRenderWindow(rpg->wd).x;
	float y = (float)sfMouse_getPositionRenderWindow(rpg->wd).y;

	if (rpg->fairy->seconds >= 0.10) {
		move_shoot(fairy->shoot);
		if (sfKeyboard_isKeyPressed(sfKeySpace)) {
			new_shoot(fairy->shoot, (pos_t){x, y, 0}, rpg);
			is_it_hit(rpg, rpg->fairy->shoot->first->pos);
			sfMusic_play(fairy->shhh);
		}
		end_shoot(fairy->shoot);
	}
	display_shoot(fairy->shoot, fairy, rpg);
}
