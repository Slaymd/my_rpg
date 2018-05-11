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
	sfRenderWindow_setView(rpg->wd, rpg->view->v_screen);
}

int	disp_game(rpg_t *rpg, sfEvent event)
{
	sfRenderWindow_setView(rpg->wd, rpg->view->v_screen);
	map_move(rpg->event, rpg->map);
	disp_map(rpg);
	sfRenderWindow_setView(rpg->wd, rpg->view->v_map);
	disp_map(rpg);
	ennemy_handling(rpg, rpg->map);
	display_character(rpg, rpg->character);
	display_fairy(rpg, event);
	cycle_handler(rpg);
	manage_inter(rpg);
	return (0);
}

int	game_loop(rpg_t *rpg)
{
	sfEvent event;

	sfRenderWindow_clear(rpg->wd, sfBlack);
	while (sfRenderWindow_pollEvent(rpg->wd, &event)) {
		rpg->event = event;
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(rpg->wd);
		scene_events_handler(rpg->wd, event, rpg->scene);
		pause_screen_events(rpg, event);
	}
	if (rpg->state < 3)
		disp_mainmenu(rpg);
	else if (rpg->state == 3) {
		if (sfKeyboard_isKeyPressed(sfKeyE))
			inventory(rpg);
		disp_game(rpg, event);
	}
	disp_pause_screen(rpg, 0);
	if (rpg->state == 5)
		manage_htp(rpg, rpg->htp);
	sfRenderWindow_display(rpg->wd);
	return (0);
}

int	main(void)
{
	rpg_t *rpg = init_rpg();

	srand(time(NULL));
	init_sprite(rpg);
	while (sfRenderWindow_isOpen(rpg->wd)) {
		game_loop(rpg);
	}
	free_rpg(rpg);
	return (0);
}
