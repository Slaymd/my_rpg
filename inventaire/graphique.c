/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** bootstrap
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	sfRenderWindow *window;
	sfVideoMode mode = {800, 500, 32};
	sfEvent event;

	window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
	if(!window)
		return (0);

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if(event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_display (window);
	}
	sfRenderWindow_destroy(window);


	return (0);
}
