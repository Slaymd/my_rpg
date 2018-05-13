/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** init
*/

#include "../include/rpg.h"

void fill_r_life(inv_t *inv)
{
	int cpt = 0;

	for (cpt = 2; inv->slot[cpt] != NULL; cpt++)
		if (inv->slot[cpt]->in_body == 0 && inv->slot[cpt]->status == 0)
			break;
		if (cpt > 13)
			return;
	inv->slot[cpt]->titem = sfTexture_createFromFile
	("assets/inventory/r_life.png", NULL);
	sfSprite_setTexture
	(inv->slot[cpt]->sitem, inv->slot[cpt]->titem, sfTrue);
	inv->slot[cpt]->can_e = 1;
	inv->slot[cpt]->status = 1;
	inv->slot[cpt]->def = 5;
	inv->slot[cpt]->life = 10;
	inv->slot[cpt]->r_life = 10;
}

void fill_r_life2(inv_t *inv)
{
	int cpt = 0;

	for (cpt = 2; inv->slot[cpt] != NULL; cpt++) {
		if (inv->slot[cpt]->in_body == 0 && inv->slot[cpt]->status == 0)
			break;
		if (cpt > 13)
			return;
	}
	inv->slot[cpt]->titem = sfTexture_createFromFile
	("assets/inventory/r_life2.png", NULL);
	sfSprite_setTexture
	(inv->slot[cpt]->sitem, inv->slot[cpt]->titem, sfTrue);
	inv->slot[cpt]->can_e = 1;
	inv->slot[cpt]->status = 1;
	inv->slot[cpt]->def = 10;
	inv->slot[cpt]->life = 25;
	inv->slot[cpt]->r_life = 25;
}

void fill_r_mana(inv_t *inv)
{
	int cpt = 0;

	for (cpt = 2; inv->slot[cpt] != NULL; cpt++) {
		if (inv->slot[cpt]->in_body == 0 && inv->slot[cpt]->status == 0)
			break;
		if (cpt > 13)
			return;
	}
	inv->slot[cpt]->titem = sfTexture_createFromFile
	("assets/inventory/r_mana.png", NULL);
	sfSprite_setTexture
	(inv->slot[cpt]->sitem, inv->slot[cpt]->titem, sfTrue);
	inv->slot[cpt]->can_e = 1;
	inv->slot[cpt]->status = 1;
	inv->slot[cpt]->def = 5;
	inv->slot[cpt]->r_life = 15;
}

void fill_r_mana2(inv_t *inv)
{
	int cpt = 0;

	for (cpt = 2; inv->slot[cpt] != NULL; cpt++) {
		if (inv->slot[cpt]->in_body == 0 && inv->slot[cpt]->status == 0)
			break;
		if (cpt > 13)
			return;
	}
	inv->slot[cpt]->titem = sfTexture_createFromFile
	("assets/inventory/r_mana2.png", NULL);
	sfSprite_setTexture
	(inv->slot[cpt]->sitem, inv->slot[cpt]->titem, sfTrue);
	inv->slot[cpt]->can_e = 1;
	inv->slot[cpt]->status = 1;
	inv->slot[cpt]->def = 10;
	inv->slot[cpt]->r_mana = 25;
}
