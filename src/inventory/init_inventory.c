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
	rpg->inv->stat->r_lifei = 0;
	rpg->inv->stat->r_manai = 0;
	rpg->inv->stat->attt = create_inv_text("attack=2K img/police.ttf", 100, (sfVector2f){200, 300}, sfBlue);
	rpg->inv->stat->deft = create_inv_text("def=2K img/police.ttf", 100, (sfVector2f){50, 300}, sfBlue);
	rpg->inv->stat->lifet = create_inv_text("life=2K img/police.ttf", 100, (sfVector2f){50, 300}, sfBlue);
	rpg->inv->stat->r_lifet = create_inv_text("r_lifet=2K img/police.ttf", 100, (sfVector2f){50, 300}, sfBlue);
	rpg->inv->stat->r_manat = create_inv_text("r_manat=2K img/police.ttf", 100, (sfVector2f){50, 300}, sfBlue);
	rpg->inv->slot[0] = create_case_item((sfIntRect){0, 0, 0, 0}, "assets/inventory/empty.png", (int[10]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	rpg->inv->slot[1] = create_case_item((sfIntRect){10, 10, 700, 500}, "assets/inventory/inv.png", (int[10]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

	rpg->inv->slot[2] = create_case_item((sfIntRect){70, 200, 50, 50}, "assets/inventory/amulette.png", (int[10]){0, 2, 1, 2, 0, 0, 0, 0, 0, 0});
	rpg->inv->slot[3] = create_case_item((sfIntRect){70, 280, 50, 50}, "assets/inventory/ankh.png", (int[10]){0, 2, 1, 5, 0, 0, 0, 0, 0, 0});
	rpg->inv->slot[4] = create_case_item((sfIntRect){70, 390, 50, 50}, "assets/inventory/armure.png", (int[10]){0, 3, 1, 0, 5, 0, 0, 0, 0, 0});
	rpg->inv->slot[5] = create_case_item((sfIntRect){230, 200, 50, 50}, "assets/inventory/teeshirt.png", (int[10]){0, 3, 1, 0, 1, 0, 0, 0, 0, 0});
	rpg->inv->slot[6] = create_case_item((sfIntRect){230, 280, 50, 50}, "assets/inventory/casquette.png", (int[10]){0, 1, 1, 0, 2, 0, 0, 0, 0, 0});
	rpg->inv->slot[7] = create_case_item((sfIntRect){230, 390, 50, 50}, "assets/inventory/casque.png", (int[10]){0, 1, 1, 0, 5, 0, 0, 0, 0, 0});
	rpg->inv->slot[8] = create_case_item((sfIntRect){390, 200, 50, 50}, "assets/inventory/popo.png", (int[10]){0, 0, 1, 0, 0, 0, 0, 0, 1, 2});

	rpg->inv->slot[9] = create_case_item((sfIntRect){350, 70, 50, 50}, "assets/inventory/empty.png", (int[10]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	rpg->inv->slot[10] = create_case_item((sfIntRect){200, 70, 50, 50}, "assets/inventory/empty.png", (int[10]){3, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	rpg->inv->slot[11] = create_case_item((sfIntRect){500, 70, 50, 50}, "assets/inventory/empty.png", (int[10]){2, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	rpg->inv->slot[12] = NULL;
}
