/*
** EPITECH PROJECT, 2017
** match
** File description:
** bonus
*/

#include "rpg.h"

void play_match(rpg_t *rpg, match_t *match, stick_t *stick)
{
	if (match->seconds > 0.075 && stick->turn % 2 == 0)
		player_play(match, stick);
	else if (match->mode == 1 && match->seconds > 0.75 &&
	stick->turn % 2 != 0)
		ai_play(match, stick);
	calcul_match(rpg, match, stick);
}

void reset_stick(stick_t *stick)
{
	stick->lines = 4;
	stick->len = stick->lines * 2 - 1;
	stick->max = 3;
	stick->turn = 0;
	for (int i = 0; i < stick->lines; i++)
		stick->line[i] = 1 + i * 2;
}

int play_matchstick(rpg_t *rpg, ms_t *ms)
{
	reset_stick(ms->stick);
	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	while (sfRenderWindow_isOpen(rpg->wd) && my_end(ms->stick) == 0) {
		matchstick_gestion(rpg, ms->match);
		play_match(rpg, ms->match, ms->stick);
		sfRenderWindow_display(rpg->wd);
	}
	return (ms->stick->turn % 2);
}
