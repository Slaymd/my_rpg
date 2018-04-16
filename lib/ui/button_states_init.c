/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** button states init
*/

#include "uilib.h"

bt_state_t *fill_first_state(button_t *but, bt_state_t *states)
{
	states[0].fill_color = get_button_fill_color(but);
	states[0].outline_color = get_button_outline_color(but);
	states[0].text = get_text_string(but->text);
	states[0].action = but->action;
	states[0].params = but->params;
	return (states);
}

bt_state_t *init_bt_states(button_t *but, int nbstates)
{
	bt_state_t *sts = NULL;

	if (but == NULL || nbstates <= 0)
		return (NULL);
	nbstates++;
	but->nb_states = nbstates;
	sts = (bt_state_t*)malloc(sizeof(bt_state_t)*nbstates);
	if (sts == NULL)
		return (NULL);
	for (int i = 1; i < nbstates; i++) {
		sts[i].id = i;
		sts[i].fill_color = (sfColor){0, 0, 0, 0};
		sts[i].outline_color = (sfColor){0, 0, 0, 0};
		sts[i].text = NULL;
		sts[i].sprite_path = NULL;
		sts[i].action = NULL;
		sts[i].params = NULL;
	}
	return (fill_first_state(but, sts));
}
