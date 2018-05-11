/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** bootstrap
*/

#include "rpg.h"

void equip_item(inv_t *inv, item_t **slot, rpg_t *rpg)
{
	int num1 = 0;
	int num2 = 0;

	if (sfKeyboard_isKeyPressed(sfKeyE)) {
		inv->pos_m = sfMouse_getPosition((sfWindow*)rpg->wd);
		num1 = if_m_in_sprite(inv->pos_m, slot);
		if (slot[num1]->conso > 0 && slot[num1]->stack > 0)
			consom(slot[num1], rpg);
		else if (slot[num1]->status == 1 && slot[num1]->can_e > 0)
			equip(slot[num1], slot);
		inv->fill = 0;
	}
	if (sfKeyboard_isKeyPressed(sfKeyR)) {
		inv->pos_m = sfMouse_getPosition((sfWindow*)rpg->wd);
		num2 = if_m_in_sprite(inv->pos_m, slot);
		if (slot[num2]->status == 1 && slot[num2]->in_body > 0)
			unequip(slot[num2], slot);
		inv->fill = 0;
	}
}

void drop(inv_t *inv, item_t **slot, rpg_t *rpg)
{
	int num = 0;

	if (sfKeyboard_isKeyPressed(sfKeyD)) {
		inv->pos_m = sfMouse_getPosition((sfWindow*)rpg->wd);
		num = if_m_in_sprite(inv->pos_m, slot);
		if (slot[num]->in_body == 0) {
			slot[num]->can_e = 0;
			slot[num]->status = 0;
			slot[num]->attack = 0;
			slot[num]->def = 0;
			slot[num]->life = 0;
			slot[num]->r_life = 0;
			slot[num]->r_mana = 0;
			slot[num]->conso = 0;
			slot[num]->stack = 0;
			slot[num]->titem = sfTexture_createFromFile
			("assets/inventory/empty.png", NULL);
			sfSprite_setTexture (slot[num]->sitem, slot[num]->titem, sfTrue);
		}
		inv->fill = 0;
	}
}
//
// void inv_info(inv_t *inv, item_t **slot, sfRenderWindow *wd)
// {
// 	int num_slot = 0;
//
// 	if (sfKeyboard_isKeyPressed(sfKeyI)) {
// 		inv->pos_m = sfMouse_getPosition((sfWindow*) wd);
// 		num_slot = if_m_in_sprite(inv->pos_m, slot);
// 		printf("num = %d, mouse = %d,%d\n", num_slot, inv->pos_m.x, inv->pos_m.y);
// 		printf("%d %d %d attack = %d def = %d %d\n\n", slot[num_slot]->in_body, slot[num_slot]->can_e, slot[num_slot]->status, slot[num_slot]->attack, slot[num_slot]->def, slot[num_slot]->conso);
// 	}
// }

void exchange_slot(rpg_t *rpg, inv_t *inv)
{
	static int slot1 = 0;
	int slot2 = 0;

	inv->pos_m = sfMouse_getPosition((sfWindow*) rpg->wd);
	if (inv->quit == 0 && inv->fill == 0) {
		slot1 = if_m_in_sprite(inv->pos_m, inv->slot);
		if (inv->slot[slot1]->status == 1) {
			fill_slot(inv->slot[0], inv->slot[slot1], 0);
			inv->fill = 1;
		}
	}
	else if (inv->quit == 0 && inv->fill == 1) {
		inv->slot[slot1]->in_body = 0;
		slot2 = if_m_in_sprite(inv->pos_m, rpg->inv->slot);
		if (inv->slot[slot1]->status == 1) {
			fill_slot(inv->slot[slot1], inv->slot[slot2], 0);
			fill_slot(inv->slot[slot2], inv->slot[0], 0);
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
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		rpg->inv->quit = 1;
	else if (rpg->inv->seconds > 0.08) {
		equip_item(rpg->inv, rpg->inv->slot, rpg);
		drop(rpg->inv, rpg->inv->slot, rpg);
		sfClock_restart(rpg->inv->clocki);
		// inv_info(rpg->inv, rpg->inv->slot, rpg->wd);
	}
	else if (rpg->event.type == sfEvtMouseButtonPressed)
		exchange_slot(rpg, rpg->inv);
}

void inventory(rpg_t *rpg)
{
	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);

	draw_all(rpg);
	while (rpg->inv->quit == 0) {
		while (sfRenderWindow_pollEvent(rpg->wd, &rpg->event)) {
			inv_event(rpg);
			recup_info(rpg->inv, rpg->character->stat);
		}
	}
	rpg->inv->quit = 0;
}
