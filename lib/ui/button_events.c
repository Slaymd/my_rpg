/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** button events
*/

#include "uilib.h"

int	check_pos_in_button(button_t *button, sfVector2f pos)
{
	sfVector2f bpos = get_button_position(button);
	sfVector2f bsize = get_button_size(button);

	if (button != NULL && pos.x >= bpos.x && pos.y >= bpos.y)
		if (pos.x <= bpos.x+bsize.x && pos.y <= bpos.y+bsize.y)
			return (1);
	return (0);
}

int	send_click_action(button_t *button)
{
	if (button->nb_states > 0) {
		switch_button_state(button);
		return (1);
	}
	if (button->action != NULL)
		button->action(button->params);
	return (1);
}

int	click_on_buttons(sfEvent event, list_t *buttons)
{
	list_t *tmp = buttons;
	button_t *button = NULL;
	sfVector2f pos = {event.mouseButton.x, event.mouseButton.y};

	for (; tmp != NULL; tmp = tmp->next) {
		button = (button_t*)tmp->data;
		if (check_pos_in_button(button, pos)) {
			send_click_action(button);
			return (1);
		}
	}
	return (0);
}

int	hover_on_buttons(sfEvent event, list_t *buttons)
{
	list_t *tmp = buttons;
	button_t *button = NULL;
	sfVector2f pos = {event.mouseMove.x, event.mouseMove.y};

	for (; tmp != NULL; tmp = tmp->next) {
		button = (button_t*)tmp->data;
		if (check_pos_in_button(button, pos))
			set_button_hover_design(button);
		else
			rem_button_hover_design(button);
	}
	return (0);
}
