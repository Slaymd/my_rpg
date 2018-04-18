/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "rpg.h"

void display_minimap(sfSprite *sprite, window_t *window)
{
	sfRenderWindow_setView(window->window, window->v_screen);
	sfRenderWindow_drawSprite(window->window, sprite, NULL);
	sfRenderWindow_setView(window->window, window->v_map);
	sfRenderWindow_drawSprite(window->window, sprite, NULL);
}

void my_free(rpg_t *rpg)
{
	sfRenderWindow_destroy(rpg->window->window);
	free_menu(rpg->menu);
}

int	main(void)
{
	map_t *map = init_map(NULL, 432542543);
	rpg_t *rpg = init_rpg();
	sfClock *sfclock = sfClock_create();
	sfTime sftime;
	init_sprite(rpg);

	while (sfRenderWindow_isOpen(rpg->window->window)) {
		sftime = sfClock_getElapsedTime(sfclock);
		if (sftime.microseconds / 1000000.0 > 0.05) {
			event_gestion(rpg->window, map);
			rpg->state == 0 ? menu(rpg) : game(rpg, map);
			sfRenderWindow_display(rpg->window->window);
		}
		printf("char y = %f et x  = %f\n", rpg->character->pos.y,  rpg->character->pos.x);
	}
	my_free(rpg);
	return (0);
}
