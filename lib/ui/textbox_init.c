/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** textbox init
*/

#include "uilib.h"

textbox_t	*create_textbox(sfIntRect rect, sfColor fill, sfColor outl)
{
	textbox_t *textbox = (textbox_t*)malloc(sizeof(textbox_t));
	sfVector2f size = (sfVector2f){rect.width, rect.height};
	sfVector2f pos = (sfVector2f){rect.left, rect.top};
	sfVector2f textpos = (sfVector2f){pos.x+5,pos.y-rect.height*0.11};

	if (textbox == NULL)
		return (NULL);
	textbox->rect = sfRectangleShape_create();
	sfRectangleShape_setSize(textbox->rect, size);
	sfRectangleShape_setPosition(textbox->rect, pos);
	sfRectangleShape_setFillColor(textbox->rect, fill);
	sfRectangleShape_setOutlineColor(textbox->rect, outl);
	textbox->outl_color = outl;
	sfRectangleShape_setOutlineThickness(textbox->rect, 4);
	textbox->text = create_text(pos, "", rect.height-4, sfWhite);
	set_text_position(textbox->text, textpos);
	textbox->type = ALL;
	return (textbox);
}
