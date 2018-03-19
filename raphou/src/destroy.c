/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** free
*/

#include "proto.h"

void my_free(window_t *window, character_t *character)
{
	sfRenderWindow_destroy(window->window);
	sfTexture_destroy(window->texture);
	sfSprite_destroy(window->sprite);
	sfClock_destroy(window->clock);
	free(window);

	sfTexture_destroy(character->texture);
	sfSprite_destroy(character->sprite);
	free(character);
}
