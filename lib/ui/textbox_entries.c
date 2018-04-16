/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** textbox entries
*/

#include "uilib.h"

int	my_strlen(char *);

int	add_char_in_textbox(textbox_t *textbox, char *str, char c)
{
	if (c == -2)
		str[my_strlen(str)-1] = '\0';
	else
		str[my_strlen(str)] = (c >= 'A' && c <= 'Z') ? c + 32 : c;
	set_text_string(textbox->text, str);
	textbox->entry_state = NORMAL;
	return (0);
}

int	check_char_entry_and_add(textbox_t *textbox, char c)
{
	char *str = get_text_string(textbox->text);
	int width = get_textbox_size(textbox).x-8;
	int size = textbox->text->fontsize;

	if (size*(my_strlen(str)+1)/2 >= width && c != -2)
		return (0);
	if ((c < '0' || c > '9') && textbox->type == ONLY_NUM && c != -2)
		return (0);
	add_char_in_textbox(textbox, str, c);
	return (0);
}

int add_char_in_textboxes(list_t *textboxes, char c)
{
	textbox_t *textbox = NULL;
	list_t *tmp = textboxes;

	for (; tmp != NULL; tmp = tmp->next) {
		textbox = (textbox_t*)tmp->data;
		if (textbox->state == 1)
			check_char_entry_and_add(textbox, c);
	}
	return (0);
}
