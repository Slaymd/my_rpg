/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** npc
*/

#include "rpg.h"

const dial_t dial_fear[] = {
	{"A werewolf killed my sister, will you help me ?", 2, "Of course",
	"No", NULL},
	{"I heared a werewolf last night, will you kill him ?", 2, "I will try",
	"No, I'm scared too", NULL},
	{"Thank you !", 0, NULL, NULL, NULL},
	{"Oh.. I guess I'll die next night.", 0, NULL, NULL, NULL},
	{NULL, 0, NULL, NULL, NULL}
};

int manage_npc_fear(npc_t *npc, int *i, int next)
{
	if (next == 1) {
		if (*i >= 2)
			return (1);
		*i = (npc->select == 0) ? 2 : 3;
	}
	return (0);
}

void npc_fear(rpg_t *rpg, int next, int *choice)
{
	static int i = 0;
	static int leave = 0;

	next = (leave == 0) ? 0 : next;
	leave = 1;
	display_dial(rpg, dial_fear[i]);
	if (dial_fear[i].ask != 0)
		display_arrow(rpg, dial_fear[i].ask, dial_fear[i]);
	for (int j = 1; j < dial_fear[i].ask + 1; j++)
		display_question(rpg, rpg->npc->text, dial_fear[i], j);
	if (manage_npc_fear(rpg->npc, &i, next) == 1) {
		sfClock_restart(rpg->npc->clock);
		rpg->character->inter = 0;
		*choice = rand() % 3;
		i = rand() % 2;
		leave = 0;
	}
}
