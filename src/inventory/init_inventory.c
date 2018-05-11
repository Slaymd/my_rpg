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

void init_item_info(item_t *item, int info[7])
{
	item->in_body = info[0];
	item->can_e = info[1];
	item->status = info[2];
	item->attack = info[3];
	item->def = info[4];
	item->life = info[5];
	item->r_life = info[6];
	item->r_mana = info[7];
	item->conso = info[8];
	item->stack = info[9];
}

item_t *create_case_item(sfIntRect pos, const char *sprite, int info[10])
{
	item_t *item = malloc(sizeof(item_t));
	sfVector2f hard_pos = (sfVector2f){pos.left, pos.top};
	sfVector2f hard_size = (sfVector2f){pos.width, pos.height};

	init_item_info(item, info);
	item->sitem = sfSprite_create();
	item->titem = sfTexture_createFromFile(sprite, NULL);
	sfSprite_setTexture (item->sitem, item->titem, sfTrue);
	item->pitem = hard_pos;
	item->ritem.left = 0;
	item->ritem.top = 0;
	item->ritem.width = hard_size.x;
	item->ritem.height = hard_size.y;
	sfSprite_setTextureRect(item->sitem, item->ritem);
	sfSprite_setPosition(item->sitem, hard_pos);
	return (item);
}

void init_inv(rpg_t *rpg)
{
	rpg->inv = malloc(sizeof(inv_t));
	rpg->inv->stat = malloc(sizeof(stat_perso_t));

	rpg->inv->clocki = sfClock_create();
	rpg->inv->seconds = 0;
	rpg->inv->quit = 0;
	rpg->inv->fill = 0;
	rpg->inv->stat->atti = 0;
	rpg->inv->stat->defi = 0;
	rpg->inv->stat->lifei = 0;
	rpg->inv->stat->max_lifei = 0;
	rpg->inv->stat->manai = 0;
	rpg->inv->stat->r_lifei = 0;
	rpg->inv->stat->r_manai = 0;
	rpg->inv->stat->attc = malloc(sizeof(char) * 2);
	rpg->inv->stat->defc = malloc(sizeof(char) * 2);
	rpg->inv->stat->lifec = malloc(sizeof(char) * 2);
	rpg->inv->stat->max_lifec = malloc(sizeof(char) * 2);
	rpg->inv->stat->manac = malloc(sizeof(char) * 2);
	rpg->inv->stat->r_lifec = malloc(sizeof(char) * 2);
	rpg->inv->stat->r_manac = malloc(sizeof(char) * 2);
	rpg->inv->stat->attt = create_inv_text("0 img/police.ttf", 20, (sfVector2f){333, 400}, sfWhite);
	rpg->inv->stat->deft = create_inv_text("0 img/police.ttf", 20, (sfVector2f){344, 440}, sfWhite);
	rpg->inv->stat->lifet = create_inv_text("0 img/police.ttf", 20, (sfVector2f){340, 340}, sfWhite);
	rpg->inv->stat->max_lifet = create_inv_text("100 img/police.ttf", 20, (sfVector2f){400, 340}, sfWhite);
	rpg->inv->stat->manat = create_inv_text("0 img/police.ttf", 20, (sfVector2f){340, 360}, sfWhite);
	rpg->inv->stat->max_manat = create_inv_text("100 img/police.ttf", 20, (sfVector2f){400, 360}, sfWhite);
	rpg->inv->stat->r_lifet = create_inv_text("0 img/police.ttf", 20, (sfVector2f){450, 400}, sfWhite);
	rpg->inv->stat->r_manat = create_inv_text("0 img/police.ttf", 20, (sfVector2f){450, 440}, sfWhite);

	rpg->inv->slot[0] = create_case_item((sfIntRect){0, 0, 0, 0}, "assets/inventory/empty.png", (int[10]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	rpg->inv->slot[1] = create_case_item((sfIntRect){100, 40, 700, 500}, "assets/inventory/inv.png", (int[10]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

	rpg->inv->slot[2] = create_case_item((sfIntRect){500, 140, 65, 65}, "assets/inventory/armure.png", (int[10]){0, 3, 1, 2, 5, 0, 10, 0, 0, 0});
	rpg->inv->slot[3] = create_case_item((sfIntRect){592, 140, 65, 65}, "assets/inventory/armure2.png", (int[10]){0, 3, 1, 0, 15, 10, 0, 0, 0, 0});
	rpg->inv->slot[4] = create_case_item((sfIntRect){684, 140, 65, 65}, "assets/inventory/att.png", (int[10]){0, 2, 1, 5, 0, 0, 0, 0, 0, 0});
	rpg->inv->slot[5] = create_case_item((sfIntRect){500, 235, 65, 65}, "assets/inventory/att2.png", (int[10]){0, 2, 1, 10, 1, 1, 5, 5, 0, 0});
	rpg->inv->slot[6] = create_case_item((sfIntRect){592, 235, 65, 65}, "assets/inventory/r_life.png", (int[10]){0, 1, 1, 0, 0, 10, 20, 0, 0, 0});
	rpg->inv->slot[7] = create_case_item((sfIntRect){684, 235, 65, 65}, "assets/inventory/r_mana2.png", (int[10]){0, 1, 1, 0, 0, 10, 0, 20, 0, 0});
	rpg->inv->slot[8] = create_case_item((sfIntRect){500, 330, 65, 65}, "assets/inventory/popo.png", (int[10]){0, 0, 1, 0, 0, 0, 0, 0, 1, 2});

	rpg->inv->slot[9] = create_case_item((sfIntRect){165, 160, 65, 65}, "assets/inventory/empty.png", (int[10]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	rpg->inv->slot[10] = create_case_item((sfIntRect){165, 275, 65, 65}, "assets/inventory/empty.png", (int[10]){2, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	rpg->inv->slot[11] = create_case_item((sfIntRect){165, 390, 65, 65}, "assets/inventory/empty.png", (int[10]){3, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	rpg->inv->slot[12] = NULL;
}
