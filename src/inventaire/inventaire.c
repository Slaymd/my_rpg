/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** bootstrap
*/

#include "rpg.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <stdio.h>

void draw_all(rpg_t *rpg)
{
	sfRenderWindow_clear(rpg->wd, sfBlack);
	disp_map(rpg);
	sfRenderWindow_drawSprite(rpg->wd, rpg->slot[1]->sitem, NULL);
	for (int cpt = 2; rpg->slot[cpt] != NULL; cpt++) {
		sfSprite_setPosition(rpg->slot[cpt]->sitem, rpg->slot[cpt]->pitem);
		sfRenderWindow_drawSprite(rpg->wd, rpg->slot[cpt]->sitem, NULL);
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

void exchange_slot(item_t *slot1, item_t *slot2, int i_equip)
{
	slot1->sitem = slot2->sitem;
	slot1->status = slot2->status;
	if (i_equip == 0) {
		slot1->in_body = slot2->in_body;
		slot1->can_e = slot2->can_e;
	}
	slot1->attack = slot2->attack;
	slot1->def = slot2->def;
}

void equip(item_t *slot, item_t **inv)
{
	for (int cpt = 2; inv[cpt] != NULL; cpt++) {
		if (inv[cpt]->in_body == slot->can_e && inv[cpt]->status == 0) {
			exchange_slot(inv[0], slot, 1);
			exchange_slot(slot, inv[cpt], 1);
			exchange_slot(inv[cpt], inv[0], 1);
			inv[cpt]->can_e = 5;
			break;
		}
	}
}

void unequip(item_t *slot, item_t **inv)
{
	for (int cpt = 2; inv[cpt] != NULL; cpt++) {
		if (inv[cpt]->status == 0) {
			exchange_slot(inv[0], inv[cpt], 1);
			exchange_slot(inv[cpt], slot, 1);
			exchange_slot(slot, inv[0], 1);
			inv[cpt]->can_e = slot->in_body;
		}
	}
}

void inventory(rpg_t *rpg)
{
	int isok = 0;
	int num_slot1 = 0;
	int num_slot2 = 0;
	int fill = 0;
	sfView *view = sfView_createFromRect((sfFloatRect){0.,0.,800.,600.});
	sfVector2i pos_m;

	printf("inventaire\n");
	sfRenderWindow_setView(rpg->wd, view);
	while (isok == 0) {
		while (sfRenderWindow_pollEvent(rpg->wd, &rpg->event)) {
			draw_all(rpg);
			pos_m = sfMouse_getPosition((sfWindow*) rpg->wd);
			if (sfKeyboard_isKeyPressed(sfKeyEscape))
				isok = 1;
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
			if (sfKeyboard_isKeyPressed(sfKeyI)) {
				num_slot2 = if_m_in_sprite(pos_m, rpg->slot);
				printf("num = %d, mouse = %d,%d\n", num_slot2, pos_m.x, pos_m.y);
				printf("%d %d %d attack = %d def = %d\n\n", rpg->slot[num_slot2]->in_body, rpg->slot[num_slot2]->can_e, rpg->slot[num_slot2]->status, rpg->slot[num_slot2]->attack, rpg->slot[num_slot2]->def);
			}
			if (rpg->event.type == sfEvtMouseButtonPressed && isok == 0 && fill == 0) {
				num_slot1 = if_m_in_sprite(pos_m, rpg->slot);
				if (rpg->slot[num_slot1]->status == 1) {
					exchange_slot(rpg->slot[0], rpg->slot[num_slot1], 0);
					fill = 1;
				}
			}
			else if (rpg->event.type == sfEvtMouseButtonPressed && isok == 0 && fill == 1) {
				rpg->slot[num_slot1]->in_body = 0;
				num_slot2 = if_m_in_sprite(pos_m, rpg->slot);
				if (rpg->slot[num_slot1]->status == 1) {
					exchange_slot(rpg->slot[num_slot1], rpg->slot[num_slot2], 0);
					exchange_slot(rpg->slot[num_slot2], rpg->slot[0], 0);
					fill = 0;
				}
			}
		}
	}
	printf("on sort\n");
}
