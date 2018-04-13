/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** textbox events
*/

#include "my_uilib.h"

int	check_pos_in_textbox(textbox_t *textbox, sfVector2f pos)
{
	sfVector2f tpos = get_textbox_position(textbox);
	sfVector2f tsize = get_textbox_size(textbox);

	if (textbox != NULL && pos.x >= tpos.x && pos.y >= tpos.y)
		if (pos.x <= tpos.x+tsize.x && pos.y <= tpos.y+tsize.y)
			return (1);
	return (0);
}

int	click_on_textboxes(sfEvent event, textbox_t *textboxes, int nb)
{
	sfVector2f pos = {event.mouseButton.x, event.mouseButton.y};

	for (int i = 0; i < nb; i++) {
		if (check_pos_in_textbox(&textboxes[i], pos))
			textboxes[i].state = textboxes[i].state == 1 ? 0 : 1;
		else
			textboxes[i].state = 0;
	}
	return (0);
}
