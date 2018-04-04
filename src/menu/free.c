/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** menu
*/

#include "rpg.h"

void free_menu(menu_t *m)
{
	for (int i = 0; m->scene[i]; i++) {
		sfTexture_destroy(m->scene[i]->texture);
		sfSprite_destroy(m->scene[i]->sprite);
		for (int j = 0; m->scene[i]->button[j]; j++) {
			sfRectangleShape_destroy(m->scene[i]->button[j]->rect);
			sfTexture_destroy(m->scene[i]->button[j]->texture);
			sfSprite_destroy(m->scene[i]->button[j]->sprite);
			free(m->scene[i]->button[j]);
		}
		free(m->scene[i]->button);
		for (int j = 0; m->scene[i]->text[j]; j++) {
			sfText_destroy(m->scene[i]->text[j]->text);
			sfFont_destroy(m->scene[i]->text[j]->font);
			free(m->scene[i]->text[j]);
		}
		free(m->scene[i]->text);
	free(m->scene[i]);
	}
	free(m->scene);
	free(m);
}
