/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** button position tools
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_uilib.h"

void set_button_position(button_t *button, sfVector2f pos)
{
	if (button == NULL)
		return;
	switch(button->type) {
		case FLAT:
			sfRectangleShape_setPosition(button->rect, pos);
			break;
		case IMAGE:
			sfSprite_setPosition(button->sprite, pos);
			break;
		default:
			break;
	}
}

void set_button_size(button_t *button, sfVector2f size)
{
	sfVector2f pos = (sfVector2f){0, 0};
	sfIntRect rect = (sfIntRect){0, 0, size.x, size.y};

	if (button == NULL)
		return;
	switch(button->type) {
		case FLAT:
			sfRectangleShape_setSize(button->rect, size);
			break;
		case IMAGE:
			pos = get_button_position(button);
			rect.left = pos.x;
			rect.top = pos.y;
			sfSprite_setTextureRect(button->sprite, rect);
			break;
		default:
			break;
	}
}

sfVector2f get_button_position(button_t *button)
{
	sfVector2f pos = (sfVector2f){0, 0};

	if (button == NULL)
		return (pos);
	switch(button->type) {
		case FLAT:
			pos = sfRectangleShape_getPosition(button->rect);
			break;
		case IMAGE:
			pos = sfSprite_getPosition(button->sprite);
			break;
		default:
			break;
	}
	return (pos);
}

sfVector2f get_button_size(button_t *button)
{
	sfVector2f size = (sfVector2f){0, 0};
	sfIntRect imgrect = (sfIntRect){0, 0, 0, 0};

	if (button == NULL)
		return (size);
	switch(button->type) {
		case FLAT:
			size = sfRectangleShape_getSize(button->rect);
			break;
		case IMAGE:
			imgrect = sfSprite_getTextureRect(button->sprite);
			size = (sfVector2f) {imgrect.width, imgrect.height};
			break;
		default:
			break;
	}
	return (size);
}
