/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** create
*/

#include "rpg.h"

void set_fairy(fairy_t *fairy)
{
	sfSprite_setTexture(fairy->sprite, fairy->texture, sfTrue);
	sfSprite_setPosition(fairy->sprite, fairy->pos);
	sfSprite_setTextureRect(fairy->sprite, fairy->rect);
	sfSprite_setOrigin(fairy->sprite, (V2F){SIZE_F_X / 2, SIZE_F_Y / 2});
}

fairy_t *init_fairy(void)
{
	fairy_t *fairy = malloc(sizeof(fairy_t));
	int x = WIDTH / 2 + 20;
	int y = HEIGHT / 2 + 20;

	fairy->texture = sfTexture_createFromFile("./img/fairy.png", NULL);
	fairy->sprite = sfSprite_create();
	fairy->clock = sfClock_create();
	fairy->time = sfClock_getElapsedTime(fairy->clock);
	fairy->seconds = 0;
	fairy->ec = (sfVector2f){0, 0};
	fairy->ep = (sfVector2f){0, 0};
	fairy->pos = (sfVector2f){x, y};
	fairy->rect = (sfIntRect){0,0, SIZE_F_X, SIZE_F_Y};
	fairy->line = sfVertexArray_create();
	fairy->shhh = sfMusic_createFromFile("assets/musics/boom.ogg");
	set_fairy(fairy);
	return (fairy);
}
