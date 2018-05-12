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

	if (KeyPressed(sfKeyRight) && rpg->npc->seconds >= 0.5)
		rpg->npc->select ++;
	if (KeyPressed(sfKeyLeft) && rpg->npc->seconds >= 0.5)
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
