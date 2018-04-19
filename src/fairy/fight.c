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

void display_shoot(list_shoot_t *shoot, fairy_t *fairy, rpg_t *rpg)
{
	shoot_t *tmp = shoot->first;

	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	while (tmp) {
		sfSprite_setPosition(fairy->s_explo, tmp->pos);
		sfSprite_setTextureRect(fairy->s_explo, tmp->rect);
		sfRenderWindow_drawSprite(rpg->wd, fairy->s_explo, NULL);
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
		if (sfKeyboard_isKeyPressed(sfKeySpace)) {
			new_shoot(fairy->shoot, (V2F){x, y});
			sfMusic_play(fairy->shhh);
		}
		end_shoot(fairy->shoot);
		sfClock_restart(rpg->fairy->clock);
	}
	display_shoot(fairy->shoot, fairy, rpg);
}
