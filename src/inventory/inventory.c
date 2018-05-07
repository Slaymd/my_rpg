/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** bootstrap
*/

#include "rpg.h"

int equip_item(sfVector2i pos_m, rpg_t *rpg, int fill)
{
	int num_slot1 = 0;
	int num_slot2 = 0;

	if (sfKeyboard_isKeyPressed(sfKeyE)) {
		num_slot1 = if_m_in_sprite(pos_m, rpg->slot);
		if (rpg->slot[num_slot1]->status == 1 && rpg->slot[num_slot1]->can_e > 0)
			equip(rpg->slot[num_slot1], rpg->slot);
		fill = 0;
	}
	if (sfKeyboard_isKeyPressed(sfKeyR)) {
		num_slot2 = if_m_in_sprite(pos_m, rpg->slot);
		if (rpg->slot[num_slot2]->status == 1 && rpg->slot[num_slot2]->in_body > 0)
			unequip(rpg->slot[num_slot2], rpg->slot);
		fill = 0;
	}
	return (fill);
}

int inv_info(sfVector2i pos_m, rpg_t *rpg)
{
	int quit = 0;
	int num_slot = 0;

	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		quit = 1;

	if (sfKeyboard_isKeyPressed(sfKeyI)) {
		num_slot = if_m_in_sprite(pos_m, rpg->slot);
		printf("num = %d, mouse = %d,%d\n", num_slot, pos_m.x, pos_m.y);
		printf("%d %d %d attack = %d def = %d\n\n", rpg->slot[num_slot]->in_body, rpg->slot[num_slot]->can_e, rpg->slot[num_slot]->status, rpg->slot[num_slot]->attack, rpg->slot[num_slot]->def);
	}
	return (quit);
}

int exchange_slot(rpg_t *rpg, sfVector2i pos_m, int quit, int fill)
{
	static int num_slot1 = 0;
	int num_slot2 = 0;

	if (rpg->event.type == sfEvtMouseButtonPressed && quit == 0 && fill == 0) {
		num_slot1 = if_m_in_sprite(pos_m, rpg->slot);
		if (rpg->slot[num_slot1]->status == 1) {
			fill_slot(rpg->slot[0], rpg->slot[num_slot1], 0);
			fill = 1;
		}
	}
	else if (rpg->event.type == sfEvtMouseButtonPressed && quit == 0 && fill == 1) {
		rpg->slot[num_slot1]->in_body = 0;
		num_slot2 = if_m_in_sprite(pos_m, rpg->slot);
		if (rpg->slot[num_slot1]->status == 1) {
			fill_slot(rpg->slot[num_slot1], rpg->slot[num_slot2], 0);
			fill_slot(rpg->slot[num_slot2], rpg->slot[0], 0);
			fill = 0;
		}
	}
	return (fill);
}

void inventory(rpg_t *rpg)
{
	int quit = 0;
	int fill = 0;
	sfView *view = sfView_createFromRect((sfFloatRect){0.,0.,800.,600.});
	sfVector2i pos_m;

	printf("inventaire\n");
	sfRenderWindow_setView(rpg->wd, view);
	while (quit == 0) {
		while (sfRenderWindow_pollEvent(rpg->wd, &rpg->event)) {
			draw_all(rpg);
			pos_m = sfMouse_getPosition((sfWindow*) rpg->wd);
			quit = inv_info(pos_m, rpg);
			fill = equip_item(pos_m, rpg, fill);
			fill = exchange_slot(rpg, pos_m, quit, fill);
		}
	}
	printf("on sort\n");
}
