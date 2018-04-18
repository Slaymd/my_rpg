/*
** EPITECH PROJECT, 2018
** ListLib
** File description:
** list getter
*/

#include "list.h"

int	my_str_len(char *str)
{
	int len = 0;

	for (; str[len] != '\0'; len++);
	return (len);
}

int	my_str_eq_str(char *str1, char *str2)
{
	if (my_str_len(str1) != my_str_len(str2))
		return (0);
	for (int i = 0; str1[i] != '\0'; i++) {
		if (str1[i] != str2[i])
			return (0);
	}
	return (1);
}

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
		if (_tmp->tag != NULL && my_str_eq_str(tag, _tmp->tag))
			return (_tmp->data);
	}
	return (NULL);
}
