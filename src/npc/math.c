/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** npc
*/

#include "rpg.h"

const dial_t dial_math[] = {
	{"What is the biggest result ?", 2, "2 / 4 + 7", "5 * 1.55", NULL},
	{"What is the smallest result ?", 2, "4 * 9 - 10", "7 * 3.8", NULL},
	{"Is this result positive ? 6.5 * 5 - 32", 2, "Yes", "No", NULL},
	{"Good job !", 0, NULL, NULL, NULL},
	{"That's wrong.", 0, NULL, NULL, NULL},
	{NULL, 0, NULL, NULL, NULL}
};

int manage_npc_math(rpg_t *rpg, npc_t *npc, int *i, int next)
{
	if (*i >= 3 && next == 1)
		return (1);
	if (next == 1 && *i < 3) {
		(*i == 0 && npc->select == 1) ? *i = 3 : 0;
		(*i == 1 && npc->select == 0) ? *i = 3 : 0;
		(*i == 2 && npc->select == 0) ? *i = 3 : 0;
		(*i != 3) ? *i = 4 : 0;
	}
	return (0);
}

void npc_math(rpg_t *rpg, int next)
{
	static int i = -1;

	i = (i == -1) ? rand() % 3 : i;
	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	sfText_setString(rpg->npc->text, dial_math[i].dial);
	sfText_setOrigin(rpg->npc->text,
	(V2F){(float)my_strlen(dial_math[i].dial) / 4 * 20, 0});
	sfText_setPosition(rpg->npc->text,
	(V2F){WIDTH / 2, HEIGHT / 6 * 5 + 10});
	sfRenderWindow_drawText(rpg->wd, rpg->npc->text, NULL);
	if (dial_math[i].ask != 0)
		display_arrow(rpg, dial_math[i].ask, dial_math[i]);
	for (int j = 1; j < dial_math[i].ask + 1; j++)
		display_question(rpg, rpg->npc->text, dial_math[i], j);
	if (manage_npc_math(rpg, rpg->npc, &i, next) == 1) {
		rpg->character->inter = 0;
		i = rand() % 3;
	}
}
