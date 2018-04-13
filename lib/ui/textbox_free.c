/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** textbox free
*/

#include "my_uilib.h"

void	free_textbox(textbox_t *textbox)
{
	if (textbox == NULL)
		return;
	if (textbox->text != NULL)
		free_text(textbox->text);
	if (textbox->rect != NULL)
		sfRectangleShape_destroy(textbox->rect);
	free(textbox);
}
