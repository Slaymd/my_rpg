/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** init
*/

#include "../include/rpg.h"

// void set_window(window_t *window)
// {
// 	window->window = sfRenderWindow_create(window->mode,"RPG",
// 	sfClose | sfResize, NULL);
// 	sfView_setSize(window->v_screen,
// 	(V2F){WIDTH * 0.6, HEIGHT * 0.6});
// 	sfView_setSize(window->v_map, (V2F){WIDTH, HEIGHT});
// 	sfView_setViewport(window->v_map, (FR){0.7, 0.05, 0.25, 0.25});
// 	sfRenderWindow_setFramerateLimit(window->window, 60);
// 	sfSprite_setTexture(window->sprite, window->texture, sfTrue);
// 	sfSprite_setPosition(window->sprite, (V2F){0, 0});
// 	sfSprite_setTextureRect(window->sprite, window->rect);
// }
//
// window_t *init_window(void)
// {
// 	window_t *window = malloc(sizeof(window_t));
//
// 	if (!window)
// 		return (NULL);
// 	window->mode = (sfVideoMode){WIDTH, HEIGHT, 32};
// 	window->texture = sfTexture_createFromFile("./img/bg.jpg", NULL);
// 	window->v_screen = sfView_createFromRect((FR)
// 	{0, 0, WIDTH, HEIGHT});
// 	window->v_map = sfView_createFromRect((FR)
// 	{0, 0, WIDTH, HEIGHT});
// 	window->sprite = sfSprite_create();
// 	window->rect = (sfIntRect){0, 0, WIDTH, HEIGHT};
// 	window->clock = sfClock_create();
// 	window->time = sfClock_getElapsedTime(window->clock);
// 	window->seconds = 0;
// 	set_window(window);
// 	return (window);
// }

view_t *create_view(void)
{
	view_t *view = malloc(sizeof(view_t));

	view->v_screen = sfView_createFromRect((FR){0, 0, WIDTH, HEIGHT});
	view->v_normal = sfView_createFromRect((FR){0, 0, WIDTH, HEIGHT});
	view->v_map = sfView_createFromRect((FR){0, 0, WIDTH, HEIGHT});
	// sfView_setSize(view->v_screen, (V2F){WIDTH * 0.8, HEIGHT * 0.8});
	sfView_zoom(view->v_screen, ZOOM);
	sfView_setSize(view->v_normal, (V2F){WIDTH, HEIGHT});
	sfView_setSize(view->v_map, (V2F){WIDTH * 2, HEIGHT * 2});
	sfView_setViewport(view->v_map, (FR){0.7, 0.0, 0.35, 0.35});
	return (view);
}

item_t *create_case_item(sfIntRect pos, const char *sprite, int info[5])
{
	item_t *item = malloc(sizeof(item_t));
	sfVector2f hard_pos = (sfVector2f){pos.left, pos.top};
	sfVector2f hard_size = (sfVector2f){pos.width, pos.height};

	item->in_body = info[0];
	item->can_e = info[1];
	item->status = info[2];
	item->attack = info[3];
	item->def = info[4];
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
	rpg->slot[0] = create_case_item((sfIntRect){0, 0, 0, 0}, "assets/inventory/empty.png", (int[5]){0, 0, 0, 0, 0});
	rpg->slot[1] = create_case_item((sfIntRect){10, 10, 700, 500}, "assets/inventory/inv.png", (int[5]){0, 0, 0, 0, 0});

	rpg->slot[2] = create_case_item((sfIntRect){70, 200, 50, 50}, "assets/inventory/amulette.png", (int[5]){0, 2, 1, 2, 0});
	rpg->slot[3] = create_case_item((sfIntRect){70, 280, 50, 50}, "assets/inventory/ankh.png", (int[5]){0, 2, 1, 5, 0});
	rpg->slot[4] = create_case_item((sfIntRect){70, 390, 50, 50}, "assets/inventory/armure.png", (int[5]){0, 3, 1, 0, 10});
	rpg->slot[5] = create_case_item((sfIntRect){230, 200, 50, 50}, "assets/inventory/teeshirt.png", (int[5]){0, 3, 1, 0, 1});
	rpg->slot[6] = create_case_item((sfIntRect){230, 280, 50, 50}, "assets/inventory/casquette.png", (int[5]){0, 1, 1, 0, 2});
	rpg->slot[7] = create_case_item((sfIntRect){230, 390, 50, 50}, "assets/inventory/casque.png", (int[5]){0, 1, 1, 0, 5});

	rpg->slot[8] = create_case_item((sfIntRect){350, 70, 50, 50}, "assets/inventory/empty.png", (int[5]){1, 0, 0, 0, 0});
	rpg->slot[9] = create_case_item((sfIntRect){200, 70, 50, 50}, "assets/inventory/empty.png", (int[5]){3, 0, 0, 0, 0});
	rpg->slot[10] = create_case_item((sfIntRect){500, 70, 50, 50}, "assets/inventory/empty.png", (int[5]){2, 0, 0, 0, 0});
	rpg->slot[11] = NULL;
}

rpg_t *init_rpg(void)
{
	rpg_t *rpg = (rpg_t*)malloc(sizeof(rpg_t));

	if (!rpg)
		return (NULL);
	rpg->state = 0;
	rpg->music = sfMusic_createFromFile("assets/musics/maintheme.ogg");
	sfMusic_setLoop(rpg->music, 1);
	sfMusic_play(rpg->music);
	rpg->wd = create_window();
	rpg->view = create_view();
	rpg->cycle = create_cycle();
	rpg->character = init_character();
	rpg->fairy = init_fairy();
	rpg->map = init_map(NULL, SEED);
	rpg->scene = init_mainmenu(rpg);
	init_inv(rpg);
	return (rpg);
}
