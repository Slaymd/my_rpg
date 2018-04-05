/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** main
*/

#include "rpg.h"

ennemy_t *add_ennemy_class_1(const char *path_sprite,
sfIntRect square)
{
	ennemy_t *new = malloc(sizeof(ennemy_t));
	sfVector2f size;

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
	return (new);
}

void init_sprite(rpg_t *rpg)
{
	rpg->ennemy[0] = add_ennemy_class_1(
	"ressources_ennemy/ennemy_assets/ostrich.png",
	(sfIntRect){0, 150, 100, 120});
}
