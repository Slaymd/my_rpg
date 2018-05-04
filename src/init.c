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
	rpg->hud = create_hud();
	rpg->view = create_view();
	rpg->character = init_character();
	rpg->fairy = init_fairy();
	rpg->map = init_map(NULL, SEED);
	rpg->scene = init_mainmenu(rpg);
	return (rpg);
}
