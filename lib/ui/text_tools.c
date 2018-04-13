/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** text tools
*/

#include "my_uilib.h"
char *my_strcpy(char *, char *);

char	*get_text_string(text_t *text)
{
	if (text == NULL)
		return (NULL);
	return ((char*)sfText_getString(text->text));
}

void	set_text_string(text_t *text, char *str)
{
	if (text == NULL)
		return;
	sfText_setString(text->text, str);
}

void set_text_position(text_t *text, sfVector2f pos)
{
	if (text == NULL)
		return;
	sfText_setPosition(text->text, pos);
}

void	set_text_font(text_t *text, char *fontpath)
{
	sfFont *font = sfFont_createFromFile(fontpath);

	if (font == NULL)
		return;
	if (text->font != NULL)
		sfFont_destroy(text->font);
	text->font = font;
	sfText_setFont(text->text, text->font);
}

void	set_text_size(text_t *text, int size)
{
	sfText_setCharacterSize(text->text, size);
}
