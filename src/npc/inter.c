/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** npc
*/

#include "rpg.h"

void display_arrow(rpg_t *rpg, int choices, dial_t dial)
{
	float x;

	if (KeyPressed(sfKeyRight) && rpg->npc->seconds >= 0.3)
		rpg->npc->select ++;
	if (KeyPressed(sfKeyLeft) && rpg->npc->seconds >= 0.3)
		rpg->npc->select --;
	(rpg->npc->select < 0) ? rpg->npc->select = choices - 1 : 0;
	(rpg->npc->select > choices - 1) ? rpg->npc->select = 0 : 0;
	x = WIDTH / (choices + 1) * (rpg->npc->select + 1);
	x -= (rpg->npc->select == 0) ? (float)my_strlen(dial.f_ch) * 10 + 20: 0;
	x -= (rpg->npc->select == 1) ? (float)my_strlen(dial.s_ch) * 10 + 20: 0;
	x -= (rpg->npc->select == 2) ? (float)my_strlen(dial.t_ch) * 10 + 20: 0;
	sfSprite_setPosition(rpg->npc->s_arrow, (V2F){x, HEIGHT / 6 * 5 + 62});
	sfRenderWindow_drawSprite(rpg->wd, rpg->npc->s_arrow, NULL);
}

void display_question(rpg_t *rpg, sfText *text, dial_t dial, int nbr)
{
	char *str = NULL;

	str = (nbr == 1) ? dial.f_ch : str;
	str = (nbr == 2) ? dial.s_ch : str;
	str = (nbr == 3) ? dial.t_ch : str;
	sfText_setString(text, str);
	sfText_setOrigin(text, (V2F){(float)my_strlen(str) / 2 * 20, 0});
	sfText_setPosition(text,
	(V2F){WIDTH / (dial.ask + 1) * nbr, HEIGHT / 6 * 5 + 50});
	sfRenderWindow_drawText(rpg->wd, text, NULL);
}

int check_villager(rpg_t *rpg)
{
	list_t *tmp = rpg->entities;

	for (; tmp != NULL; tmp = tmp->next) {
		if (((entity_t *)tmp->data)->num == 4 && KeyPressed(sfKeyReturn)
		&& rpg->npc->seconds >= 0.3 &&
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

	rpg->npc->time = sfClock_getElapsedTime(rpg->npc->clock);
	rpg->npc->seconds = rpg->npc->time.microseconds / 1000000.0;
	if (talk_villager(rpg) == 1)
		return;
	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	sfRenderWindow_drawRectangleShape(rpg->wd, rpg->npc->box, NULL);
	if (rpg->npc->seconds >= 0.3) {
		if (KeyPressed(sfKeyReturn) || KeyPressed(sfKeyRight) ||
		KeyPressed(sfKeyLeft))
			sfClock_restart(rpg->npc->clock);
		(KeyPressed(sfKeyReturn)) ? next = 1 : 0;
	}
	npc_game(rpg, next);
}
