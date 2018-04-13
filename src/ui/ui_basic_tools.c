/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** ui basic tools
*/

#include "../../include/rpg.h"

sfRenderWindow	*create_window(void)
{
	sfRenderWindow	*window;
	sfVideoMode	mode;

	mode.width = WIDTH;
	mode.height = HEIGHT;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "my_rpg", sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(window, 60);
	return (window);
}
