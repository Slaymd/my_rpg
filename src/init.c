/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** init
*/

#include "rpg.h"

view_t *create_view(void)
{
	view_t *view = malloc(sizeof(view_t));

	view->v_screen = sfView_createFromRect((FR){0, 0, WIDTH, HEIGHT});
	view->v_normal = sfView_createFromRect((FR){0, 0, WIDTH, HEIGHT});
	view->v_map = sfView_createFromRect((FR){0, 0, WIDTH, HEIGHT});
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
	rpg->view = create_view();
	rpg->npc = create_npc();
	rpg->htp = create_htp();
	rpg->cycle = create_cycle();
	rpg->character = init_character();
	if (!rpg->character)
		return (NULL);
	rpg->fairy = init_fairy();
	rpg->map = init_map(NULL, SEED);
	rpg->scene = init_mainmenu(rpg);
	return (rpg);
}
