/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** npc
*/

#include "rpg.h"

const dial_t dial_game[] = {
	{"Do you want to play a game ?", 2, "OK!", "No", NULL},
	{"Well played !", 0, NULL, NULL, NULL},
	{"LOOOOOSEEEEEER", 0, NULL, NULL, NULL},
	{NULL, 0, NULL, NULL, NULL}
};

int manage_npc_game(rpg_t *rpg, npc_t *npc, int *i, int next)
{
	if (*i >= 1 && next == 1)
		return (1);
	if (*i == 0 && npc->select == 1 && next == 1)
		return (1);
	(*i == 0 && npc->select == 0 && next == 1) ?
	(play_matchstick(rpg, npc->ms) == 1) ? *i = *i + 1 : 0 : 0;
	(next == 1) ? *i = *i + 1 : 0;
	if (!dial_game[*i].dial)
		return (1);
	return (0);
}

void npc_game(rpg_t *rpg, int next)
{
	static int i = 0;

	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	sfText_setString(rpg->npc->text, dial_game[i].dial);
	sfText_setOrigin(rpg->npc->text,
	(V2F){(float)my_strlen(dial_game[i].dial) / 4 * 20, 0});
	sfText_setPosition(rpg->npc->text,
	(V2F){WIDTH / 2, HEIGHT / 6 * 5 + 10});
	sfRenderWindow_drawText(rpg->wd, rpg->npc->text, NULL);
	if (dial_game[i].ask != 0)
		display_arrow(rpg, dial_game[i].ask, dial_game[i]);
	for (int j = 1; j < dial_game[i].ask + 1; j++)
		display_question(rpg, rpg->npc->text, dial_game[i], j);
	if (manage_npc_game(rpg, rpg->npc, &i, next) == 1) {
		rpg->character->inter = 0;
		i = 0;
	}
}
