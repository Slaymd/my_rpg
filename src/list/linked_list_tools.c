/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** linked list tools
*/

#include "../../include/linked_list.h"

int	add_to_linked_list(linked_list_t **list, void *data)
{
	linked_list_t *head = (linked_list_t*)malloc(sizeof(linked_list_t));

	head->data = data;
	head->next = *list;
	*list = head;
	return (0);
}
