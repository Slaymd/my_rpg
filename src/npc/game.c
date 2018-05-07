/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** npc
*/

#include "rpg.h"

char *dial_game[] = {"Do you want to play a game for an item ?", NULL};

void play_chifoumi(void)
{
	// int choice = rand() % 3;
}

void npc_game(rpg_t *rpg)
{
	int i = 0;

	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	sfText_setString(rpg->npc->text, dial_game[i]);
	sfText_setOrigin(rpg->npc->text,
	(V2F){(float)my_strlen(dial_game[i]) / 4 * 20, 0});
	sfText_setPosition(rpg->npc->text,
	(V2F){WIDTH / 2, HEIGHT / 6 * 5 + 10});
	sfRenderWindow_drawText(rpg->wd, rpg->npc->text, NULL);
}
