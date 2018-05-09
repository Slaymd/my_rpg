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
		tmp->pos_r.x += tmp->distance.x / 10;
		tmp->pos_r.y += tmp->distance.y / 10;
		(tmp->distance.x >= 0 && tmp->pos_r.x >= tmp->pos_e.x) ?
		tmp->pos_r.x = tmp->pos_e.x : 0;
		(tmp->distance.x < 0 && tmp->pos_r.x <= tmp->pos_e.x) ?
		tmp->pos_r.x = tmp->pos_e.x : 0;
		(tmp->distance.y >= 0 && tmp->pos_r.y >= tmp->pos_e.y) ?
		tmp->pos_r.y = tmp->pos_e.y : 0;
		(tmp->distance.y < 0 && tmp->pos_r.y <= tmp->pos_e.y) ?
		tmp->pos_r.y = tmp->pos_e.y : 0;
		if (tmp->pos_r.x == tmp->pos_e.x &&
		tmp->pos_r.y == tmp->pos_e.y)
			tmp->state = 1;
		if (tmp->state == 1 && tmp->rect.left < 4800)
			tmp->rect.left += 192;
		tmp = tmp->next;
	}
}

void disp_shoot_at(sfRenderWindow *wd, map_t *mp, sfSprite *sprite, pos_t p)
{
	pos_t relat_ref_pos = {p.x - mp->center.x, p.y - mp->center.y, 0};
	sfVector2f px = {relat_ref_pos.x, relat_ref_pos.y};

	if (px.x <= -TILE_SIZE || px.x >= WIDTH)
		return;
	if (px.y <= -TILE_SIZE || px.y >= HEIGHT)
		return;
	sfSprite_setPosition(sprite, px);
	sfRenderWindow_drawSprite(wd, sprite, NULL);
	return;
}

void display_shoot(list_shoot_t *shoot, fairy_t *fairy, rpg_t *rpg)
{
	shoot_t *tmp = shoot->first;

	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	while (tmp) {
		sfSprite_setTextureRect(fairy->s_explo, tmp->rect);
		sfSprite_setRotation(fairy->s_rocket, tmp->angle);
		if (tmp->state == 0)
			disp_shoot_at(rpg->wd, rpg->map, fairy->s_rocket,
			tmp->pos_r);
		else {
<<<<<<< HEAD
			//printf("%f & %f\n", tmp->pos_e.x - WIDTH / 2, tmp->pos_e.y - HEIGHT / 2);
			disp_shoot_at(rpg->wd, rpg->map, fairy->s_explo,
			tmp->pos_e);
			// disp_sprite_at(rpg->wd, rpg->map, fairy->s_explo,
			// (pos_t){tmp->pos_e.x + WIDTH / 2, tmp->pos_e.y + HEIGHT / 2, 0});
=======
			printf("%f & %f\n", tmp->pos_e.x - WIDTH / 2, tmp->pos_e.y - HEIGHT / 2);
			// disp_shoot_at(rpg->wd, rpg->map, fairy->s_explo,
			// tmp->pos_e);
			disp_sprite_at(rpg->wd, rpg->map, fairy->s_explo,
			(pos_t){tmp->pos_e.x - WIDTH / 2, tmp->pos_e.y - HEIGHT / 2, 0});
>>>>>>> 08c3e02cff64cd0734058371c186af5d8176084b
		}
		tmp = tmp->next;
	}
	sfRenderWindow_setView(rpg->wd, rpg->view->v_screen);
}

void fairy_fight(fairy_t *fairy, rpg_t *rpg)
{
	float x = (float)sfMouse_getPositionRenderWindow(rpg->wd).x;
	float y = (float)sfMouse_getPositionRenderWindow(rpg->wd).y;

	if (rpg->fairy->seconds >= 0.05) {
		move_shoot(fairy->shoot);
		if (sfKeyboard_isKeyPressed(sfKeySpace) &&
		rpg->character->stat->mana >= 10) {
			rpg->character->stat->mana -= 10;
			new_shoot(fairy->shoot, (pos_t){x, y, 0}, (pos_t)
			{fairy->pos.x, fairy->pos.y, 0} ,rpg);
			sfMusic_play(fairy->shhh);
		}
		end_shoot(fairy->shoot);
	}
	display_shoot(fairy->shoot, fairy, rpg);
}
