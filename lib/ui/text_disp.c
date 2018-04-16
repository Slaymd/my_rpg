/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** text disp
*/

#include "uilib.h"

void	disp_text(sfRenderWindow *wd, text_t *text)
{
	sfRenderWindow_drawText(wd, text->text, NULL);
}

void	disp_texts(sfRenderWindow *wd, list_t *texts)
{
	list_t *tmp = texts;

	for (; tmp != NULL; tmp = tmp->next)
		disp_text(wd, (text_t*)tmp->data);
}
