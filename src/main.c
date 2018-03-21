/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../include/rpg.h"
#include "../include/my.h"
#include "../include/map.h"
#include "../include/linked_list.h"

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

int	main(int nbargs, char **args, char **envp)
{
	map_t *map = generate_map(55465756);
	sfRenderWindow *wd = create_window();
	sfEvent event;

	while (sfRenderWindow_isOpen(wd)) {
		while (sfRenderWindow_pollEvent(wd, &event))
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(wd);
		sfRenderWindow_clear(wd, sfBlack);
		disp_map(wd, map);
		sfRenderWindow_display(wd);
	}
	sfRenderWindow_destroy(wd);
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
		sfRenderWindow_display(rpg->window->window);
	}
	free_rpg(rpg);
	return (0);
}*/
