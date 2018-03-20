/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "rpg.h"

int main(int ac, char **av)
{
	rpg_t *rpg = init_rpg();

	if (!rpg || ac != ac || av != av)
		return (84);
	while (sfRenderWindow_isOpen(rpg->window->window)) {
		event_gestion(rpg->window);
		display_map(rpg->window, rpg->character);
		display_character(rpg->window, rpg->character);
		sfRenderWindow_display(rpg->window->window);
	}
	free_rpg(rpg);
	return (0);
}
