/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** textbox events
*/

#include "uilib.h"

int	check_pos_in_textbox(textbox_t *textbox, sfVector2f pos)
{
	sfVector2f tpos = get_textbox_position(textbox);
	sfVector2f tsize = get_textbox_size(textbox);

	if (textbox != NULL && pos.x >= tpos.x && pos.y >= tpos.y)
		if (pos.x <= tpos.x+tsize.x && pos.y <= tpos.y+tsize.y)
			return (1);
	return (0);
}

int	click_on_textboxes(sfEvent event, list_t *textboxes)
{
	textbox_t *textbox = NULL;
	list_t *tmp = textboxes;
	sfVector2f pos = {event.mouseButton.x, event.mouseButton.y};

	for (; tmp != NULL; tmp = tmp->next) {
		textbox = (textbox_t*)tmp->data;
		if (check_pos_in_textbox(textbox, pos))
			textbox->state = textbox->state == 1 ? 0 : 1;
		else
			textbox->state = 0;
	}
	return (0);
}
