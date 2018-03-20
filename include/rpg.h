/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** rpg header
*/

#ifndef __RPG_H__
#define __RPG_H__

#include <CSFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "map.h"

typedef struct linked_list_s linked_list_t;
typedef struct rpg_s rpg_t;

struct linked_list_s {
	void *data;
	linked_list_t *next;
}

struct rpg_s {
	map_t	*map;
}

#endif /* RPG_H_ */
