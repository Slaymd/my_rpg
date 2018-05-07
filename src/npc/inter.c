/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** npc
*/

#include "rpg.h"

void manage_inter(rpg_t *rpg)
{
	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	sfRenderWindow_drawRectangleShape(rpg->wd, rpg->npc->box, NULL);
}
