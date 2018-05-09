/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** npc
*/

#include "rpg.h"

sfSprite *npc_sprite(char *path)
{
	sfSprite *sprite = sfSprite_create();
	sfTexture *texture = sfTexture_createFromFile(path, NULL);

	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setPosition(sprite, (V2F){200, 200});
	return (sprite);
}

void set_npc(npc_t *npc)
{
	sfRectangleShape_setSize(npc->box, (V2F){WIDTH - 8, HEIGHT / 6 - 8});
	sfRectangleShape_setPosition(npc->box, (V2F){4, HEIGHT / 6 * 5 + 4});
	sfRectangleShape_setOutlineThickness(npc->box, 5);
	sfRectangleShape_setOutlineColor(npc->box, sfBlack);
	sfText_setFont(npc->text, npc->font);
	sfText_setCharacterSize(npc->text, 20);
	sfText_setColor(npc->text, sfBlack);
	sfSprite_setTexture(npc->s_arrow, npc->t_arrow, sfTrue);
	sfSprite_setOrigin(npc->s_arrow, (V2F){15 / 2, 15 / 2});
}

npc_t *create_npc(void)
{
	npc_t *npc = malloc(sizeof(npc_t));

	npc->s_npc[0] = npc_sprite(NPC_GAME);
	npc->s_npc[1] = npc_sprite(NPC_KID);
	npc->box = sfRectangleShape_create();
	npc->text = sfText_create();
	npc->s_arrow = sfSprite_create();
	npc->t_arrow = sfTexture_createFromFile(TXTR_ARROW, NULL);
	npc->select = 0;
	npc->used = 0;
	npc->font = sfFont_createFromFile(FONT_UBUREG);
	npc->clock = sfClock_create();
	npc->time = sfClock_getElapsedTime(npc->clock);
	npc->seconds = 0;
	set_npc(npc);
	return (npc);
}
