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
	item->conso = info[5];
	item->stack = info[6];
}

item_t *create_case_item(sfIntRect pos, const char *sprite, int info[7])
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
	rpg->slot[0] = create_case_item((sfIntRect){0, 0, 0, 0}, "assets/inventory/empty.png", (int[7]){0, 0, 0, 0, 0, 0, 0});
	rpg->slot[1] = create_case_item((sfIntRect){10, 10, 700, 500}, "assets/inventory/inv.png", (int[7]){0, 0, 0, 0, 0, 0, 0});

	rpg->slot[2] = create_case_item((sfIntRect){70, 200, 50, 50}, "assets/inventory/amulette.png", (int[7]){0, 2, 1, 2, 0, 0, 0});
	rpg->slot[3] = create_case_item((sfIntRect){70, 280, 50, 50}, "assets/inventory/ankh.png", (int[7]){0, 2, 1, 5, 0, 0, 0});
	rpg->slot[4] = create_case_item((sfIntRect){70, 390, 50, 50}, "assets/inventory/armure.png", (int[7]){0, 3, 1, 0, 1, 0, 0});
	rpg->slot[5] = create_case_item((sfIntRect){230, 200, 50, 50}, "assets/inventory/teeshirt.png", (int[7]){0, 3, 1, 0, 1, 0, 0});
	rpg->slot[6] = create_case_item((sfIntRect){230, 280, 50, 50}, "assets/inventory/casquette.png", (int[7]){0, 1, 1, 0, 2, 0, 0});
	rpg->slot[7] = create_case_item((sfIntRect){230, 390, 50, 50}, "assets/inventory/casque.png", (int[7]){0, 1, 1, 0, 5, 0, 0});

	rpg->slot[8] = create_case_item((sfIntRect){350, 70, 50, 50}, "assets/inventory/empty.png", (int[7]){1, 0, 0, 0, 0, 0, 0});
	rpg->slot[9] = create_case_item((sfIntRect){200, 70, 50, 50}, "assets/inventory/empty.png", (int[7]){3, 0, 0, 0, 0, 0, 0});
	rpg->slot[10] = create_case_item((sfIntRect){500, 70, 50, 50}, "assets/inventory/empty.png", (int[7]){2, 0, 0, 0, 0, 0, 0});
	rpg->slot[11] = NULL;
}
