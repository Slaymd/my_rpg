/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** button actions
*/

#include "uilib.h"

void set_button_action(button_t *button, void (*pf)(void*), void *params)
{
	button->action = pf;
	button->params = params;
}
