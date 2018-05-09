/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** bootstrap
*/

#include "rpg.h"

void fill_str(inv_t *inv)
{
	sfText_setString(inv->stat->attt->text, my_itoa(inv->stat->atti));
	sfText_setString(inv->stat->deft->text, my_itoa(inv->stat->defi));
	sfText_setString(inv->stat->lifet->text, my_itoa(inv->stat->lifei));
	sfText_setString(inv->stat->r_lifet->text, my_itoa(inv->stat->r_lifei));
	sfText_setString(inv->stat->r_manat->text, my_itoa(inv->stat->r_manai));
}

void recup_info(inv_t *inv)
{
	for (int i = 0; inv->slot[i] != NULL; i++) {
		inv->stat->atti += inv->slot[i]->attack;
		inv->stat->defi += inv->slot[i]->def;
		inv->stat->lifei += inv->slot[i]->life;
		inv->stat->r_lifei += inv->slot[i]->r_life;
		inv->stat->r_manai += inv->slot[i]->r_mana;
	}
	fill_str(inv);
}

void consom(item_t *item)
{
	printf("on consomme la popo\n");
	item->stack -= 1;
	if (item->stack <= 0) {
		item->titem = sfTexture_createFromFile("assets/inventory/empty.png", NULL);
		sfSprite_setTexture (item->sitem, item->titem, sfTrue);
		item->status = 0;
		item->conso = 0;
	}
}
