/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** bootstrap
*/

#include "rpg.h"

void equip_item(inv_t *inv, item_t **slot)
{
	int num_slot1 = 0;
	int num_slot2 = 0;

	if (sfKeyboard_isKeyPressed(sfKeyE)) {
		num_slot1 = if_m_in_sprite(inv->pos_m, slot);
		if (slot[num_slot1]->conso > 0 && slot[num_slot1]->stack > 0)
			consom(slot[num_slot1]);
		else if (slot[num_slot1]->status == 1 && slot[num_slot1]->can_e > 0)
			equip(slot[num_slot1], slot);
		inv->fill = 0;
	}
	if (sfKeyboard_isKeyPressed(sfKeyR)) {
		num_slot2 = if_m_in_sprite(inv->pos_m, slot);
		if (slot[num_slot2]->status == 1 && slot[num_slot2]->in_body > 0)
			unequip(slot[num_slot2], slot);
		inv->fill = 0;
	}
}

void inv_info(inv_t *inv, item_t **slot)
{
	int num_slot = 0;

	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		inv->quit = 1;

	if (sfKeyboard_isKeyPressed(sfKeyI)) {
		num_slot = if_m_in_sprite(inv->pos_m, slot);
		printf("num = %d, mouse = %d,%d\n", num_slot, inv->pos_m.x, inv->pos_m.y);
		printf("%d %d %d attack = %d def = %d %d\n\n", slot[num_slot]->in_body, slot[num_slot]->can_e, slot[num_slot]->status, slot[num_slot]->attack, slot[num_slot]->def, slot[num_slot]->conso);
	}
}

void exchange_slot(rpg_t *rpg, inv_t *inv)
{
	static int num_slot1 = 0;
	int num_slot2 = 0;

	if (rpg->event.type == sfEvtMouseButtonPressed && inv->quit == 0 && inv->fill == 0) {
		num_slot1 = if_m_in_sprite(inv->pos_m, inv->slot);
		if (inv->slot[num_slot1]->status == 1) {
			fill_slot(inv->slot[0], inv->slot[num_slot1], 0);
			inv->fill = 1;
		}
	}
	else if (rpg->event.type == sfEvtMouseButtonPressed && inv->quit == 0 && inv->fill == 1) {
		inv->slot[num_slot1]->in_body = 0;
		num_slot2 = if_m_in_sprite(inv->pos_m, rpg->inv->slot);
		if (inv->slot[num_slot1]->status == 1) {
			fill_slot(inv->slot[num_slot1], inv->slot[num_slot2], 0);
			fill_slot(inv->slot[num_slot2], inv->slot[0], 0);
			inv->fill = 0;
		}
	}
}

void inv_event(rpg_t *rpg)
{
	draw_all(rpg);
	rpg->inv->timei = sfClock_getElapsedTime(rpg->inv->clocki);
	rpg->inv->seconds = rpg->inv->timei.microseconds / 1000000.0;
	if (rpg->event.type == sfEvtClosed) {
		sfRenderWindow_close(rpg->wd);
		rpg->inv->quit = 1;
		return;
	}
	rpg->inv->pos_m = sfMouse_getPosition((sfWindow*) rpg->wd);
	if (rpg->inv->seconds > 0.05) {
		equip_item(rpg->inv, rpg->inv->slot);
		sfClock_restart(rpg->inv->clocki);
	}
	exchange_slot(rpg, rpg->inv);
	inv_info(rpg->inv, rpg->inv->slot);
}

void inventory(rpg_t *rpg)
{
	sfView *view = sfView_createFromRect((sfFloatRect){0.,0.,800.,600.});

	printf("inventaire\n");
	sfRenderWindow_setView(rpg->wd, view);
	draw_all(rpg);
	while (rpg->inv->quit == 0) {
		while (sfRenderWindow_pollEvent(rpg->wd, &rpg->event)) {
			inv_event(rpg);
			recup_info(rpg->inv);
		}
	}
	rpg->inv->quit = 0;
	printf("on sort\n");
}
