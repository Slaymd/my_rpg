/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** hud
*/

#include "rpg.h"

hud_t *create_hud(void)
{
	hud_t *hud = malloc(sizeof(hud_t));

	if (!hud)
		return (NULL);
	hud->f_hud = sfFont_createFromFile(FONT_UBUREG);
	hud->t_coo = sfText_create();
	sfText_setFont(hud->t_coo, hud->f_hud);
	sfText_setCharacterSize(hud->t_coo, 20);
	return (hud);
}
