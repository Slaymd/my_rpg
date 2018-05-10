/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** bootstrap
*/

#include "rpg.h"


// char *my_itoa_free(int i, char *str)
// {
// 	int i = 0;
//
// 	if (str != NULL)
// 		free(str)
// 	if (number == 0) {
// 		str = malloc(sizeof(char) * 2);
// 		str[0] = '0';
// 		str[1] = '\0';
// 		return (str);
// 	}
// 	for (int tmp = number; tmp > 0; tmp /= 10, i++);
// 	str = malloc(sizeof(char) * (i + 1));
// 	str[i] = '\0';
// 	i --;
// 	for (int tp = number; tp > 0; tp /= 10, i--)
// 		str[i] = tp % 10 + 48;
// 	return (str);
// }

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
	inv->stat->atti = 0;
	inv->stat->defi = 0;
	inv->stat->lifei = 0;
	inv->stat->r_lifei = 0;
	inv->stat->r_manai = 0;
	for (int i = 2; inv->slot[i] != NULL; i++) {
		if (inv->slot[i]->in_body > 0) {
			inv->stat->atti += inv->slot[i]->attack;
			inv->stat->defi += inv->slot[i]->def;
			inv->stat->lifei += inv->slot[i]->life;
			inv->stat->r_lifei += inv->slot[i]->r_life;
			inv->stat->r_manai += inv->slot[i]->r_mana;
		}
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
