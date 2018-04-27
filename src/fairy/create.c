/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** create
*/

#include "rpg.h"

void new_shoot(list_shoot_t *list, pos_t pos_e, pos_t pos_r, rpg_t *rpg)
{
	shoot_t *new = malloc(sizeof(shoot_t));

	if (!new)
		return;
	new->rect = (sfIntRect){0, 0, EXPLO_X, EXPLO_Y};
	new->state = 0;
	new->pos_e = (pos_t){pos_e.x + rpg->map->center.x,
	pos_e.y + rpg->map->center.y, pos_e.z};
	new->pos_r = (pos_t){rpg->map->center.x + pos_r.x,
	rpg->map->center.y + pos_r.y, pos_r.z};
	new->distance = (V2F){new->pos_e.x - new->pos_r.x,
	new->pos_e.y - new->pos_r.y};
	new->angle = acos(new->distance.x / sqrt(pow(new->distance.y, 2) +
	pow(new->distance.x, 2))) * 180 / M_PI + 90;
	(new->distance.y < 0) ? new->angle += 180, new->angle *= -1 : 0;
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
			tmp->next = (tmp->next->next) ? tmp->next->next : NULL;
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
	sfSprite_setOrigin(fairy->sprite, (V2F){SIZE_F_X / 2, SIZE_F_Y / 2});
	sfSprite_setTexture(fairy->s_explo, fairy->t_explo, sfTrue);
	sfSprite_setOrigin(fairy->s_explo, (V2F){EXPLO_X / 2, EXPLO_Y / 2});
	sfSprite_setScale(fairy->s_explo, (V2F){0.5, 0.5});
	sfSprite_setTexture(fairy->s_rocket, fairy->t_rocket, sfTrue);
	sfSprite_setOrigin(fairy->s_rocket, (V2F){ROCKET_X / 2, ROCKET_Y / 2});
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
	fairy->t_rocket = sfTexture_createFromFile("./img/rocket.png", NULL);
	fairy->s_rocket = sfSprite_create();
	fairy->shoot = malloc(sizeof(list_shoot_t));
	fairy->particle = create_particle(76, 76);
	fairy->line = sfVertexArray_create();
	fairy->shhh = sfMusic_createFromFile("assets/musics/shhh.ogg");
	set_fairy(fairy);
	return (fairy);
}
