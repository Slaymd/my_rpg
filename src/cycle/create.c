/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** time
*/

#include "rpg.h"

void set_cycle(cycle_t *cycle)
{
	sfText_setFont(cycle->text, cycle->font);
	sfText_setPosition(cycle->text, (V2F){95, 30});
	sfText_setCharacterSize(cycle->text, 25);
	sfSprite_setTexture(cycle->s_clock, cycle->t_clock, sfTrue);
	sfSprite_setPosition(cycle->s_clock, (V2F){42.5, 42.5});
	sfSprite_setOrigin(cycle->s_clock, (V2F){37.5, 37.5});
	sfSprite_setTexture(cycle->s_rain, cycle->t_rain, sfTrue);
}

cycle_t *create_cycle(void)
{
	cycle_t *cycle = malloc(sizeof(cycle_t));

	cycle->h = 8;
	cycle->m = 0;
	cycle->font = sfFont_createFromFile(FONT_UBUREG);
	cycle->text = sfText_create();
	cycle->clock = sfClock_create();
	cycle->time = sfClock_getElapsedTime(cycle->clock);
	cycle->seconds = 0;
	cycle->t_clock = sfTexture_createFromFile("./img/clock.png", NULL);
	cycle->s_clock = sfSprite_create();
	cycle->t_rain = sfTexture_createFromFile("./img/rain.png", NULL);
	cycle->s_rain = sfSprite_create();
	cycle->rain = (V2F){0, 0};
	cycle->cycle = create_particle((V2I){WIDTH, HEIGHT}, sfBlue, SQUARE,
	NONE);
	set_cycle(cycle);
	return (cycle);
}
