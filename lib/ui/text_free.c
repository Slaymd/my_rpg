/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** text free
*/

#include "uilib.h"

void free_text(text_t *text)
{
	sfFont_destroy(text->font);
	sfText_destroy(text->text);
	free(text);
}
