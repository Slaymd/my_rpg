/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** text tools
*/

#include "my_uilib.h"

int	my_strlen_but_text(char *str)
{
	int len = 0;

	for (int i = 0; str[i] != '\0'; i++)
		len++;
	return (len);
}
