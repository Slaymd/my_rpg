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

int main(void)
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
			if (rpg->state == 0) {
				sfRenderWindow_clear(rpg->window->window, sfBlack);
				manage_buttons(rpg);
				display_menu(rpg->menu->scene[rpg->menu->state], rpg->window);
			} else if (rpg->state == 1) {
				sfRenderWindow_clear(rpg->window->window, sfBlack);
				sfRenderWindow_setView(rpg->window->window, rpg->window->v_screen);
				disp_map(rpg->window->window, map, map->topleft_to_disp);
				sfRenderWindow_setView(rpg->window->window, rpg->window->v_map);
				disp_map(rpg->window->window, map, map->topleft_to_disp);
				display_character(rpg->window, rpg->character);
				display_ennemy(rpg->window, rpg->ennemy[0], map);
			}
			sfRenderWindow_display(rpg->window->window);
		}
	}
	sfRenderWindow_destroy(rpg->window->window);
	free_menu(rpg->menu);
	return (0);
}
