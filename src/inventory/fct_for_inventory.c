/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** bootstrap
*/

#include "rpg.h"

void draw_all(rpg_t *rpg)
{
	sfRenderWindow_clear(rpg->wd, sfBlack);
	disp_map(rpg);
	cycle_handler(rpg);
	sfRenderWindow_drawSprite(rpg->wd, rpg->inv->slot[1]->sitem, NULL);
	sfRenderWindow_drawText(rpg->wd, rpg->inv->stat->attt->text, NULL);
	sfRenderWindow_drawText(rpg->wd, rpg->inv->stat->deft->text, NULL);
	sfRenderWindow_drawText(rpg->wd, rpg->inv->stat->lifet->text, NULL);
	sfRenderWindow_drawText(rpg->wd, rpg->inv->stat->r_lifet->text, NULL);
	sfRenderWindow_drawText(rpg->wd, rpg->inv->stat->r_manat->text, NULL);
	for (int cpt = 2; rpg->inv->slot[cpt] != NULL; cpt++) {
		sfSprite_setPosition(rpg->inv->slot[cpt]->sitem, rpg->inv->slot[cpt]->pitem);
		sfRenderWindow_drawSprite(rpg->wd, rpg->inv->slot[cpt]->sitem, NULL);
	}
	sfRenderWindow_display(rpg->wd);
}

int if_m_in_sprite(sfVector2i pos_m, item_t **slot)
{
	for (int cpt = 2; slot[cpt] != NULL; cpt++) {
		if (pos_m.x > slot[cpt]->pitem.x &&
			pos_m.x < slot[cpt]->pitem.x + 50 &&
			pos_m.y > slot[cpt]->pitem.y &&
			pos_m.y < slot[cpt]->pitem.y + 50)
			return (cpt);
	}
	return (0);
}

void fill_slot(item_t *slot1, item_t *slot2, int i_equip)
{
	slot1->sitem = slot2->sitem;
	slot1->status = slot2->status;
	if (i_equip == 0) {
		slot1->in_body = slot2->in_body;
		slot1->can_e = slot2->can_e;
	}
	slot1->attack = slot2->attack;
	slot1->def = slot2->def;
	slot1->life = slot2->life;
	slot1->r_life = slot2->r_life;
	slot1->r_mana = slot2->r_mana;
	slot1->conso = slot2->conso;
	slot1->stack = slot2->stack;
}

void equip(item_t *slot, item_t **inv)
{
	for (int cpt = 2; inv[cpt] != NULL; cpt++) {
		if (inv[cpt]->in_body == slot->can_e && inv[cpt]->status == 0) {
			fill_slot(inv[0], slot, 1);
			fill_slot(slot, inv[cpt], 1);
			fill_slot(inv[cpt], inv[0], 1);
			inv[cpt]->can_e = 5;
			break;
		}
	}
}

void unequip(item_t *slot, item_t **inv)
{
	for (int cpt = 2; inv[cpt] != NULL; cpt++) {
		if (inv[cpt]->status == 0) {
			fill_slot(inv[0], inv[cpt], 1);
			fill_slot(inv[cpt], slot, 1);
			fill_slot(slot, inv[0], 1);
			inv[cpt]->can_e = slot->in_body;
		}
	}
}
