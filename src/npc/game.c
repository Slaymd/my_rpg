/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** npc
*/

#include "rpg.h"

dial_t dial_game[] = {{"Do you want to play a game for an item ?", 2, "OK!", "No", NULL}, {NULL}};

void play_chifoumi(void)
{
	// int choice = rand() % 3;
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
	for (int j = 1; j < dial_game[i].ask + 1; j++) {
		display_question(rpg, rpg->npc->text, dial_game[i], j);
	}
	if (next == 1)
		i++;
	if (!dial_game[i].dial) {
		i = 0;
		rpg->character->inter = 0;
	}
}
