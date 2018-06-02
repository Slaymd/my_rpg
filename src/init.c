/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** init
*/

#include "../include/rpg.h"

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

int	init_map_gen_profile(rpg_t *rpg)
{
	rpg->gen_profile = (float*)malloc(sizeof(float)*8);
	rpg->gen_profile[0] = TILE_WATER_ID;
	rpg->gen_profile[1] = 0.4;
	rpg->gen_profile[2] = TILE_SAND_ID;
	rpg->gen_profile[3] = 0.5;
	rpg->gen_profile[4] = TILE_GRASS_ID;
	rpg->gen_profile[5] = 0.8;
	rpg->gen_profile[6] = TILE_DARKGRASS_ID;
	rpg->gen_profile[7] = 1.1;
	return (1);
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
	init_map_gen_profile(rpg);
	rpg->character = init_character();
	rpg->fairy = init_fairy();
	rpg->map = init_map(NULL, SEED, 0, rpg->gen_profile);
	rpg->scene = init_mainmenu(rpg);
	init_inv(rpg);
	return (rpg);
}
