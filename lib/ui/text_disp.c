/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** text disp
*/

#include "my_uilib.h"

void	disp_text(sfRenderWindow *wd, text_t *text)
{
	sfRenderWindow_drawText(wd, text->text, NULL);
}

void	disp_texts(sfRenderWindow *wd, text_t *texts, int nb)
{
	for (int i = 0; texts != NULL && i < nb; i++) {
		disp_text(wd, &texts[i]);
	}
}
