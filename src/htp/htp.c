/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** htp
*/

#include "rpg.h"

htp_tab_t htp_tab[] = {
	{{1, 0, 0, 0, 0, 0}, "You spawn on an infinite map", 3},
	{{1, 0, 0, 0, 1, 1}, "The goal is to save the villagers from the wolf",
	3},
	{{1, 0, 0, 0, 1, 0}, "He's visible only at night and he's verry strong",
	3},
	{{1, 1, 0, 0, 1, 0}, "A fairy is here to help you.", 3},
	{{1, 1, 0, 0, 1, 0}, "In order to kill him you need to earn XP", 3},
	{{1, 1, 1, 1, 0, 0}, "For that you need to kill monsters", 3},
	{{1, 1, 1, 0, 0, 0}, "Some of then will run away", 2},
	{{1, 1, 0, 1, 0, 0}, "And others will kill you", 2},
	{{1, 1, 0, 0, 0, 1},
	"For help you, some villagers will give you info on the wolf", 3},
	{{1, 1, 0, 0, 0, 0}, "Here is our Paypal if you want to help us :", 3},
	{{1, 1, 0, 0, 0, 0}, "paypal.me/RDakiche", 3},
	{{1, 1, 0, 0, 0, 0}, "Good luck & have fun !", 3}
};

void display_htp(htp_t *htp, rpg_t *rpg)
{
	for (int i = 0; i < 6; i++) {
		if (htp_tab[htp->state].disp[i] == 1)
			sfRenderWindow_drawSprite(rpg->wd,
			htp->sprite[i].sprite, NULL);
	}
	cycle_handler(rpg);
	sfText_setOrigin(htp->text, (V2F){(float)my_strlen
	(htp_tab[htp->state].text) / 4 * 26, 15});
	sfText_setString(htp->text, htp_tab[htp->state].text);
	sfRenderWindow_drawText(rpg->wd, htp->text, NULL);
}

void manage_htp(rpg_t *rpg, htp_t *htp)
{
	htp->time = sfClock_getElapsedTime(htp->clock);
	htp->seconds = htp->time.microseconds / 1000000.0;
	sfRenderWindow_setView(rpg->wd, rpg->view->v_screen);
	disp_map(rpg);
	sfRenderWindow_setView(rpg->wd, rpg->view->v_map);
	disp_map(rpg);
	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	display_htp(htp, rpg);
	if (htp->seconds >= htp_tab[htp->state].time) {
		htp->state ++;
		sfClock_restart(htp->clock);
	}
	if (htp->state == 12)
		rpg->state = 3;
}
