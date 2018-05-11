/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** init
*/

#include "../include/rpg.h"

void fill_att(inv_t *inv)
{
	int cpt = 0;

	for (cpt = 2; inv->slot[cpt] != NULL; cpt++)
		if (inv->slot[cpt]->in_body == 0 && inv->slot[cpt]->status == 0)
			break;
		if (cpt > 13)
			return;
	inv->slot[cpt]->titem = sfTexture_createFromFile
	("assets/inventory/att.png", NULL);
	sfSprite_setTexture(inv->slot[cpt]->sitem, inv->slot[cpt]->titem, sfTrue);
	inv->slot[cpt]->can_e = 2;
	inv->slot[cpt]->status = 1;
	inv->slot[cpt]->attack = 5;
	inv->slot[cpt]->r_mana = 5;
}

void fill_att2(inv_t *inv)
{
	int cpt = 0;

	for (cpt = 2; inv->slot[cpt] != NULL; cpt++)
		if (inv->slot[cpt]->in_body == 0 && inv->slot[cpt]->status == 0)
			break;
		if (cpt > 13)
			return;
	inv->slot[cpt]->titem = sfTexture_createFromFile
	("assets/inventory/att2.png", NULL);
	sfSprite_setTexture(inv->slot[cpt]->sitem, inv->slot[cpt]->titem, sfTrue);
	inv->slot[cpt]->can_e = 2;
	inv->slot[cpt]->status = 1;
	inv->slot[cpt]->attack = 20;
	inv->slot[cpt]->r_mana = 5;
}

void fill_life_potion(inv_t *inv)
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
	("assets/inventory/life_potion.png", NULL);
	sfSprite_setTexture(inv->slot[cpt]->sitem, inv->slot[cpt]->titem, sfTrue);
	inv->slot[cpt]->can_e = 0;
	inv->slot[cpt]->status = 1;
	inv->slot[cpt]->conso = 1;
	inv->slot[cpt]->stack += 1;
}

void fill_mana_potion(inv_t *inv)
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
	("assets/inventory/mana_potion.png", NULL);
	sfSprite_setTexture(inv->slot[cpt]->sitem, inv->slot[cpt]->titem, sfTrue);
	inv->slot[cpt]->can_e = 0;
	inv->slot[cpt]->status = 1;
	inv->slot[cpt]->conso = 2;
	inv->slot[cpt]->stack += 1;
}
