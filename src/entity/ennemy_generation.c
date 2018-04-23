/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "../../include/rpg.h"

entity_infos_t get_entity_infos(entity_type type)
{
	entity_infos_t ents_infos[] = {{OSTRICH, {0, 150, 108, 120}, 1, 1, 850,
	108, TXTRE_OSTRICH, 1, (pos_t){16020, 16010, 0}, 0, 430,
	"assets/musics/aer.ogg", 30}, {STONE_OGRE, {0, 150, 140, 155}, 1, 1, 644
	, 144, TXTRE_STONE_OGRE, 2, (pos_t){16010, 16010, 0}, 0, 720,
	"assets/musics/aer.ogg", 150}, {UNKNOWN, {0, 0, 0, 0}, 0, 0, 0, 0, "", 0
	, (pos_t){0, 0, 0}, 0, 0, "", 0}};
	for (int i = 0; ents_infos[i].type != UNKNOWN; i++) {
		if (ents_infos[i].type == type)
			return (ents_infos[i]);
	}
	return ((entity_infos_t){UNKNOWN, {0 , 0, 0, 0}, 0, 0, 0, 0, "", 0,
	(pos_t){0, 0, 0}, 0, 0, NULL, 0});
}

entity_t *init_entity(entity_t *ent, entity_infos_t infos)
{
	ent->song = sfMusic_createFromFile(infos.song);
	ent->texture = sfTexture_createFromFile(infos.tex_path, NULL);
	sfSprite_setTexture(ent->sprite, ent->texture, sfTrue);
	sfSprite_setTextureRect(ent->sprite, ent->square);
	sfSprite_setScale(ent->sprite, (sfVector2f){0.6, 0.6});
	ent->rect = sfRectangleShape_create();
	sfRectangleShape_setPosition(ent->rect, (sfVector2f){200, 200});
	sfRectangleShape_setSize(ent->rect, (sfVector2f){200, 200});
	sfRectangleShape_setFillColor(ent->rect, (sfColor){0, 0, 0, 0});
	ent->clock = sfClock_create();
	ent->time = sfClock_getElapsedTime(ent->clock);
	ent->seconds = 0;
	ent->hp = infos.hp;
	ent->hp_bar = sfRectangleShape_create();
	sfSprite_setOrigin(ent->sprite, (V2F){ent->square.width / 2,
	ent->square.height / 2});
	sfRectangleShape_setOrigin(ent->hp_bar, (V2F){25, 2.5});
	sfRectangleShape_setSize(ent->hp_bar, (V2F){50, 5});
	sfRectangleShape_setFillColor(ent->hp_bar, sfRed);
	return (ent);
}

entity_t *create_entity(entity_type type)
{
	entity_t *ent = (entity_t*)malloc(sizeof(entity_t));
	entity_infos_t infos = get_entity_infos(type);

	if (ent == NULL)
		return (NULL);
	ent->movement = infos.movement;
	ent->lvl = infos.lvl;
	ent->pos = infos.pos;
	ent->rect = NULL;
	ent->sprite = sfSprite_create();
	ent->mirror = infos.mirror;
	ent->square = infos.rect;
	ent->max = infos.max;
	ent->num = infos.num;
	ent->type = type;
	return (init_entity(ent, infos));
}

void init_sprite(rpg_t *rpg)
{
	rpg->entities = NULL;
	list_add(&rpg->entities, create_entity(OSTRICH));
	list_add(&rpg->entities, create_entity(STONE_OGRE));
}
