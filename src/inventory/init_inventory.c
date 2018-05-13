/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** init
*/

#include "../include/rpg.h"

text_t *create_inv_text(char *info, int size, sfVector2f pos, sfColor color)
{
	text_t *text = malloc(sizeof(text_t));
	char **str = str_to_array(info, ' ');

	text->text = sfText_create();
	text->font = sfFont_createFromFile(str[1]);
	sfText_setFont(text->text, text->font);
	sfText_setString(text->text, str[0]);
	sfText_setCharacterSize(text->text, size);
	sfText_setPosition(text->text, pos);
	sfText_setColor(text->text, color);
	free_str_array(str);
	return (text);
}

void init_inv_stat2(rpg_t *rpg)
{
	rpg->inv->stat->attt = create_inv_text("0 img/police.ttf", 20,
	(sfVector2f){333, 400}, sfWhite);
	rpg->inv->stat->deft = create_inv_text("0 img/police.ttf", 20,
	(sfVector2f){344, 440}, sfWhite);
	rpg->inv->stat->lifet = create_inv_text("0 img/police.ttf", 20,
	(sfVector2f){340, 340}, sfWhite);
	rpg->inv->stat->max_lifet = create_inv_text("100 img/police.ttf", 20,
	(sfVector2f){400, 340}, sfWhite);
	rpg->inv->stat->manat = create_inv_text("0 img/police.ttf", 20,
	(sfVector2f){340, 360}, sfWhite);
	rpg->inv->stat->max_manat = create_inv_text("100 img/police.ttf", 20,
	(sfVector2f){400, 360}, sfWhite);
	rpg->inv->stat->r_lifet = create_inv_text("0 img/police.ttf", 20,
	(sfVector2f){450, 400}, sfWhite);
	rpg->inv->stat->r_manat = create_inv_text("0 img/police.ttf", 20,
	(sfVector2f){450, 440}, sfWhite);
	init_tab_item(rpg);
}

void init_inv_stat(rpg_t *rpg)
{
	rpg->inv->stat = malloc(sizeof(stat_perso_t));
	rpg->inv->stat->atti = rpg->character->stat->attack;
	rpg->inv->stat->defi = rpg->character->stat->defense;
	rpg->inv->stat->lifei = rpg->character->stat->hp;
	rpg->inv->stat->max_lifei = rpg->character->stat->hp_max;
	rpg->inv->stat->manai = rpg->character->stat->mana;
	rpg->inv->stat->r_lifei = rpg->character->stat->hp_r;
	rpg->inv->stat->r_manai = rpg->character->stat->mana_r;
	rpg->inv->stat->attc = malloc(sizeof(char) * 2);
	rpg->inv->stat->defc = malloc(sizeof(char) * 2);
	rpg->inv->stat->lifec = malloc(sizeof(char) * 2);
	rpg->inv->stat->max_lifec = malloc(sizeof(char) * 2);
	rpg->inv->stat->manac = malloc(sizeof(char) * 2);
	rpg->inv->stat->r_lifec = malloc(sizeof(char) * 2);
	rpg->inv->stat->r_manac = malloc(sizeof(char) * 2);
	init_inv_stat2(rpg);
}
void init_inv(rpg_t *rpg)
{
	rpg->inv = malloc(sizeof(inv_t));
	rpg->inv->clocki = sfClock_create();
	rpg->inv->seconds = 0;
	rpg->inv->quit = 0;
	rpg->inv->fill = 0;
	init_inv_stat(rpg);
}
