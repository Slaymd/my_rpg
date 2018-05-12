/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** cycle
*/

#include "rpg.h"

void display_rain(cycle_t *cycle, sfRenderWindow *window)
{
	sfSprite_setPosition(cycle->s_rain, (V2F){cycle->rain.x - 1920, cycle->rain.y});
	sfRenderWindow_drawSprite(window, cycle->s_rain, NULL);
	sfSprite_setPosition(cycle->s_rain, (V2F){cycle->rain.x - 1920, cycle->rain.y - 1080});
	sfRenderWindow_drawSprite(window, cycle->s_rain, NULL);
	sfSprite_setPosition(cycle->s_rain, (V2F){cycle->rain.x, cycle->rain.y});
	sfRenderWindow_drawSprite(window, cycle->s_rain, NULL);
	sfSprite_setPosition(cycle->s_rain, (V2F){cycle->rain.x, cycle->rain.y - 1080});
	sfRenderWindow_drawSprite(window, cycle->s_rain, NULL);
	sfSprite_setPosition(cycle->s_rain, (V2F){cycle->rain.x + 1920, cycle->rain.y});
	sfRenderWindow_drawSprite(window, cycle->s_rain, NULL);
	sfSprite_setPosition(cycle->s_rain, (V2F){cycle->rain.x + 1920, cycle->rain.y - 1080});
	sfRenderWindow_drawSprite(window, cycle->s_rain, NULL);
	(KeyPressed(sfKeyLeft)) ? cycle->rain.x += 8 : 0;
	(KeyPressed(sfKeyRight)) ? cycle->rain.x -= 8 : 0;
	(KeyPressed(sfKeyUp)) ? cycle->rain.y += 8 : 0;
	cycle->rain.y += 8;
	cycle->rain.y >= 1080 ? cycle->rain.y = 0 : 0;
	cycle->rain.x >= 1920 ? cycle->rain.x = 0 : 0;
	cycle->rain.x <= -1920 ? cycle->rain.x = 0 : 0;
}

void cycle_rain(cycle_t *cycle, sfRenderWindow *window)
{
	static int rain = 0;
	static double luck = 0;

	luck += 0.0001;
	if (rain == 1) {
		display_rain(cycle, window);
		if (luck >= 0.5) {
			cycle->rain.x = 0;
			cycle->rain.y = 0;
			rain = 0;
			luck = 0;
		}
	} else {
		if (luck >= 2) {
			rain = 1;
			luck = 0;
		}
	}
}

void run_cycle(cycle_t *cycle)
{
	sfColor color = sfSprite_getColor(cycle->cycle->sprite);
	float alpha = 0;

	if (cycle->h >= 20 || cycle->h <= 4) {
		alpha = 75;
	} else if (cycle->h >= 18) {
		alpha = (cycle->h + (float)cycle->m / 60) - 18;
		alpha = alpha / 2 * 75;
	} else {
		if (cycle->h <= 6) {
			alpha = (cycle->h - 5 + (float)cycle->m / 60) * -1 + 2;
			alpha = alpha / 2 * 75;
		}
	}
	color.a = (int)alpha;
	sfSprite_setColor(cycle->cycle->sprite, color);
}

void cycle_handler(rpg_t *rpg)
{
	refresh_time(rpg->cycle);
	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	cycle_rain(rpg->cycle, rpg->wd);
	display_time(rpg->cycle, rpg->wd);
	display_particle(rpg->cycle->cycle, rpg->wd,
	(V2F){WIDTH / 2, HEIGHT / 2}, 1);
}
