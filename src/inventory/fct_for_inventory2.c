/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** bootstrap
*/

#include "rpg.h"

char *my_itoa_free(int number, char *str, int first)
{
	int i = 0;

	if (first == 1)
		free(str);
	if (number == 0) {
		str = malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	for (int tmp = number; tmp > 0; tmp /= 10, i++);
	str = malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	i --;
	for (int tp = number; tp > 0; tp /= 10, i--)
		str[i] = tp % 10 + 48;
	return (str);
}

void fill_str(stat_perso_t *stat)
{
	static int verif = 0;

	stat->attc = my_itoa_free(stat->atti, stat->attc, verif);
	stat->defc = my_itoa_free(stat->defi, stat->defc, verif);
	stat->lifec = my_itoa_free(stat->lifei, stat->lifec, verif);
	stat->max_lifec = my_itoa_free(stat->max_lifei, stat->max_lifec, verif);
	stat->manac = my_itoa_free(stat->manai, stat->manac, verif);
	stat->r_lifec = my_itoa_free(stat->r_lifei, stat->r_lifec, verif);
	stat->r_manac = my_itoa_free(stat->r_manai, stat->r_manac, verif);
	verif = 1;
	sfText_setString(stat->attt->text, stat->attc);
	sfText_setString(stat->deft->text, stat->defc);
	sfText_setString(stat->lifet->text, stat->lifec);
	sfText_setString(stat->max_lifet->text, stat->max_lifec);
	sfText_setString(stat->manat->text, stat->manac);
	sfText_setString(stat->r_lifet->text, stat->r_lifec);
	sfText_setString(stat->r_manat->text, stat->r_manac);
}

void recup_info(inv_t *inv, main_stat_t *stat)
{
	inv->stat->atti = (int)stat->attack;
	inv->stat->defi = (int)stat->defense;
	inv->stat->max_lifei = (int)stat->hp_max;
	inv->stat->r_lifei = (int)stat->hp_r;
	inv->stat->r_manai = (int)stat->mana_r;
	for (int i = 2; inv->slot[i] != NULL; i++) {
		if (inv->slot[i]->in_body > 0) {
			inv->stat->atti += inv->slot[i]->attack;
			inv->stat->defi += inv->slot[i]->def;
			inv->stat->max_lifei += inv->slot[i]->life;
			inv->stat->r_lifei += inv->slot[i]->r_life;
			inv->stat->r_manai += inv->slot[i]->r_mana;
		}
	}
	inv->stat->lifei = (int)stat->hp;
	inv->stat->manai = (int)stat->mana;
	fill_str(inv->stat);
}

void consom(item_t *item)
{
	printf("on consomme la popo\n");
	item->stack -= 1;
	if (item->stack <= 0) {
		item->titem = sfTexture_createFromFile
		("assets/inventory/empty.png", NULL);
		sfSprite_setTexture (item->sitem, item->titem, sfTrue);
		item->status = 0;
		item->conso = 0;
	}
}
