/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../include/rpg.h"

void display_minimap(sfSprite *sprite, rpg_t *rpg)
{
	sfRenderWindow_setView(rpg->wd, rpg->view->v_screen);
	sfRenderWindow_drawSprite(rpg->wd, sprite, NULL);
	sfRenderWindow_setView(rpg->wd, rpg->view->v_map);
	sfRenderWindow_drawSprite(rpg->wd, sprite, NULL);
}

int	disp_game(rpg_t *rpg)
{
	map_move(rpg->event, rpg->map);
	disp_map(rpg->wd, rpg->map, rpg->map->topleft_to_disp);
	// my_printf("CAN MOVE HERE: %d\n", can_move_here(rpg->map, rpg->map->topleft_to_disp));
	return (0);
}

int	game_loop(rpg_t *rpg)
{
	sfEvent event;

	sfRenderWindow_clear(rpg->wd, sfBlack);
	while(sfRenderWindow_pollEvent(rpg->wd, &event)) {
		rpg->event = event;
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(rpg->wd);
		scene_events_handler(rpg->wd, event, rpg->scene);
	}
	if (rpg->state == 0)
		disp_mainmenu(rpg);
	else if (rpg->state == 1) {
		sfRenderWindow_setView(rpg->wd, rpg->view->v_screen);
		disp_game(rpg);
		sfRenderWindow_setView(rpg->wd, rpg->view->v_map);
		disp_game(rpg);
		display_character(rpg);
		display_fairy(rpg);
	}
	sfRenderWindow_display(rpg->wd);
	return (0);
}

int	main(void)
{
	rpg_t *rpg = init_rpg();

	while (sfRenderWindow_isOpen(rpg->wd)) {
			game_loop(rpg);
	}
	sfRenderWindow_destroy(rpg->wd);
	return (0);
}
