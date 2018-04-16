/*
** EPITECH PROJECT, 2018
** ListLib
** File description:
** list getter
*/

#include "list.h"

int	my_streqstr(char *str1, char *str2);

void *list_get_last(list_t *list)
{
	list_t *_tmp = list;

	if (list == NULL)
		return (NULL);
	if (list->last != NULL)
		return (list->last);
	for (; _tmp != NULL; _tmp = _tmp->next) {
		if (_tmp->next == NULL) {
			list->last = _tmp;
			return (_tmp);
		}
	}
	return (NULL);
}

void *list_get_fromtag(list_t *list, char *tag)
{
	list_t *_tmp = list;

	for (; _tmp != NULL; _tmp = _tmp->next) {
		if (_tmp->tag != NULL && my_streqstr(tag, _tmp->tag))
			return (_tmp->data);
	}
	return (NULL);
}
