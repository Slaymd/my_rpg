/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** init
*/

#include "../include/rpg.h"

void fill_armure2(inv_t *inv)
{
	int cpt = 0;

	for (cpt = 2; inv->slot[cpt] != NULL; cpt++)
		if (inv->slot[cpt]->in_body == 0 && inv->slot[cpt]->status == 0)
			break;
		if (cpt > 13)
			return;
	inv->slot[cpt]->titem = sfTexture_createFromFile
	("assets/inventory/armure2.png", NULL);
	sfSprite_setTexture(inv->slot[cpt]->sitem, inv->slot[cpt]->titem, sfTrue);
	inv->slot[cpt]->can_e = 3;
	inv->slot[cpt]->status = 1;
	inv->slot[cpt]->def = 10;
	inv->slot[cpt]->life = 20;
	inv->slot[cpt]->r_life = 5;
}

void fill_popo(inv_t *inv)
{
	int cpt = 0;

	for (cpt = 2; inv->slot[cpt] != NULL; cpt++)
		if ((inv->slot[cpt]->in_body == 0 &&
			inv->slot[cpt]->status == 0) ||
			(inv->slot[cpt]->status == 1 &&
			inv->slot[cpt]->stack > 0))
			break;
		if (cpt > 13)
			return;
	inv->slot[cpt]->titem = sfTexture_createFromFile
	("assets/inventory/popo.png", NULL);
	sfSprite_setTexture(inv->slot[cpt]->sitem, inv->slot[cpt]->titem, sfTrue);
	inv->slot[cpt]->can_e = 0;
	inv->slot[cpt]->status = 1;
	inv->slot[cpt]->conso = 3;
	inv->slot[cpt]->stack += 1;
}

void fill_armure(inv_t *inv)
{
	int cpt = 0;

	for (cpt = 2; inv->slot[cpt] != NULL; cpt++)
		if (inv->slot[cpt]->in_body == 0 && inv->slot[cpt]->status == 0)
			break;
		if (cpt > 13)
			return;
	inv->slot[cpt]->titem = sfTexture_createFromFile
	("assets/inventory/armure.png", NULL);
	sfSprite_setTexture(inv->slot[cpt]->sitem, inv->slot[cpt]->titem, sfTrue);
	inv->slot[cpt]->can_e = 3;
	inv->slot[cpt]->status = 1;
	inv->slot[cpt]->def = 2;
	inv->slot[cpt]->life = 10;
	inv->slot[cpt]->r_life = 5;
}

void rand_drop_item2(rpg_t *rpg, int num_item)
{
	switch(num_item) {
	case 16:
		fill_popo(rpg->inv);
		break;
	case 17:
		fill_r_life(rpg->inv);
		break;
	case 18:
		fill_r_life2(rpg->inv);
		break;
	case 19:
		fill_r_mana(rpg->inv);
		break;
	case 20:
		fill_r_mana2(rpg->inv);
		break;
	}
}

void rand_drop_item(rpg_t *rpg, entity_t *ent)
{
	int num_item = 0;

	if (ent->invent == 0) {
		num_item = random()%21;
		ent->invent = 1;
	} else
		return;

	switch(num_item) {
	case 10:
		fill_armure(rpg->inv);
		break;
	case 11:
		fill_armure2(rpg->inv);
		break;
	case 12:
		fill_att(rpg->inv);
		break;
	case 13:
		fill_att2(rpg->inv);
		break;
	case 14:
		fill_life_potion(rpg->inv);
		break;
	case 15:
		fill_mana_potion(rpg->inv);
		break;
	default:
		rand_drop_item2(rpg, num_item);
		break;
	}
}
