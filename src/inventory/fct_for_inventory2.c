/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** bootstrap
*/

#include "rpg.h"

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
