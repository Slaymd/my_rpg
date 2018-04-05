/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../include/rpg.h"

sfRenderWindow	*create_window(void)
{
	sfRenderWindow	*window;
	sfVideoMode	mode;

	mode.width = WIDTH;
	mode.height = HEIGHT;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "my_rpg", sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	return (window);
}

int	main(void)
{
	map_t *map = init_map(NULL, 432542543);
	rpg_t *rpg = init_rpg();
	sfClock *sfclock = sfClock_create();
	sfTime sftime;
	int start = 1;
	init_sprite(rpg);
	while (sfRenderWindow_isOpen(rpg->window->window)) {
		sftime = sfClock_getElapsedTime(sfclock);
		sfRenderWindow_clear(rpg->window->window, sfBlack);
		disp_map(rpg->window->window, map, map->topleft_to_disp);
		sfRenderWindow_setView(rpg->window->window, rpg->window->v_map);
		disp_map(rpg->window->window, map, map->topleft_to_disp);
		sfRenderWindow_setView(rpg->window->window, rpg->window->v_screen);
		if (sftime.microseconds / 1000000.0 > 0.05) {
			if (map_event_handler(rpg->window, map) || start)
				start = 0;
			display_ennemy(rpg->window, rpg->ennemy[0], map);
			display_character(rpg->window, rpg->character, map);
			sfRenderWindow_display(rpg->window->window);
		}
	}
	sfRenderWindow_destroy(rpg->window->window);
	return (0);
}

/*int main(int ac, char **av)
{
	rpg_t *rpg = init_rpg();

	if (!rpg || ac != ac || av != av)
		return (84);
	while (sfRenderWindow_isOpen(rpg->window->window)) {
		event_gestion(rpg->window);
		display_map(rpg->window, rpg->character);
		display_character(rpg->window, rpg->character);
		verif_action(rpg);
		sfRenderWindow_display(rpg->window->window);
	}
	free_rpg(rpg);
	return (0);
}*/
