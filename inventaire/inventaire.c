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

void display_sprite(sfRenderWindow *window, carac_t **tabperso, sfSprite *sinv)
{
	// sfRenderWindow_clear(window, sfBlack);
	printf("on entre dans display\n");
	sfRenderWindow_drawSprite(window, sinv, NULL);
	for (int cpt = 0; cpt < 4; cpt++)
		sfRenderWindow_drawSprite(window, tabperso[cpt]->sperso, NULL);
	sfRenderWindow_display (window);
}

int if_m_in_sprite(sfVector2i pos_m, carac_t **tabperso)
{
	for (int cpt = 0; cpt < 4; cpt++) {
		if (pos_m.x > tabperso[cpt]->posperso.x &&
			pos_m.x < tabperso[cpt]->posperso.x + 50 &&
			pos_m.y > tabperso[cpt]->posperso.y &&
			pos_m.y < tabperso[cpt]->posperso.y + 50)
			return (cpt);
	}
	return (-1);
}

void replacement(sfRenderWindow *window, carac_t **tabperso, sfSprite *sinv)
{
	for (int cpt = 0; cpt < 4; cpt++) {
		for(; ((int)tabperso[cpt]->posperso.x + 25) % 50 != 0; tabperso[cpt]->posperso.x--);
		if ((tabperso[cpt]->posperso.x) < 0)
			tabperso[cpt]->posperso.x = 25;
		for(; ((int)tabperso[cpt]->posperso.y + 25) % 50 != 0; tabperso[cpt]->posperso.y--);
		if ((tabperso[cpt]->posperso.y) < 0)
			tabperso[cpt]->posperso.y = 25;
		// for (int lol = 0; lol < 4; lol++) {
		// 	if (lol == cpt && lol != 3)
		// 		lol++;
		// 	else if (lol == cpt && lol == 3)
		// 		break;
		// 	if (tabperso[cpt]->posperso.x == tabperso[lol]->posperso.x && tabperso[cpt]->posperso.y == tabperso[lol]->posperso.y)
		// 		tabperso[cpt]->posperso.x += 50;
		// }
		sfSprite_setTextureRect(tabperso[cpt]->sperso, tabperso[cpt]->rectperso);
		sfSprite_setPosition(tabperso[cpt]->sperso, tabperso[cpt]->posperso);
	}
	display_sprite(window, tabperso, sinv);
}

void mouse_click(sfRenderWindow *window, sfEvent *event, carac_t **tabperso, sfSprite *sinv)
{
	sfVector2i pos_m;
	int num_sprite = -1;

	pos_m.x = 0;
	pos_m.y = 0;
	pos_m = sfMouse_getPosition((sfWindow*) window);
	printf("x = %d et y = %d\n",pos_m.x, pos_m.y);
	num_sprite = if_m_in_sprite(pos_m, tabperso);
	while (num_sprite >= 0 && sfMouse_isButtonPressed(sfMouseLeft)) {
		pos_m = sfMouse_getPosition((sfWindow*) window);
		tabperso[num_sprite]->posperso.x = pos_m.x - 25;
		tabperso[num_sprite]->posperso.y = pos_m.y - 25;
		sfSprite_setTextureRect(tabperso[num_sprite]->sperso, tabperso[num_sprite]->rectperso);
		sfSprite_setPosition(tabperso[num_sprite]->sperso, tabperso[num_sprite]->posperso);
		display_sprite(window, tabperso, sinv);
	}
	replacement(window, tabperso, sinv);
}

void analyse_events(sfRenderWindow *window, sfEvent *event, carac_t **tabperso)
{
	while (sfRenderWindow_pollEvent(window, event)) {
		if (event->type == sfEvtClosed)
			sfRenderWindow_close(window);
	}
}

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

void game (sfRenderWindow *window, sfEvent *event, carac_t **tabperso)
{
	int isok = 0;

	if (sfKeyboard_isKeyPressed(sfKeyE)) {
		printf("inventaire\n");
		sfSprite *sinv = sfSprite_create();
		sfTexture *tinv = sfTexture_createFromFile("inventaire.jpg", NULL);
		sfSprite_setTexture(sinv, tinv, sfTrue);
		sfSprite_setPosition(sinv, (sfVector2f){0,0});
		while (isok == 0) {
			while (sfRenderWindow_pollEvent(window, event)) {
				// sfRenderWindow_clear(window, sfBlack);
				sfRenderWindow_drawSprite(window, sinv, NULL);
				sfRenderWindow_display (window);
				if (sfKeyboard_isKeyPressed(sfKeyEscape))
					isok = 1;
				if (event->type == sfEvtMouseButtonPressed)
					mouse_click(window, event, tabperso, sinv);
			}
		}
		printf("on sort\n");
	}
}

int main (void)
{
	sfRenderWindow *window;
	sfVideoMode mode = {800, 500, 32};
	sfSprite *sfond = sfSprite_create();
	sfTexture *tfond = sfTexture_createFromFile("fond.png", NULL);
	sfSprite_setTexture(sfond, tfond, sfTrue);
	sfSprite_setPosition(sfond, (sfVector2f){0,0});
	carac_t **tabperso = malloc(sizeof(carac_t *) * 5);
	sfEvent event;
	sfClock *clock = sfClock_create();
	sfTime time;
	float seconds = 0;

	window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
	if(!window)
		return (0);
	tabperso[0] = create_perso("sprite/zelda_left.png", 10, 70);
	tabperso[1] = create_perso("sprite/zelda_right.png", 20, 130);
	tabperso[2] = create_perso("sprite/zelda_top.png", 30, 190);
	tabperso[3] = create_perso("sprite/zelda_down.png", 40, 250);
	while (sfRenderWindow_isOpen(window)) {
		time = sfClock_getElapsedTime(clock);
		seconds = time.microseconds / 1000000.0;
		analyse_events(window, &event, tabperso);
		game(window, &event, tabperso);
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, sfond, NULL);
		sfRenderWindow_display (window);
	}
	sfRenderWindow_destroy(window);
	return (0);
}
