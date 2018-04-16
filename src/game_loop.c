/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "rpg.h"

void game(rpg_t *rpg, map_t *map)
{
	sfRenderWindow_clear(rpg->window->window, sfBlack);
	sfRenderWindow_setView(rpg->window->window, rpg->window->v_screen);
	disp_map(rpg->window->window, map, map->topleft_to_disp);
	sfRenderWindow_setView(rpg->window->window, rpg->window->v_map);
	disp_map(rpg->window->window, map, map->topleft_to_disp);
	display_character(rpg->window, rpg->character);
	ennemy_handling(rpg, map);
}

void menu(rpg_t *rpg)
{
	sfRenderWindow_clear(rpg->window->window, sfBlack);
	manage_buttons(rpg);
	display_menu(rpg->menu->scene[rpg->menu->state], rpg->window);
}
