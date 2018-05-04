/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** time
*/

#include "rpg.h"

cycle_t *create_cycle(void)
{
	cycle_t *cycle = malloc(sizeof(cycle_t));

	cycle->h = 0;
	cycle->m = 0;
	cycle->font = sfFont_createFromFile(FONT_UBUREG);
	cycle->text = sfText_create();
	sfText_setFont(cycle->text, cycle->font);
	sfText_setPosition(cycle->text, (V2F){95, 30});
	sfText_setCharacterSize(cycle->text, 25);
	cycle->clock = sfClock_create();
	cycle->time = sfClock_getElapsedTime(cycle->clock);
	cycle->seconds = 0;
	cycle->texture = sfTexture_createFromFile("./img/clock.png", NULL);
	cycle->sprite = sfSprite_create();
	sfSprite_setTexture(cycle->sprite, cycle->texture, sfTrue);
	sfSprite_setPosition(cycle->sprite, (V2F){42.5, 42.5});
	sfSprite_setOrigin(cycle->sprite, (V2F){37.5, 37.5});
	return (cycle);
}
