/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** object gen
*/

#include "../../../include/rpg.h"

char	*get_object_texture_path(object_stats_t *obj_stats)
{
	char **txts = obj_stats->txt_paths;
	int txtnb = 0;
	int rd_txt = 0;

	for (; txts != NULL && txts[txtnb] != NULL; txtnb++);
	rd_txt = rand_time(0, txtnb);
	return (txts[rd_txt]);
}

sfSprite *get_sprite_from_texture_path(char *path)
{
	sfTexture *txt = NULL;
	sfSprite *sprite = NULL;

	if (path == NULL)
		return (NULL);
	txt = sfTexture_createFromFile(path, NULL);
	if (txt == NULL)
		return (NULL);
	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, txt, sfTrue);
	return (sprite);
}

int	generate_object(map_t *map, object_stats_t *obj_stats, pos_t pos)
{
	object_t *obj = (object_t*)malloc(sizeof(object_t));
	int freq = obj_stats->freq*1000;
	int rd_freq = rand_time(0, 1001);
	float scale = (float)TILE_SIZE/16;

	if (rd_freq > freq)
		return (free_object(obj));
	obj->txt_path = get_object_texture_path(obj_stats);
	obj->sprite = get_sprite_from_texture_path(obj->txt_path);
	sfSprite_setScale(obj->sprite, (sfVector2f){scale,scale});
	if (!can_be_placed_here(map, obj->sprite, pos))
		return (free_object(obj));
	obj->pos = (pos_t){pos.x+0.5, pos.y+0.5, 0};
	obj->type = obj_stats->type;
	list_add(&map->objects, obj);
	return (1);
}

int	generate_tile_objects(map_t *map, pos_t pos, int txt_id)
{
	list_t *tmp = map->obj_stats;
	object_stats_t *obj_stats = NULL;

	for (; tmp != NULL; tmp = tmp->next) {
		obj_stats = (object_stats_t*)tmp->data;
		if (obj_stats->spawn_type == TILE && obj_stats->data == txt_id &&
		generate_object(map, obj_stats, pos))
			break;
	}
	return (0);
}
