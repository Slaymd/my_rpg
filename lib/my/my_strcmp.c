/*
** EPITECH PROJECT, 2018
** task02
** File description:
** str cat
*/

#include <stdio.h>
#include <stdlib.h>

int my_strcmp(char *s1, char *s2)
{
	int i = 0;

	if (s1 == '\0' || s2 == '\0') {
		return (1);
	}
	for(; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] ; i++);
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (1);
}
