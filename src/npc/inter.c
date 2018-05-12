/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** npc
*/

#include "rpg.h"

int check_villager(rpg_t *rpg)
{
	list_t *tmp = rpg->entities;

	for (; tmp != NULL; tmp = tmp->next) {
		if (((entity_t *)tmp->data)->num == 4 && KeyPressed(sfKeyReturn)
		&& rpg->npc->seconds >= 0.5 &&
		detect_villager((entity_t *){tmp->data}, rpg->map) == 1) {
			rpg->character->inter = 1;
			sfClock_restart(rpg->npc->clock);
			rpg->npc->seconds = 0;
			return (1);
		}
	}
	return (0);
}

int talk_villager(rpg_t *rpg)
{
	if (rpg->character->inter == 0) {
		if (check_villager(rpg) == 1)
			return (0);
		return (1);
	}
	return (0);
}

void manage_inter(rpg_t *rpg)
{
	int next = 0;
	static int choice = 0;

	rpg->npc->time = sfClock_getElapsedTime(rpg->npc->clock);
	rpg->npc->seconds = rpg->npc->time.microseconds / 1000000.0;
	if (talk_villager(rpg) == 1) {
		return;
	}
	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	sfRenderWindow_drawRectangleShape(rpg->wd, rpg->npc->box, NULL);
	if (rpg->npc->seconds >= 0.5) {
		if (KeyPressed(sfKeyReturn) || KeyPressed(sfKeyRight) ||
		KeyPressed(sfKeyLeft)) {
			sfClock_restart(rpg->npc->clock);
		}
		next = (KeyPressed(sfKeyReturn)) ? 1 : 0;
	}
	(choice == 0) ? npc_math(rpg, next, &choice) : 0;
	(choice == 1) ?	npc_game(rpg, next, &choice) : 0;
	(choice == 2) ?	npc_fear(rpg, next, &choice) : 0;
}
