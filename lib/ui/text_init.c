/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** text init
*/

#include "uilib.h"

text_t	*create_text(sfVector2f pos, char *str, int size, sfColor color)
{
	text_t *text = (text_t*)malloc(sizeof(text_t));
	sfFont *font = sfFont_createFromFile(DEFAULT_FONT);

	if (text == NULL || font == NULL)
		return (NULL);
	text->font = font;
	text->text = sfText_create();
	if (text->text == NULL) {
		free(text);
		return (NULL);
	}
	sfText_setFont(text->text, font);
	sfText_setCharacterSize(text->text, size);
	sfText_setString(text->text, str);
	sfText_setPosition(text->text, pos);
	sfText_setColor(text->text, color);
	text->fontsize = size;
	return (text);
}
