/*
** EPITECH PROJECT, 2017
** match
** File description:
** bonus
*/

#include "rpg.h"

void play_match(rpg_t *rpg, match_t *match, stick_t *stick)
{
	if (match->seconds > 0.05 && stick->turn % 2 == 0)
		player_play(match, stick);
	else if (match->mode == 1 && match->seconds > 0.75 &&
	stick->turn % 2 != 0)
		ai_play(match, stick);
	calcul_match(rpg, match, stick);
}

int play_matchstick(rpg_t *rpg)
{
	match_t *match = init_match();
	stick_t *stick = fill_stick();

	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	while (sfRenderWindow_isOpen(rpg->wd) && my_end(stick) == 0) {
		matchstick_gestion(rpg, match);
		play_match(rpg, match, stick);
		sfRenderWindow_display(rpg->wd);
	}
	return (stick->turn % 2);
}
