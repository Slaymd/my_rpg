/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** init
*/

#include "../include/rpg.h"

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

item_t *create_slot(sfIntRect pos, const char *sprite, int info[10])
{
	item_t *item = malloc(sizeof(item_t));
	sfVector2f hard_pos = (sfVector2f){pos.left, pos.top};
	sfVector2f hard_size = (sfVector2f){pos.width, pos.height};

	init_item_info(item, info);
	item->sitem = sfSprite_create();
	item->titem = sfTexture_createFromFile(sprite, NULL);
	sfSprite_setTexture(item->sitem, item->titem, sfTrue);
	item->pitem = hard_pos;
	item->ritem.left = 0;
	item->ritem.top = 0;
	item->ritem.width = hard_size.x;
	item->ritem.height = hard_size.y;
	sfSprite_setTextureRect(item->sitem, item->ritem);
	sfSprite_setPosition(item->sitem, hard_pos);
	return (item);
}

item_t *fill_tab(sfIntRect rect)
{
	item_t *item;
	item = create_slot(rect, "assets/inventory/empty.png",
	(int[10]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	return (item);
}

void fill_mid_tab(rpg_t *rpg)
{
	rpg->inv->slot[2] = fill_tab((sfIntRect){500, 140, 65, 65});
	rpg->inv->slot[3] = fill_tab((sfIntRect){592, 140, 65, 65});
	rpg->inv->slot[4] = fill_tab((sfIntRect){684, 140, 65, 65});
	rpg->inv->slot[5] = fill_tab((sfIntRect){500, 235, 65, 65});
	rpg->inv->slot[6] = fill_tab((sfIntRect){592, 235, 65, 65});
	rpg->inv->slot[7] = fill_tab((sfIntRect){684, 235, 65, 65});
	rpg->inv->slot[8] = fill_tab((sfIntRect){500, 330, 65, 65});
	rpg->inv->slot[9] = fill_tab((sfIntRect){592, 330, 65, 65});
	rpg->inv->slot[10] = fill_tab((sfIntRect){684, 330, 65, 65});
	rpg->inv->slot[11] = fill_tab((sfIntRect){500, 425, 65, 65});
	rpg->inv->slot[12] = fill_tab((sfIntRect){592, 425, 65, 65});
	rpg->inv->slot[13] = fill_tab((sfIntRect){684, 425, 65, 65});
}

void init_tab_item(rpg_t *rpg)
{
	rpg->inv->slot[0] = create_slot((sfIntRect){0, 0, 0, 0},
	"assets/inventory/empty.png", (int[10]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	rpg->inv->slot[1] = create_slot((sfIntRect){100, 40, 700, 550},
	"assets/inventory/new_inv.png",
	(int[10]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	fill_mid_tab(rpg);
	rpg->inv->slot[14] = create_slot((sfIntRect){165, 160, 65, 65},
	"assets/inventory/empty.png", (int[10]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	rpg->inv->slot[15] = create_slot((sfIntRect){165, 275, 65, 65},
	"assets/inventory/empty.png", (int[10]){2, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	rpg->inv->slot[16] = create_slot((sfIntRect){165, 390, 65, 65},
	"assets/inventory/empty.png", (int[10]){3, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	rpg->inv->slot[17] = NULL;
}
