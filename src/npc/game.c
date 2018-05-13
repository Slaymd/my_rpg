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
	if (next == 1) {
		if (*i >= 1 || (*i == 0 && npc->select == 1))
			return (1);
		if (*i == 0 && npc->select == 0) {
			*i = (play_matchstick(rpg, npc->ms) == 1) ? 2 : 1;
			sfClock_restart(rpg->npc->clock);
		}
	}
	return (0);
}

void npc_game(rpg_t *rpg, int next, int *choice)
{
	static int i = 0;
	static int leave = 0;

	next = (leave == 0) ? 0 : next;
	leave = 1;
	display_dial(rpg, dial_game[i]);
	if (dial_game[i].ask != 0)
		display_arrow(rpg, dial_game[i].ask, dial_game[i]);
	for (int j = 1; j < dial_game[i].ask + 1; j++)
		display_question(rpg, rpg->npc->text, dial_game[i], j);
	if (manage_npc_game(rpg, rpg->npc, &i, next) == 1) {
		sfClock_restart(rpg->npc->clock);
		rpg->character->inter = 0;
		*choice = rand() % 3;
		i = 0;
		leave = 0;
	}
}
