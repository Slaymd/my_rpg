/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** linkedlist header
*/

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdlib.h>

typedef struct linked_list_s linked_list_t;

struct linked_list_s {
	void *data;
	linked_list_t *next;
};

//Add
int	add_to_linked_list(linked_list_t **list, void *data);

#endif /* LINKED_LIST_H_ */
