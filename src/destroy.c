/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** free
*/

#include "rpg.h"

void free_fairy(fairy_t *fairy)
{
	sfSprite_destroy(fairy->sprite);
	sfTexture_destroy(fairy->texture);
	sfSprite_destroy(fairy->s_explo);
	sfTexture_destroy(fairy->t_explo);
	sfSprite_destroy(fairy->s_rocket);
	sfTexture_destroy(fairy->t_rocket);
	sfClock_destroy(fairy->clock);
	sfMusic_destroy(fairy->shhh);
	sfVertexArray_destroy(fairy->line);
	destroy_particle(fairy->particle);
	if (fairy->shoot)
		free(fairy->shoot);
	free(fairy);
}

void free_character(character_t *character)
{
	sfSprite_destroy(character->sprite);
	sfTexture_destroy(character->texture);
	sfClock_destroy(character->clock);
	sfRectangleShape_destroy(character->hp_bar);
	free(character);
}

void free_entity(rpg_t *rpg)
{
	list_t *tmp = rpg->entities;
	list_t *tmp_next = NULL;

	for (; tmp != NULL; tmp = tmp_next) {
		tmp_next = tmp->next;
		sfSprite_destroy(((entity_t *)tmp->data)->sprite);
		sfTexture_destroy(((entity_t *)tmp->data)->texture);
		sfClock_destroy(((entity_t *)tmp->data)->clock);
		sfRectangleShape_destroy(((entity_t *)tmp->data)->rect);
		sfMusic_destroy(((entity_t *)tmp->data)->song);
		free(tmp->data);
		free(tmp);
	}
}

void free_rpg(rpg_t *rpg)
{
	sfRenderWindow_destroy(rpg->wd);
	free_fairy(rpg->fairy);
	free_entity(rpg);
	free_character(rpg->character);
}
