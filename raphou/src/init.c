/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** init
*/

#include "proto.h"

void set_character(character_t *character)
{
	int x = SIZE_X / 2 - 68 / 2;
	int y = SIZE_Y / 2 - 72 / 2;

	sfSprite_setTexture(character->sprite, character->texture, sfTrue);
	sfSprite_setPosition(character->sprite, (sfVector2f){x, y});
	sfSprite_setTextureRect(character->sprite, character->rect);
}

character_t *init_character(void)
{
	character_t *character = malloc(sizeof(character_t));

	if (!character)
		return (NULL);
	character->texture = sfTexture_createFromFile("./img/sacha.png", NULL);
	character->sprite = sfSprite_create();
	character->rect = (sfIntRect){0,0, 68, 72};
	set_character(character);
	return (character);
}

void set_window(window_t *window)
{
	window->window = sfRenderWindow_create(window->mode,"Matches",\
	sfClose | sfResize, NULL);
	sfRenderWindow_setFramerateLimit(window->window, 60);
	sfSprite_setTexture(window->sprite, window->texture, sfTrue);
	sfSprite_setPosition(window->sprite, (sfVector2f){0, 0});
	sfSprite_setTextureRect(window->sprite, window->rect);
}

window_t *init_window(void)
{
	window_t *window = malloc(sizeof(window_t));

	if (!window)
		return (NULL);
	window->mode = (sfVideoMode){750, 750, 32};
	window->texture = sfTexture_createFromFile("./img/bg.jpg", NULL);
	window->sprite = sfSprite_create();
	window->rect = (sfIntRect){0, 0, SIZE_X, SIZE_Y};
	window->clock = sfClock_create();
	window->time = sfClock_getElapsedTime(window->clock);
	window->seconds = 0;
	set_window(window);
	return (window);
}
