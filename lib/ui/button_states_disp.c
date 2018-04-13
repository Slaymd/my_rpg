/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** states disp
*/

#include "uilib.h"

int	set_button_state(button_t *button, int state)
{
	bt_state_t btst;

	if (state < 0 || button == NULL || state >= button->nb_states)
		return (84);
	if (state == button->state)
		return (0);
	btst = button->states[state];
	button->state = state;
	set_button_color(button, btst.fill_color, btst.outline_color);
	if (button->text != NULL && btst.text != NULL)
		set_text_string(button->text, btst.text);
	if (btst.action != NULL) {
		button->action = btst.action;
		button->params = btst.params;
	}
	return (1);
}

void	switch_button_state(void *ptr)
{
	button_t *button = (button_t*)ptr;
	int state = button->state + 1;

	if (state == button->nb_states)
		state = 0;
	set_button_state(button, state);
}
