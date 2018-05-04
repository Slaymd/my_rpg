/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** hud
*/

#include "rpg.h"

void display_coo(sfText *text, pos_t coo, sfRenderWindow *wd)
{
	char *str;

	sfText_setPosition(text, (V2F){10, 10});
	sfText_setString(text, "x = \ny = ");
	sfRenderWindow_drawText(wd, text, NULL);
	str = my_itoa((int)coo.x);
	sfText_setPosition(text, (V2F){40, 11});
	sfText_setString(text, str);
	sfRenderWindow_drawText(wd, text, NULL);
	free(str);
	str = my_itoa((int)coo.y);
	sfText_setPosition(text, (V2F){40, 34});
	sfText_setString(text, str);
	sfRenderWindow_drawText(wd, text, NULL);
	free(str);
}

void display_hud(rpg_t *rpg)
{
	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	display_coo(rpg->hud->t_coo, rpg->map->center, rpg->wd);
}
