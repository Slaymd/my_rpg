/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** init
*/

#include "proto.h"

void set_character(character_t *character)
{
	sfSprite_setTexture(character->sprite, character->texture, sfTrue);
	sfSprite_setPosition(character->sprite, character->pos);
	sfSprite_setTextureRect(character->sprite, character->rect);
}

character_t *init_character(void)
{
	character_t *character = malloc(sizeof(character_t));
	int x = SIZE_SCREEN_X / 2 - SIZE_PERSO_X / 2;
	int y = SIZE_SCREEN_Y / 2 - SIZE_PERSO_Y / 2;

	if (!character)
		return (NULL);
	character->texture = sfTexture_createFromFile("./img/sacha.png", NULL);
	character->sprite = sfSprite_create();
	character->rect = (sfIntRect){0,0, SIZE_PERSO_X, SIZE_PERSO_Y};
	character->speed = 4;
	character->pos = (sfVector2f){x, y};
	set_character(character);
	return (character);
}

void set_window(window_t *window)
{
	window->window = sfRenderWindow_create(window->mode,"RPG",\
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
	window->mode = (sfVideoMode){SIZE_SCREEN_X, SIZE_SCREEN_X, 32};
	window->texture = sfTexture_createFromFile("./img/bg.jpg", NULL);
	window->sprite = sfSprite_create();
	window->rect = (sfIntRect){0, 0, SIZE_SCREEN_X, SIZE_SCREEN_Y};
	window->clock = sfClock_create();
	window->time = sfClock_getElapsedTime(window->clock);
	window->seconds = 0;
	set_window(window);
	return (window);
}
