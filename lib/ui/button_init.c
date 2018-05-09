/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** button initialisation
*/

#include "uilib.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

button_t	*create_void_button(void)
{
	button_t *button = (button_t*)malloc(sizeof(*button));

	if (button == NULL)
		return (NULL);
	button->rect = NULL;
	button->text = NULL;
	button->sprite = NULL;
	button->tooltip = NULL;
	button->states = NULL;
	button->state = 0;
	return (button);
}

button_t	*create_flat_button(sfIntRect pos, sfColor fill,
	sfColor outl, char *str)
{
	button_t *button = create_void_button();
	sfVector2f hard_pos = (sfVector2f){pos.left, pos.top};
	sfVector2f hard_size = (sfVector2f){pos.width, pos.height};

	if (button == NULL)
		return (NULL);
	button->rect = sfRectangleShape_create();
	sfRectangleShape_setSize(button->rect, hard_size);
	sfRectangleShape_setPosition(button->rect, hard_pos);
	sfRectangleShape_setFillColor(button->rect, fill);
	sfRectangleShape_setOutlineColor(button->rect, outl);
	sfRectangleShape_setOutlineThickness(button->rect, 4);
	hard_pos.x += 10;
	button->text = create_text(hard_pos, str, hard_size.y*0.72, outl);
	button->type = FLAT;
	return (button);
}
