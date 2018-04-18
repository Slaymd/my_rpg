/*
** EPITECH PROJECT, 2018
** ListLib
** File description:
** linked list add
*/

#include "list.h"

int	list_add_withtag(list_t **list, void *data, char *tag)
{
	list_t *head = (list_t*)malloc(sizeof(list_t));

	head->data = data;
	head->next = *list;
	head->last = NULL;
	head->tag = tag;
	*list = head;
	if (head->next != NULL)
		head->last = head->next->last;
	return (0);
}

int	list_add(list_t **list, void *data)
{
	return (list_add_withtag(list, data, NULL));
}

int	list_append_withtag(list_t **list, void *data, char *tag)
{
	list_t *_tmp = *list;
	list_t *end = (list_t*)malloc(sizeof(list_t));

	end->data = data;
	end->next = NULL;
	end->last = NULL;
	end->tag = tag;
	if (_tmp == NULL) {
		*list = end;
		return (0);
	}
	_tmp->last = end;
	for (; _tmp != NULL; _tmp = _tmp->next) {
		if (_tmp->next == NULL) {
			_tmp->next = end;
			break;
		}
	}
	return (0);
}

int	list_append(list_t **list, void *data)
{
	return (list_append_withtag(list, data, NULL));
}
