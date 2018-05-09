/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** free
*/

#include "rpg.h"

void free_npc(npc_t *npc)
{
	sfSprite_destroy(npc->s_npc[0]);
	sfSprite_destroy(npc->s_npc[1]);
	sfSprite_destroy(npc->s_arrow);
	sfTexture_destroy(npc->t_arrow);
	sfText_destroy(npc->text);
	sfFont_destroy(npc->font);
	sfClock_destroy(npc->clock);
	sfRectangleShape_destroy(npc->box);
	free_ms(npc->ms);
	free(npc);
}
