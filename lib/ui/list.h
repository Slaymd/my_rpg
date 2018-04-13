/*
** EPITECH PROJECT, 2018
** ListLib
** File description:
** linkedlist header
*/

#ifndef __LIST_LIB_H__
#define __LIST_LIB_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct list_s list_t;
typedef struct intlist_s intlist_t;

struct list_s {
	char *tag;
	void *data;
	list_t *next;
	void *last;
};

struct intlist_s {
	int	value;
	intlist_t *next;
};

//Add
int	list_add(list_t **list, void *data);
int	intlist_add(intlist_t **list, int value);
int	list_add_withtag(list_t **list, void *data, char *tag);
int	list_append_withtag(list_t **list, void *data, char *tag);

//Append
int	list_append(list_t	**list, void *data);
int	intlist_append(intlist_t **list, int value);

//Contain
int	list_contain(list_t *list, void *data_to_check);

//Copy
list_t *list_copy(list_t *list);

//Getters
void *list_get_last(list_t *list);
void *list_get_fromtag(list_t *list, char *tag);

//Size
int	list_size(list_t *list);


#endif /* LIST_LIB_H_ */
