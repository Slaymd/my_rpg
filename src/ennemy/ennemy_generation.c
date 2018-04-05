/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../../include/rpg.h"

entity_infos_t get_entity_infos(entity_type type)
{
	entity_infos_t ents_infos[] = {{OSTRICH,{0,0,0,0},1,1,1,1,ENT_OSTRICH},
		{UNKNOWN,{0,0,0,0},0,0,0}};

	for (int i = 0; ents_infos[i].type != UNKNOWN; i++) {
		if (ents_infos[i].type == OSTRICH)
			return (ents_infos[i]);
	}
	return ((entity_infos_t){UNKNOWN,0,0,0});
}

entity_t *create_entity(entity_type type)
{
	entity_t *ent = (entity_t*)malloc(sizeof(entity_t));
	entity_infos_t infos = get_entity_infos(type);

	if (ent == NULL)
		return (NULL);
	ent->ennemy_range = infos.range;
	ent->callback = NULL;
	ent->lvl = infos.level;
	ent->pos = (pos_t){0, 0, 0};
	ent->rect = NULL;
	ent->sprite = NULL; //À FAIRE ! LOAD SPRITE DE BASE
	ent->square = infos.rect;
	ent->texture = NULL; //À FAIRE ! LOAD DE TEXTUTE infos.tex_path
	ent->type = type;
	return (ent);
}

entity_t *add_ennemy_class_1(const char *path_sprite, sfIntRect square)
{
	entity_t *new = (entity_t*)malloc(sizeof(entity_t));
	sfVector2f size = {0,0};

	if (new == NULL)
		return (NULL);
	for (int i = 0; i == 0; i = 1, size.x = square.width, size.y =
	square.height, new->lvl = 0, new->type = 1, new->ennemy_range = 0,
	new->stat = 1103101);
	new->sprite = sfSprite_create();
	new->texture = sfTexture_createFromFile(path_sprite, NULL);
	new->square = square;
	new->pos = (pos_t){16000, 16000, 0};
	sfSprite_setTexture(new->sprite, new->texture, sfTrue);
	sfSprite_setTextureRect(new->sprite, new->square);
	sfSprite_setScale(new->sprite, (sfVector2f){0.6, 0.6});
	return (new);
}

void init_sprite(rpg_t *rpg)
{
	rpg->ennemy[0] = add_ennemy_class_1(ENT_OSTRICH, (sfIntRect){0, 150, 100, 120});
}
