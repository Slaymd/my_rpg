/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** bootstrap
*/

#include "struct.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <stdio.h>

carac_t *create_perso(const char *sprite, int x, int y)
{
	carac_t *carac = malloc(sizeof(carac_t));
	carac->sperso = sfSprite_create();
	carac->tperso = sfTexture_createFromFile(sprite, NULL);
	sfSprite_setTexture (carac->sperso, carac->tperso, sfTrue);
	carac->posperso.x = x;
	carac->posperso.y = y;
	carac->rectperso.left = 0;
	carac->rectperso.top = 0;
	carac->rectperso.width = 50;
	carac->rectperso.height = 50;
	sfSprite_setTextureRect(carac->sperso, carac->rectperso);
	sfSprite_setPosition(carac->sperso, carac->posperso);
	return (carac);
}

void moverect(carac_t *perso, int cpt)
{
	static int move = 0;
	if (cpt == 1) {
		move = 0;
		perso->rectperso.left = 0;
	}
	if (move < 2) {
		perso->rectperso.left += 50;
		move += 1;
	} else if (move < 3){
		perso->rectperso.left -= 50;
		move += 1;
	}else {
		perso->rectperso.left = 0;
		move = 0;
	}
	sfSprite_setTextureRect(perso->sperso, perso->rectperso);
}

int movepos(carac_t **perso, int num)
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		num = 0;
		perso[0]->posperso.x -= 0.2;
		perso[1]->posperso.x -= 0.2;
		perso[2]->posperso.x -= 0.2;
		perso[3]->posperso.x -= 0.2;
	}
	if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		num = 1;
		perso[0]->posperso.x += 0.2;
		perso[1]->posperso.x += 0.2;
		perso[2]->posperso.x += 0.2;
		perso[3]->posperso.x += 0.2;
	}
	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		num = 2;
		perso[0]->posperso.y -= 0.2;
		perso[1]->posperso.y -= 0.2;
		perso[2]->posperso.y -= 0.2;
		perso[3]->posperso.y -= 0.2;
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		num = 3;
		perso[0]->posperso.y += 0.2;
		perso[1]->posperso.y += 0.2;
		perso[2]->posperso.y += 0.2;
		perso[3]->posperso.y += 0.2;
	}
	sfSprite_setPosition(perso[0]->sperso, perso[0]->posperso);
	sfSprite_setPosition(perso[1]->sperso, perso[1]->posperso);
	sfSprite_setPosition(perso[2]->sperso, perso[2]->posperso);
	sfSprite_setPosition(perso[3]->sperso, perso[3]->posperso);
	return (num);
}

int main (void)
{
	sfRenderWindow *window;
	sfVideoMode mode = {800, 500, 32};
	carac_t **tabperso = malloc(sizeof(carac_t *) * 5);
	sfEvent event;
	sfClock *clock = sfClock_create();
	sfTime time;
	float seconds = 0;
	int numperso = 0;
	int numprec = 0;
	int cpt = 0;

	window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
	if(!window)
		return (0);
	tabperso[0] = create_perso("sprite/zelda_left.png", 10, 10);
	tabperso[1] = create_perso("sprite/zelda_right.png", 10, 10);
	tabperso[2] = create_perso("sprite/zelda_top.png", 10, 10);
	tabperso[3] = create_perso("sprite/zelda_down.png", 10, 10);
	while (sfRenderWindow_isOpen(window)) {
		time = sfClock_getElapsedTime(clock);
		seconds = time.microseconds / 1000000.0;
		while (sfRenderWindow_pollEvent(window, &event)) {
			if(event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		numprec = numperso;
		numperso = movepos(tabperso, numperso);
		if (numprec != numperso)
			cpt = 1;
		if (seconds > 0.1) {
			moverect(tabperso[numperso], cpt);
			cpt = 0;
			sfClock_restart(clock);
		}
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, tabperso[numperso]->sperso, NULL);
		sfRenderWindow_display (window);
	}
	sfRenderWindow_destroy(window);


	return (0);
}
