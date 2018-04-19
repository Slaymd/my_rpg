/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "../../include/rpg.h"

int rand_time(int min, int max)
{
	int nb = 0;

	srand(time(NULL));
	nb = rand() % (max - min) + min;
	return (nb);
}
