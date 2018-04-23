/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** create
*/

#include "rpg.h"

void new_shoot(list_shoot_t *list, pos_t pos, rpg_t *rpg)
{
	shoot_t *new = malloc(sizeof(shoot_t));

	if (!new)
		return;
	new->rect = (sfIntRect){0, 0, EXPLO_X, EXPLO_Y};
	new->pos = (pos_t){pos.x + rpg->map->topleft_to_disp.x,
	pos.y + rpg->map->topleft_to_disp.y, pos.z};
	new->next = list->first;
	list->first = new;
}

void end_shoot(list_shoot_t *list)
{
	shoot_t *tmp = list->first;
	shoot_t *delete;

	while (tmp && tmp->next) {
		if (tmp->next->rect.left >= 4800) {
			delete = tmp->next;
			if (tmp->next->next)
				tmp->next = tmp->next->next;
			else
				tmp->next = NULL;
			free(delete);
		}
		tmp = tmp->next;
	}
}

void set_fairy(fairy_t *fairy)
{
	sfSprite_setTexture(fairy->sprite, fairy->texture, sfTrue);
	sfSprite_setPosition(fairy->sprite, fairy->pos);
	sfSprite_setTextureRect(fairy->sprite, fairy->rect);
	sfSprite_setScale(fairy->sprite, (V2F){ZOOM, ZOOM});
	sfSprite_setOrigin(fairy->sprite, (V2F){SIZE_F_X / 2 * ZOOM,
	SIZE_F_Y / 2 * ZOOM});
	sfSprite_setTexture(fairy->s_explo, fairy->t_explo, sfTrue);
	sfSprite_setOrigin(fairy->s_explo, (V2F){EXPLO_X / 2, EXPLO_Y / 2});
	sfSprite_setScale(fairy->s_explo, (V2F){0.5, 0.5});
	fairy->shoot->first = NULL;
}

fairy_t *init_fairy(void)
{
	fairy_t *fairy = malloc(sizeof(fairy_t));

	fairy->texture = sfTexture_createFromFile("./img/fairy.png", NULL);
	fairy->sprite = sfSprite_create();
	fairy->clock = sfClock_create();
	fairy->time = sfClock_getElapsedTime(fairy->clock);
	fairy->seconds = 0;
	fairy->ec = (sfVector2f){0, 0};
	fairy->ep = (sfVector2f){0, 0};
	fairy->pos = (sfVector2f){WIDTH / 2 + 20, HEIGHT / 2 + 20};
	fairy->rect = (sfIntRect){0,0, SIZE_F_X, SIZE_F_Y};
	fairy->t_explo = sfTexture_createFromFile("./img/explosion.png", NULL);
	fairy->s_explo = sfSprite_create();
	fairy->shoot = malloc(sizeof(list_shoot_t));
	fairy->line = sfVertexArray_create();
	fairy->shhh = sfMusic_createFromFile("assets/musics/shhh.ogg");
	set_fairy(fairy);
	return (fairy);
}
