/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** free
*/

#include "rpg.h"

void free_htp(htp_t *htp)
{
	sfClock_destroy(htp->clock);
	sfText_destroy(htp->text);
	sfFont_destroy(htp->font);
	for (int i = 0; i < 5; i++) {
		sfSprite_destroy(htp->sprite[i].sprite);
		sfTexture_destroy(htp->sprite[i].texture);
	}
	free(htp);
}
