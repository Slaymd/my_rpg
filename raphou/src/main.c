/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "proto.h"

int main(int ac, char **av)
{
	window_t *window = init_window();
	character_t *character = init_character();

	if (!window || !character || ac != ac || av != av)
		return (84);
	while (sfRenderWindow_isOpen(window->window)) {
		event_gestion(window);
		display_map(window);
		display_character(window, character);
		sfRenderWindow_display(window->window);
	}
	my_free(window, character);
	return (0);
}
